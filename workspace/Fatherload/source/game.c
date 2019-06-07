/*
 * game.c
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "game.h"

int player_x;
int player_y;
int screen_x;
int screen_y;
int flying;
int sell_mode, buy_mode;
bool gameOver;

int mineral_count = 0;

int fuel_price;
int drill_price;

Mineral *mineralMap;

dir orientation;

u16 *player_horizontal, *player_vertical, *player_vertical_static, *player_horizontal_static;

u16 *diamond_pic, *amazonite_pic, *bronze_pic, *alexxzandrite_pic;

bool moved;
bool start_pressed = false;
bool drilling = false;
int player_score = 0;
int score_changed = 0;

int player_diamonds = 0;
int player_amazonite = 0;
int player_bronze = 0;
int player_alexxzandrite = 0;
int player_drill_health;
int player_fuel;

soundEffectType nextSF;

void starting_game_screen(){
	// Starting screen
	showInitImage();
	u16 keys;
	while(1){
		swiWaitForVBlank();
		scanKeys();
		keys = keysDown();

		// any key clicked allows to go to the game
		if((keys & KEY_START)  || (keys & KEY_A)  || (keys & KEY_B) ||
		   (keys & KEY_R) 	   || (keys & KEY_L)  || (keys & KEY_TOUCH) ||
		   (keys & KEY_SELECT) || (keys & KEY_UP) || (keys & KEY_DOWN) ||
		   (keys & KEY_LEFT)   || (keys & KEY_RIGHT))
			break;
	}
}

int update_game(){
	moved = false;
	scanKeys();
	// Variable for movment keys
	u16 keys = keysHeld();
	// Variable for start, store and buy modes
	u16 keys2 = keysDown();

	// Drilling play
	if(keys2 & KEY_START && (!sell_mode) && (!buy_mode))
		player_pressed_start();

	// Store play
	if(((keys2 & KEY_L)) && (!start_pressed)){
		if(on_store_location() && !sell_mode){
			sell_mode = 1;
			buy_mode = 0;
			store_sub_display_sell();
			store_main_display();
			irqDisable(IRQ_TIMER0);
			irqDisable(IRQ_TIMER1);
		}
		// If we press again L in Sell mode it quits the store
		else {
			if(sell_mode){
				sell_mode = 0;
				game_sub_resume();
				release_pause_graphics();
				display_mineral(BRONZE);
				display_mineral(AMAZONITE);
				display_mineral(DIAMOND);
				display_mineral(ALEXXZANDRITE);
				score_display(20, 1, 9, player_score, 26);
				irqEnable(IRQ_TIMER0);
				irqEnable(IRQ_TIMER1);
			}
		}
	}

	if((keys2 & KEY_R) && (!start_pressed)){
		if(on_store_location() && !buy_mode){
			buy_mode = 1;
			sell_mode = 0;
			store_sub_display_buy();
			store_main_display();
			irqDisable(IRQ_TIMER0);
			irqDisable(IRQ_TIMER1);
		}
		// If we press again R in Buy mode it quits the store
		else{
			if(buy_mode){
				buy_mode = 0;
				game_sub_resume();
				release_pause_graphics();
				display_mineral(BRONZE);
				display_mineral(AMAZONITE);
				display_mineral(DIAMOND);
				display_mineral(ALEXXZANDRITE);
				score_display(20, 1, 9, player_score, 26);
				irqEnable(IRQ_TIMER0);
				irqEnable(IRQ_TIMER1);
			}
		}
	}

	if(sell_mode)
		store_sell(keys2);

	if(buy_mode)
		store_buy(keys2);
	// Moving play
	if (!start_pressed && !sell_mode && !buy_mode) {
		if(keys & KEY_A || keys & KEY_Y){
			player_drills();
		}

		else{
			if(keys & KEY_DOWN){
				player_move_down();
			}

			if(keys & KEY_RIGHT){
				player_move_right();
			}

			if(keys & KEY_LEFT){
				player_move_left();
			}

			if(keys & KEY_UP || keys & KEY_B){
				player_move_up();
			}

			if (keys & KEY_TOUCH){
				player_pressed_touchscreen();
			}
		}

		// move the background 3 => the main background
		REG_BG3HOFS = screen_x;
		REG_BG3VOFS = screen_y;
		// move the background 2 => the digged parts
		REG_BG2HOFS = screen_x;
		REG_BG2VOFS = screen_y;

		// update the player's movements
		update_vehicle();

		// Update the drilled path
		update_state();

		if(!flying)
			player_fall();

		oamUpdate(&oamMain);

		// Show the time since the game began
		updateChronoDisp(min, sec, msec, 11, 27, 0);

		// Stop the while if the player reaches the number of mineral generated
		if (mineral_count == N_TOT_MINERALS)
			return 0;

		if(player_fuel <= 0)
			return 0;
	}

	refreshMineralSprites();

	return 1;
}

void init_game() {
	Audio_Init();

	config_main_background();

	init_sub_background();

	orientation = DOWN;

	init_timers();

	configureSprites();

	player_bronze = 0;
	player_amazonite = 0;
	player_diamonds = 0;
	player_alexxzandrite = 0;
}

void start_game() {
	player_x = 128;
	player_y = 112;
	screen_x = 128;
	screen_y = 0;
	mineral_count = 0;
	player_score = 0;
	flying = 0;
	fuel_price = 100;
	drill_price = 200;

	// For tests, low fuel
	//player_fuel = 500;
	// For final version higher starting fuel stock
	player_fuel = 2500;

	// Not used for now, drill health
	player_drill_health = 500;

	Audio_PlayMusic();

	update_sprite(player_vertical_static, PLAYER_SPRITE_ID, 0, PLAYER_VSPAL, 1, 0,
			player_x, player_y);

	oamUpdate(&oamMain);

	// set the starting backgrounds
	init_main_bg();

	//set the objects coordinates
	initMinerals();

	gameOver = false;
	restart_timer();
	swiDelay(1000000);
	irqEnable(IRQ_TIMER0);
	irqEnable(IRQ_TIMER1);

	score_display(20, 5, 9, player_score, 26);
	display_mineral(BRONZE);
	display_mineral(AMAZONITE);
	display_mineral(DIAMOND);
	display_mineral(ALEXXZANDRITE);
}

bool hasBeenDrilled(int pos_x, int pos_y) {
	int position_y = pos_y + screen_y;
	int position_x = pos_x + screen_x;

	int base = (((position_y) > 255) ? 2 : 0) + (position_x) / 256;
	int x = ((position_x) % 256) / 8;
	int y = ((position_y) % 256) / 8;
	//printf("b: %d, x: %d, y: %d. %d\n",base, x, y, BG_MAP_RAM(base)[y * 32 + x]);
	if (BG_MAP_RAM(base)[y * 32 + x] == 1 || BG_MAP_RAM(base)[y * 32 + x] == 4)
		return true;
	else
		return false;
}

void player_move_right() {
	orientation = RIGHT;
	flying = 0;
	if (screen_x < 512 - 256 && !start_pressed) {
		if (hasBeenDrilled(player_x + 16, player_y) && hasBeenDrilled(player_x + 16, player_y + 10)) {
			screen_x++;
			if (player_x < 256 - 16)
				player_x++;
			player_fuel--;
		}
	}
	moved = true;
}

void player_move_left() {
	orientation = LEFT;
	flying = 0;

	if (screen_x > 0) {

		if (hasBeenDrilled(player_x - 1, player_y) && hasBeenDrilled(player_x - 1, player_y + 10)) {
			screen_x--;

			if (player_x > 0)
				player_x--;
			player_fuel--;
		}
	}
	moved = true;
}

void player_move_down() {
	orientation = DOWN;
	flying = 0;

	if (screen_y < 512 - 192) {

		if (hasBeenDrilled(player_x, player_y + 16) && hasBeenDrilled(player_x + 10, player_y + 16)) {
			screen_y++;

			if (player_y < 168)
				player_y++;
			player_fuel--;
		}
	}
	moved = true;
}

void player_move_up() {
	orientation = UP;
	// Equivalent to fly mode
	if (hasBeenDrilled(player_x  + 2, player_y - 2) && hasBeenDrilled(player_x + 10, player_y - 2)) {
		flying = 1;

		if (screen_y > 0) {
			screen_y--;
		}

		if (player_y > 90)
			player_y--;
		player_fuel -= 2;
	}
	moved = true;
}

void player_drills() {
	// Not -1 or +1, the size in pixels of the sprite is 16x 16, the beginning is on the top left so offset of
	// 16 for right and down, for up and left the offsets are needed because at the same time we create new blocks of drilled parts
	if(player_drill_health > 0){
		switch (orientation) {
		case RIGHT:
			if (screen_x < 512 - 256) {
				screen_x++;
				if (player_x < 256 - 16) {
					player_x++;
				}
				if(!(hasBeenDrilled(player_x + 16, player_y) && hasBeenDrilled(player_x + 16, player_y + 10)))
					player_drill_health--;
				player_fuel -= 2;
				drilling = true;
			}
			break;
		case LEFT:
			if (screen_x > 0) {
				screen_x--;
				if (player_x > 0) {
					player_x--;
				}
				if(!(hasBeenDrilled(player_x - 1, player_y) && hasBeenDrilled(player_x - 1, player_y + 10)))
					player_drill_health--;
				player_fuel -= 2;
				drilling = true;
			}
			break;
		case DOWN:
			if (screen_y < 512 - 192) {
				screen_y++;
				if (player_y < 168) {
					player_y++;
				}
				if(!(hasBeenDrilled(player_x, player_y + 16) && hasBeenDrilled(player_x + 10, player_y + 16)))
					player_drill_health--;
				player_fuel -= 2;
				drilling = true;
			}
			break;
		case UP:
			if (screen_y > 0) {
				screen_y--;
				if (player_y > 112) {
					player_y--;
				}
				flying = 1;
				if(!(hasBeenDrilled(player_x  + 2, player_y - 2) && hasBeenDrilled(player_x + 10, player_y - 2)))
					player_drill_health--;
				player_fuel -= 4;
				drilling = true;
			}
			break;
		}
	}
	moved = true;
}

void player_pressed_start() {
	if (!start_pressed) {
		irqDisable(IRQ_TIMER0);
		irqDisable(IRQ_TIMER1);
		mmPause();
		Audio_PlaySoundEX(SFX_TIRE_SCREECH);
		load_pause_graphics();
		start_pressed = 1;

		update_sprite(player_horizontal, PLAYER_SPRITE_ID, 1, PLAYER_VPAL, 0, 0,
				player_x, player_y);

		oamUpdate(&oamMain);
	}
	else{
		mmResume();

		if (orientation == DOWN || orientation == UP)
			update_sprite(player_vertical_static, PLAYER_SPRITE_ID, 0, PLAYER_VPAL, 0,
					((orientation == DOWN) ? 1 : 0), player_x, player_y);
		else
			update_sprite(player_horizontal_static, PLAYER_SPRITE_ID, 0, PLAYER_VPAL,
					((orientation == LEFT) ? 1 : 0), 0, player_x, player_y);

		oamUpdate(&oamMain);
		release_pause_graphics();
		start_pressed = 0;
		irqEnable(IRQ_TIMER0);
		irqEnable(IRQ_TIMER1);
	}
}

void player_pressed_touchscreen() {
	touchPosition touch;
	touchRead(&touch);
	// UP
	if (((touch.py >= 0) && (touch.py < 50)) && (touch.px >= 45) && (touch.px <= 85)) {
		player_move_up();
	}
	// DOWN
	if (((touch.py >= 75) && (touch.py <= 128)) && (touch.px >= 45) && (touch.px <= 85)) {
		player_move_down();
	}
	// LEFT
	if (((touch.py >= 30) && (touch.py < 90)) && (touch.px >= 2) && (touch.px <= 37)) {
		player_move_left();
	}
	// RIGHT
	if (((touch.py >= 30) && (touch.py < 90)) && (touch.px >= 90) && (touch.px <= 128)) {
		player_move_right();
	}
}

void update_vehicle() {
	switch (orientation) {
	case RIGHT:
	case LEFT:
		update_sprite((moved)?player_horizontal:player_horizontal_static, PLAYER_SPRITE_ID, 0,
				PLAYER_HPAL, (orientation==LEFT)?1:0, 0, player_x, player_y);
		break;
	case DOWN:
	case UP:
		update_sprite((moved)?player_vertical:player_vertical_static, PLAYER_SPRITE_ID, 0,
				PLAYER_VPAL, 0, (orientation==DOWN)?1:0, player_x, player_y);
		break;
	}
}

void addToInventory(mineralType mineral) {
	switch (mineral) {
		case DIAMOND:
			player_diamonds++;
			break;
		case AMAZONITE:
			player_amazonite++;
			break;
		case BRONZE:
			player_bronze++;
			break;
		case ALEXXZANDRITE:
			player_alexxzandrite++;
			break;
		default:
			break;
	}
}

void sellItemFromInventory(mineralType mineral) {
	switch (mineral) {
	case DIAMOND:
		if (player_diamonds > 0) {
			player_diamonds--;
			updateScore(SCORE_DIAMONDS);
		}
		break;
	case AMAZONITE:
		if (player_amazonite > 0) {
			player_amazonite--;
			updateScore(SCORE_AMAZONITE);
		}
		break;
	case BRONZE:
		if (player_bronze > 0) {
			player_bronze--;
			updateScore(SCORE_BRONZE);
		}
		break;
	case ALEXXZANDRITE:
		if (player_alexxzandrite > 0) {
			player_alexxzandrite--;
			updateScore(SCORE_ALEXXZANDRITE);
		}
		break;
	default:
		break;
	}

	score_display(10, 1, 9, player_score, 26);
	display_mineral(mineral);
}

void addToAudioEffectQueue(soundEffectType sf){
	switch (sf){
	case COIN:
		nextSF = COIN;
		break;
	case DRILL:
		if (nextSF == NONE)
			nextSF = DRILL;
		break;
	default:
		break;
	}
}

void update_state() {
	int position_y = player_y + screen_y + ((orientation == LEFT || orientation == RIGHT)?2:0);
	int position_x = player_x + screen_x + ((orientation == DOWN || orientation == UP)?2:0);

	if (position_y > 112 + 15) {
		int base = (((position_y) > 255) ? 2 : 0) + (position_x) / 256;
		int x = ((position_x) % 256) / 8;
		int y = ((position_y) % 256) / 8;
		drilling_path(base, x, y);
	}

	if (drilling) {
		mineralType mineral = drillMineralReturnValue(position_x, position_y);
		if (mineral != DIRT) {
			addToInventory(mineral);
			//{DIRT, DRILLED, DIAMOND, AMAZONITE, BRONZE, ALEXXZANDRITE}
			// Drill damaged by the mineral
			switch(mineral){
			case BRONZE:
				player_drill_health--;
				break;
			case AMAZONITE:
				player_drill_health -= 2;
				break;
			case DIAMOND:
				player_drill_health -= 3;
				break;
			case ALEXXZANDRITE:
				player_drill_health -= 4;
				break;
			default:
				break;
			}
			display_mineral(mineral);
			addToAudioEffectQueue(COIN);
		}

		else {
			addToAudioEffectQueue(DRILL);
		}
	}
	drilling = false;
	oamUpdate(&oamMain);
}



void player_fall() {
	if (hasBeenDrilled(player_x + 2, player_y + 16) && hasBeenDrilled(
			player_x + 8, player_y + 16)) {
		if (screen_y < 512 - 192)
			screen_y++;
		if (player_y < 168)
			player_y++;
	}
}

int gameOverState(){

	if(max_score < player_score){
		max_score = player_score;
		writeMaxScore(max_score);
	}

	player_fuel = 0;
	print_fuel(20, 10, 8);

	// restart part
	free(mineralMap);
	hide_all_minerals();

	gameOver = true;
	overSec = 0;
	irqDisable(IRQ_TIMER1);
	mmPause();
	Audio_PlaySoundEX(SFX_TIRE_SCREECH);

	update_sprite(player_horizontal, PLAYER_SPRITE_ID, 1, PLAYER_VPAL, 0, 0, player_x, player_y);

	oamUpdate(&oamMain);

	restart_display();

	u16 keys = 0;
	while(1){
		swiWaitForVBlank();
		scanKeys();

		keys = keysDown();

		if(keys & KEY_Y){
			return 1;

		}

		if (keys & KEY_X) {
			return 0;
		}

		if (keys & KEY_TOUCH) {
			touchPosition touch;
			touchRead(&touch);
			if(touch.py >= 10 && touch.py <= 90){
				// "Yes" button pressed
				if(touch.px >= 22 && touch.px <= 115)
					return 1;
				// "No" button pressed
				if(touch.px >= 146 && touch.px <= 240)
					return 0;
			}
		}
		// If wait more than 60 seconds, quit
		if(overSec >= 60)
			return 0;
	}
}

int on_store_location(){
	return ( (player_x + screen_x > 415) && (player_x + screen_x < 495) &&
			 (player_y + screen_y > 60) && (player_y + screen_y < 120) ) ? 1:0;
}

void store_sell(u16 keys){
	if((keys & KEY_A)){
		if(player_bronze > 0)
			sellItemFromInventory(BRONZE);
	}
	if((keys & KEY_B)){
		if(player_amazonite > 0)
			sellItemFromInventory(AMAZONITE);
	}
	if((keys & KEY_Y)){
		if(player_diamonds > 0)
			sellItemFromInventory(DIAMOND);
	}
	if((keys & KEY_X)){
		if(player_alexxzandrite > 0)
			sellItemFromInventory(ALEXXZANDRITE);
	}

	// TODO: add touchscreen
}

void store_buy(u16 keys){
	// Buying gas
	if((keys & KEY_A) && (player_score >= fuel_price)){
		updateScore(-(fuel_price));
		player_fuel += FUEL_RECHARGE;
		// TODO: increase gas price
	}
	if((keys & KEY_B) && (player_score >= drill_price)){
		updateScore(-(drill_price));
		player_drill_health += DRILL_HEAL;
	}

	// TODO: add touchscreen

	score_display(10, 1, 9, player_score, 26);
}
