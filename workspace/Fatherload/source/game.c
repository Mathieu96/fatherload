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

Objects_coord *mineral;

dir orientation;

u16 *gfx_horizontal, *gfx_vertical, *diamond_pic, *amazonite_pic, *bronze_pic, *alexxzandrite_pic;

int start_pressed = 0;
int score_player = 0;
int score_changed = 0;

void init_game() {
	mineral = (Objects_coord *) malloc(N_TOT_MINERALS * sizeof(Objects_coord));

	Audio_Init();
	Audio_PlayMusic();

	config_main_background();
	//	consoleDemoInit();
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
	score_player = 0;

	update_sprite(gfx_horizontal, PLAYER_SPRITE_ID, 0,
				  PLAYER_VPAL, 0, 0,
				  player_x, player_y);
/*	oamSet(&oamMain, 			// oam handler
			PLAYER_SPRITE_ID, 	// Number of sprite
			player_x, player_y, // Coordinates
			0, 					// Priority
			0, 					// Palette to use
			SpriteSize_16x16, 	// Sprite size
			SpriteColorFormat_16Color, // Color format
			gfx_horizontal,	 	// Loaded graphic to display
			-1, 				// Affine rotation to use (-1 none)
			false, 				// Double size if rotating
			false, 				// Hide this sprite
			false, false,		// Horizontal or vertical flip
			false 				// Mosaic
	);*/
	oamUpdate(&oamMain);
	// set the starting backgrounds
	init_main_bg();

	//set the objects coordinates
	initMinerals();
	irqEnable(IRQ_TIMER0);
	score_update();
}

void player_move_right() {
	if (screen_x < 512 - 256 && !start_pressed) {
		Audio_PlaySoundEX(SFX_BULLDOZER);
		orientation = RIGHT;
		screen_x++;
		if (player_x < 256 - 16)
			player_x++;
	}
}

void player_move_left() {
	if (screen_x > 0 && !start_pressed) {
		Audio_PlaySoundEX(SFX_BULLDOZER);
		orientation = LEFT;
		screen_x--;
		if (player_x > 0)
			player_x--;
	}
}

void player_move_down() {
	if (screen_y < 512 - 192 && !start_pressed) {
		Audio_PlaySoundEX(SFX_BULLDOZER);
		orientation = DOWN;
		screen_y++;
		if (player_y < 168)
			player_y++;
	}
}

void player_move_up() {
	if (screen_y > 0 && !start_pressed) {
		Audio_PlaySoundEX(SFX_BULLDOZER);
		orientation = UP;
		screen_y--;
		if (player_y > 112)
			player_y--;
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
/*		oamSet(&oamMain,			// oam handler
				PLAYER_SPRITE_ID, 	// Number of sprite
				player_x, player_y, // Coordinates
				0, 					// Priority
				0, 					// Palette to use
				SpriteSize_16x16, 	// Sprite size
				SpriteColorFormat_16Color, // Color format
				gfx_horizontal, 	// Loaded graphic to display
				-1, 				// Affine rotation to use (-1 none)
				false, 				// Double size if rotating
				true, 				// Hide this sprite
				false, false,		// Horizontal or vertical flip
				false 				// Mosaic
		);*/
		oamUpdate(&oamMain);
		swiDelay(11000000); // Delay to avoid going back out of start mode right after
	} else {
		mmResume();
		update_sprite(gfx_horizontal, PLAYER_SPRITE_ID, 0,
					  PLAYER_HPAL, 0, 0,
					  player_x, player_y);
/*		oamSet(&oamMain, 			// oam handler
				PLAYER_SPRITE_ID, 	// Number of sprite
				player_x, player_y, // Coordinates
				0, 					// Priority
				0, 					// Palette to use
				SpriteSize_16x16, 	// Sprite size
				SpriteColorFormat_16Color, // Color format
				gfx_horizontal, 	// Loaded graphic to display
				-1, 				// Affine rotation to use (-1 none)
				false, 				// Double size if rotating
				false, 				// Hide this sprite
				false, false, 		// Horizontal or vertical flip
				false 				// Mosaic
		);*/
		oamUpdate(&oamMain);
		release_start_display();
		start_pressed = 0;
		swiDelay(11000000); // Delay to avoid going back into start mode right after
		irqEnable(IRQ_TIMER0);
	}
}

void player_pressed_touchscreen() {
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

void update_game() {
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


void update_state(){
	int position_y = player_y + screen_y;
	int position_x = player_x + screen_x;

	if(position_y > 112 + 15){
		int base = (((position_y)>255)?2:0) + (position_x)/256;
		int x = ((position_x)%256)/8;
		int y = ((position_y)%256)/8;
		display_drilled_path(base, x, y);
	}
	check_alexxzandrite(position_x, position_y);
	check_amazonite(position_x, position_y);
	check_diamond(position_x, position_y);
	check_bronze(position_x, position_y);
	oamUpdate(&oamMain);
}

void check_diamond(int position_x, int position_y){
	int i;
	for(i = 0; i < N_DIAMOND; i++){
		if(!mineral[i].isDrilled && (
		   (((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) // abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			if(score_player < 999999){
				score_player += SCORE_DIAMONDS;
				if(score_player > 999999)
					score_player = 999999;
				score_changed = 1;
			}
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isDrilled = true;
			update_sprite(diamond_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, DIAMOND_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}

		if(((mineral[i].x > - 16) 		   && (mineral[i].x < screen_x + 256)) &&
		   ((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){
			update_sprite(diamond_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, DIAMOND_PAL,0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
}

void check_amazonite(int position_x, int position_y){
	int i;
	for(i = N_DIAMOND; i < N_DIAMOND + N_AMAZONITE; i++){
		if(!mineral[i].isDrilled && (
		(((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) //abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			if(score_player < 999999){
				score_player += SCORE_AMAZONITE;
				if(score_player > 999999)
					score_player = 999999;
				score_changed = 1;
			}
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isDrilled = true;
			//update_sprite(u16* gfx, int spriteID, int hide, int paletteNum, int x, int y)
			update_sprite(amazonite_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, AMAZONITE_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}

		if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
				((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){

			update_sprite(amazonite_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, AMAZONITE_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
}

void check_bronze(int position_x, int position_y){
	int i;
	for(i = N_DIAMOND + N_AMAZONITE; i < N_DIAMOND + N_AMAZONITE + N_BRONZE; i++){
		if(!mineral[i].isDrilled && (
		(((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) //abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			if(score_player < 999999){
				score_player += SCORE_BRONZE;
				if(score_player > 999999)
					score_player = 999999;
				score_changed = 1;
			}
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isDrilled = true;

			update_sprite(bronze_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, BRONZE_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);

		}

		if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
				((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){

			update_sprite(bronze_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, BRONZE_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
}

void check_alexxzandrite(int position_x, int position_y){
	int i;
	for(i = N_DIAMOND + N_AMAZONITE + N_BRONZE;
		i < N_DIAMOND + N_AMAZONITE + N_BRONZE + N_ALEXXZANDRITE; i++){
		if(!mineral[i].isDrilled && (
		(((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) //abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			if(score_player < 999999){
				score_player += SCORE_ALEXANDRITE;
				if(score_player > 999999)
					score_player = 999999;
				score_changed = 1;
			}
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isDrilled = true;

			update_sprite(alexxzandrite_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, ALEXX_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}

		if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
				((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){

			update_sprite(alexxzandrite_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, ALEXX_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
}
