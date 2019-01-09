/*
 * graphics_main.c
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "game.h"

int player_x;
int player_y;
int screen_x;
int screen_y;

int mineral_count = 0;

Mineral *mineralMap;

dir orientation;

u16 *gfx_horizontal, *gfx_vertical, *diamond_pic, *amazonite_pic, *bronze_pic, *alexxzandrite_pic;

bool start_pressed = false;
bool drilling = false;
int player_score = 0;
int score_changed = 0;

int player_diamonds = 0;
int player_amazonite = 0;
int player_bronze = 0;
int player_alexxzandrite = 0;
//TODO: Find reasonnable values for these:
int player_drill_health = 50;
int player_fuel = 100;

void init_game() {
	mineralMap = (Mineral *) malloc(N_TOT_MINERALS * sizeof(Mineral));

	Audio_Init();
	Audio_PlayMusic();

	config_main_background();
	//consoleDemoInit();
	init_sub_background();

	orientation = RIGHT;


	TIMER_DATA(0) = TIMER_FREQ(100);
	TIMER0_CR = TIMER_ENABLE | TIMER_DIV_64 | TIMER_IRQ_REQ;
	irqSet(IRQ_TIMER0, timer0_ISR);

	configureSprites();
}

void start_game() {
	player_x = 128;
	player_y = 112;
	screen_x = 128;
	screen_y = 0;
	mineral_count = 0;
	player_score = 0;

	update_sprite(gfx_horizontal, PLAYER_SPRITE_ID, 0,
				  PLAYER_VPAL, 0, 0,
				  player_x, player_y);

	oamUpdate(&oamMain);
	// set the starting backgrounds
	init_main_bg();

	//set the objects coordinates
	initMinerals();
	irqEnable(IRQ_TIMER0);

	score_display(16, 1, 10, player_score);
}

bool hasBeenDrilled(int pos_x, int pos_y, bool answer) {
	//TODO: Mathieu, can you implement this?
	// last argument only for debugging purposes, should be removed when implemented properly
	// Possibly re-use it with display_drilled_path if applicable
	int position_y = pos_y + screen_y;
	int position_x = pos_x + screen_x;

	int base = (((position_y)>255)?2:0) + (position_x)/256;
	int x = ((position_x)%256)/8;
	int y = ((position_y)%256)/8;
	printf("base: %d,%d,%d: %d\n",base,x,y,BG_MAP_RAM(base)[y*32+x]);
	if(BG_MAP_RAM(base)[y * 32 + x] == 1 ||
			BG_MAP_RAM(base)[y * 32 + x] == 4)
		return true;
	else
		return false;
}

void player_move_right() {
	orientation = RIGHT;
	if (screen_x < 512 - 256 && !start_pressed) {
		if(hasBeenDrilled(player_x + 16, player_y, true)) {
			screen_x++;
			if (player_x < 256 - 16)
				player_x++;
			player_fuel--;
		}
	}
}

void player_move_left() {
	orientation = LEFT;
	if (screen_x > 0 && !start_pressed) {
		if(hasBeenDrilled(player_x - 1, player_y, true)) {
			screen_x--;
			if (player_x > 0)
				player_x--;
			player_fuel--;
		}
	}
}

void player_move_down() {
	orientation = DOWN;
	if (screen_y < 512 - 192 && !start_pressed) {
		if(hasBeenDrilled(player_x, player_y + 16, true)) {
			screen_y++;
			if (player_y < 168)
				player_y++;
			player_fuel--;
		}
	}
}

void player_move_up() {
	orientation = UP;
	if (screen_y > 0 && !start_pressed) {
		if(hasBeenDrilled(player_x, player_y - 1, true)){
			screen_y--;
			if (player_y > 112)
				player_y--;
			player_fuel--;
		}
	}
}

void player_drills() {
	// Not -1 or +1, the size in pixels of the sprite is 16x 16, the beginning is on the top left so offset of
	// 16 for right and down, for up and left the offsets are needed because at the same time we create new blocks of drilled parts
	switch (orientation) {
	case RIGHT:
		if (screen_x < 512 - 256 && !start_pressed && !hasBeenDrilled(player_x + 16, player_y, false)) {
			Audio_PlaySoundEX(SFX_BULLDOZER);
			screen_x++;
			if (player_x < 256 - 16){
				player_x++;
			}
			player_drill_health--;
			drilling = true;
		}
		break;
	case LEFT:
		if (screen_x > 0 && !start_pressed && !hasBeenDrilled(player_x - 8, player_y, false)) {
			Audio_PlaySoundEX(SFX_BULLDOZER);
			screen_x--;
			if (player_x > 0) {
				player_x--;
			}
			player_drill_health--;
			drilling = true;
		}
		break;
	case DOWN:
		if (screen_y < 512 - 192 && !start_pressed && !hasBeenDrilled(player_x, player_y + 16, false)) {
			Audio_PlaySoundEX(SFX_BULLDOZER);
			screen_y++;
			if (player_y < 168){
				player_y++;
			}
			player_drill_health--;
			drilling = true;
		}
		break;
		case UP:
			if (screen_y > 0 && !start_pressed && !hasBeenDrilled(player_x, player_y - 8, false)) {
				Audio_PlaySoundEX(SFX_BULLDOZER);
				screen_y--;
				if (player_y > 112){
					player_y--;
				}
				player_drill_health--;
				drilling = true;
			}
			break;
	}
}

void player_pressed_start() {
	if (!start_pressed) {
		irqDisable(IRQ_TIMER0);
		mmPause();
		Audio_PlaySoundEX(SFX_TIRE_SCREECH);
		load_start_display();
		start_pressed = 1;

		update_sprite(gfx_horizontal, PLAYER_SPRITE_ID, 1,
					  PLAYER_VPAL, 0, 0,
					  player_x, player_y);

		oamUpdate(&oamMain);
		//TODO: change to key released?
		swiDelay(11000000); // Delay to avoid going back out of start mode right after
	} else {
		mmResume();

		update_sprite(gfx_horizontal, PLAYER_SPRITE_ID, 0,
					  PLAYER_HPAL, 0, 0,
					  player_x, player_y);

		oamUpdate(&oamMain);
		release_start_display();
		start_pressed = 0;
		swiDelay(11000000); // Delay to avoid going back into start mode right after
		irqEnable(IRQ_TIMER0);
	}
}

void player_pressed_touchscreen() {
	//TODO: update to new movement/drilling scheme
	touchPosition touch;
	touchRead(&touch);
	if (((touch.py >= 0) && (touch.py < 50)) && (touch.px >= 45) && (touch.px <= 85)) {
		if (screen_y > 0) {
			Audio_PlaySoundEX(SFX_BULLDOZER);
			orientation = UP;
			screen_y -= 3;
			if (player_y > 112)
				player_y--;
		}
	}
	if (((touch.py >= 75) && (touch.py <= 128)) && (touch.px >= 45)
			&& (touch.px <= 85)) {
		if (screen_y < 512 - 192) {
			Audio_PlaySoundEX(SFX_BULLDOZER);
			orientation = DOWN;
			screen_y += 3;
			if (player_y < 168)
				player_y++;
		}
	}
	if (((touch.py >= 30) && (touch.py < 90)) && (touch.px >= 2) && (touch.px <= 37)) {
		if (screen_x > 0) {
			Audio_PlaySoundEX(SFX_BULLDOZER);
			orientation = LEFT;
			screen_x--;
			if (player_x > 0)
				player_x--;
		}
	}
	if (((touch.py >= 30) && (touch.py < 90)) && (touch.px >= 90) && (touch.px <= 128)) {
		if (screen_x < 512 - 256) {
			Audio_PlaySoundEX(SFX_BULLDOZER);
			orientation = RIGHT;
			screen_x++;
			if (player_x < 256 - 16)
				player_x++;
		}
	}
}

void update_vehicle() {
	switch (orientation) {
	case RIGHT:
		update_sprite(gfx_horizontal, PLAYER_SPRITE_ID, 0,
					  PLAYER_HPAL, 0, 0,
					  player_x, player_y);
		break;
	case LEFT:
		update_sprite(gfx_horizontal, PLAYER_SPRITE_ID, 0,
					  PLAYER_HPAL, 1, 0,
					  player_x, player_y);
		break;
	case UP:
		update_sprite(gfx_vertical, PLAYER_SPRITE_ID, 0,
					  PLAYER_VPAL, 0, 0,
					  player_x, player_y);
		break;
	case DOWN:
		update_sprite(gfx_vertical, PLAYER_SPRITE_ID, 0,
					  PLAYER_VPAL, 0, 1,
					  player_x, player_y);
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
		if (player_diamonds > 0){
			player_diamonds--;
			updateScore(SCORE_DIAMONDS);
		}
		break;
	case AMAZONITE:
		if (player_amazonite > 0){
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
			updateScore(SCORE_ALEXANDRITE);
		}
		break;
	default:
		break;
	}
	if(mineral != DIRT)
		score_changed = 1;
}

void update_state(){
	int position_y = player_y + screen_y;
	int position_x = player_x + screen_x;

	if(position_y > 112 + 15){
		int base = (((position_y)>255)?2:0) + (position_x)/256;
		int x = ((position_x)%256)/8;
		int y = ((position_y)%256)/8;
		drilling_path(base, x, y);
	}
	if (drilling) {
		mineralType mineral = drillMineralReturnValue(position_x, position_y);
		if (mineral != DIRT){
			addToInventory(mineral);
			//TODO: Fix when store is implemented, just sell right away for now
			sellItemFromInventory(mineral);
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
		} else {
			Audio_PlaySoundEX(SFX_BULLDOZER);
		}

	}
	drilling = false;
	oamUpdate(&oamMain);
}
