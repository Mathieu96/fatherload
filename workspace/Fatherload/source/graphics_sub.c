/*
 * graphics_sub.c
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "graphics_sub.h"

u8 emptyTile2[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0
};

void init_sub_background() {
	REG_DISPCNT_SUB = MODE_3_2D | DISPLAY_BG1_ACTIVE | DISPLAY_BG2_ACTIVE | DISPLAY_BG3_ACTIVE;

	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	// Init BG1
	BGCTRL_SUB[1] = BG_TILE_BASE(3) | BG_MAP_BASE(26) | BG_COLOR_16 | BG_32x32;

	// Init BG2
	BGCTRL_SUB[2] = BG_TILE_BASE(3) | BG_MAP_BASE(27) | BG_COLOR_16 | BG_32x32;

	// Init BG3
	//BGCTRL_SUB[3] = BG_MAP_BASE(0) | BG_BMP8_128x128;
	BGCTRL_SUB[3] = BG_MAP_BASE(0) | BG_BMP8_256x256;

	dmaCopy(controlsPal, BG_PALETTE_SUB, controlsPalLen);
	dmaCopy(controlsBitmap, BG_MAP_RAM_SUB(0), controlsBitmapLen);

	dmaCopy(numbers_smallTiles, BG_TILE_RAM_SUB(3), numbers_smallTilesLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[9*16],  numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[10*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[11*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[12*16], numbers_smallPalLen);

	BG_PALETTE_SUB[145] = ARGB16(1,0,31,0);
	BG_PALETTE_SUB[161] = ARGB16(1,31,0,0);
	BG_PALETTE_SUB[177] = ARGB16(1,0,0,31);

	int i, j;
	// initialize all the tiles of BG2 & BG1 to transparent, to avoid overlapping the background 3
	for (i = 0; i < 32; i++) {
		for (j = 0; j < 32; j++) {
			BG_MAP_RAM_SUB(26)[i * 32 + j] = 0 | TILE_PALETTE(9);
		}
	}

	for (i = 0; i < 32; i++) {
		for (j = 0; j < 32; j++) {
			BG_MAP_RAM_SUB(27)[i * 32 + j] = 0 | TILE_PALETTE(11);
		}
	}

	// Set up affine matrix
	REG_BG3PA_SUB = 256;
	REG_BG3PC_SUB = 0;
	REG_BG3PB_SUB = 0;
	REG_BG3PD_SUB = 256;
}

void printDigit(int number, int x, int y, int pal, int base) {
	int i, j;

	if (number >= 0 && number < 10)
		for (i = 0; i < 4; i++)
			for (j = 0; j < 2; j++)
				if (number >= 0)
					BG_MAP_RAM_SUB(base)[(i + y) * 32 + j + x] = ((u16) (i * 2 + j + 2) + 8 * number) | TILE_PALETTE(pal);
}

void updateChronoDisp(int min, int sec, int msec, int pal, int base, int isGameOver) {
	int i, j;
	int x, y;
	if(!isGameOver){
		x = 14;
		y = 14;
	}
	else{
		x = 1;
		y = 20;
	}
	printDigit((int) min / 10, x, y, pal, base); x += 2;
	printDigit((int) min % 10, x, y, pal, base); x += 2;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			BG_MAP_RAM_SUB(base)[(i + y) * 32 + j + x] = ((u16) (i * 2 + j + 2) + 8 * 10) | TILE_PALETTE(pal);
		}
	}
	x += 2;
	printDigit((int) sec / 10, x, y, pal, base); x += 2;
	printDigit((int) sec % 10, x, y, pal, base); x += 2;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			BG_MAP_RAM_SUB(base)[(i + y+2) * 32 + j + x] = ((u16) (i * 2 + j + 8) + 8 * 10) | TILE_PALETTE(pal);
		}
	}
	x++;
	printDigit((int) msec / 100, x, y, pal, base); x += 2;
	printDigit((int) (msec % 100) / 10, x, y, pal, base); x += 2;
	printDigit((int) msec % 10, x, y, pal, base);
}

void score_display(int x, int y, int pal, int score, int base){
	int i;
	int temp = score;
	for (i = 10000; i > 0; i /= 10) {
		x += 2;
		printDigit(temp / i, x, y, pal, base);
		temp = temp % i;
	}
}

void sell_price_display(int x, int y, int pal, int score, int base){
	int i;
	int temp = score;
	for (i = 1000; i > 0; i /= 10) {
		x += 2;
		printDigit(temp / i, x, y, pal, base);
		temp = temp % i;
	}
}

void print_fuel(int x, int y, int pal){
	int i;
	int temp = player_fuel;
	for(i = 10000; i > 0; i /= 10){
		x += 2;
		printDigit(temp / i, x, y, pal, 26);
		temp = temp % i;
	}
}

void print_drill_health(int x, int y, int pal){
	int i;
	int temp = player_drill_health;
	for(i = 10000; i > 0; i /= 10){
		x += 2;
		printDigit(temp / i, x, y, pal, 26);
		temp = temp % i;
	}
}

void print_mineral(int x, int y, int value, int pal){
	int i;
	for(i = 10; i > 0; i /= 10){
		printDigit(value / i, x, y, pal, 26);
		x += 2;
		value = value % i;
	}
}

void display_mineral(mineralType mineral){
	switch(mineral){
	case BRONZE:
		print_mineral((sell_mode == 0) ? 4:7, (sell_mode == 0) ? 19:7, player_bronze,
					  (sell_mode == 0) ? 12:((player_bronze > 0) ? 9:10));
		break;

	case AMAZONITE:
		print_mineral((sell_mode == 0) ? 11:7, (sell_mode == 0) ? 19:16, player_amazonite,
					  (sell_mode == 0) ? 12:((player_amazonite > 0) ? 9:10));
		break;

	case DIAMOND:
		print_mineral((sell_mode == 0) ? 18:21, (sell_mode == 0) ? 19:7, player_diamonds,
					  (sell_mode == 0) ? 12:((player_diamonds > 0) ? 9:10));
		break;

	case ALEXXZANDRITE:
		print_mineral((sell_mode == 0) ? 27:21, (sell_mode == 0) ? 19:16, player_alexxzandrite,
					  (sell_mode == 0) ? 12:((player_alexxzandrite > 0) ? 9:10));
		break;

	default:
		break;
	}
}
void GameOver_sub_display(){
	REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE;
	BGCTRL_SUB[0] = BG_COLOR_16 | BG_MAP_BASE(1) | BG_TILE_BASE(2) | BG_32x32;
	BGCTRL_SUB[1] = BG_COLOR_16 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32;

	dmaCopy(game_over_subTiles, BG_TILE_RAM_SUB(1), game_over_subTilesLen);
	dmaCopy(game_over_subMap,   BG_MAP_RAM_SUB(0),  game_over_subMapLen);
	dmaCopy(game_over_subPal,   BG_PALETTE_SUB,     game_over_subPalLen);

	dmaCopy(numbers_smallTiles, BG_TILE_RAM_SUB(2), numbers_smallTilesLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[1*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[2*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[3*16], numbers_smallPalLen);

	BG_PALETTE_SUB[17] = ARGB16(1,31,0,0);
	BG_PALETTE_SUB[33] = ARGB16(1,0,31,0);
	BG_PALETTE_SUB[49] = ARGB16(1,31,31,31);

	int i,j;

	for (i = 0; i < 32; i++) {
		for (j = 0; j < 32; j++) {
			BG_MAP_RAM_SUB(1)[i * 32 + j] = 0 | TILE_PALETTE(1);
		}
	}

	// High score display
	score_display(20, 16, 1, max_score, 1);

	// Score display
	score_display(20, 20, 2, player_score, 1);

	// Finish chrono
	updateChronoDisp(min, sec, msec, 3, 1, 1);
}

void starting_sub_display(){
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
	REG_DISPCNT_SUB = MODE_3_2D | DISPLAY_BG0_ACTIVE;

	BGCTRL_SUB[0] = BG_TILE_BASE(1) | BG_MAP_BASE(0) | BG_COLOR_256 | BG_32x32;

	dmaCopy(press_to_beginTiles, BG_TILE_RAM_SUB(1), press_to_beginTilesLen);
	dmaCopy(press_to_beginMap,   BG_MAP_RAM_SUB(0),  press_to_beginMapLen);
	dmaCopy(press_to_beginPal,   BG_PALETTE_SUB,     press_to_beginPalLen);
}

void game_sub_resume(){
	// Resumes the game state after getting in the shop
	dmaCopy(controlsPal, BG_PALETTE_SUB, controlsPalLen);
	dmaCopy(controlsBitmap, BG_MAP_RAM_SUB(0), controlsBitmapLen);
	dmaCopy(numbers_smallTiles, BG_TILE_RAM_SUB(3), numbers_smallTilesLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[9*16],  numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[10*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[11*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[12*16], numbers_smallPalLen);

	BG_PALETTE_SUB[145] = ARGB16(1,0,31,0);
	BG_PALETTE_SUB[161] = ARGB16(1,31,0,0);
	BG_PALETTE_SUB[177] = ARGB16(1,0,0,31);
}

void store_sub_display_sell(){
	dmaCopy(store_sub_display_sellPal, BG_PALETTE_SUB, store_sub_display_sellPalLen);
	dmaCopy(store_sub_display_sellBitmap, BG_MAP_RAM_SUB(0), store_sub_display_sellBitmapLen);

	dmaCopy(numbers_smallTiles, BG_TILE_RAM_SUB(3), numbers_smallTilesLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[9*16],  numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[10*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[11*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[12*16], numbers_smallPalLen);

	BG_PALETTE_SUB[145] = ARGB16(1,0,31,0);
	BG_PALETTE_SUB[161] = ARGB16(1,31,0,0);
	BG_PALETTE_SUB[177] = ARGB16(1,0,0,31);

	hide_all_minerals();

	update_sprite(player_horizontal, PLAYER_SPRITE_ID, 1, PLAYER_VPAL, 0, 0,
			player_x, player_y);

	display_mineral(BRONZE);
	display_mineral(AMAZONITE);
	display_mineral(DIAMOND);
	display_mineral(ALEXXZANDRITE);
	score_display(10, 1, 12, player_score, 26);

	sell_price_display(4, 11, 12, SCORE_BRONZE, 26);
	sell_price_display(4, 20, 12, SCORE_AMAZONITE, 26);
	sell_price_display(18, 11, 12, SCORE_DIAMONDS, 26);
	sell_price_display(18, 20, 12, SCORE_ALEXXZANDRITE, 26);

	oamUpdate(&oamMain);
}

void store_sub_display_buy(){
	dmaCopy(store_sub_display_buyPal, BG_PALETTE_SUB, store_sub_display_buyPalLen);
	dmaCopy(store_sub_display_buyBitmap, BG_MAP_RAM_SUB(0), store_sub_display_buyBitmapLen);

	dmaCopy(numbers_smallTiles, BG_TILE_RAM_SUB(3), numbers_smallTilesLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[9*16],  numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[10*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[11*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[12*16], numbers_smallPalLen);

	BG_PALETTE_SUB[145] = ARGB16(1,0,31,0);
	BG_PALETTE_SUB[161] = ARGB16(1,31,0,0);
	BG_PALETTE_SUB[177] = ARGB16(1,0,0,31);

	hide_all_minerals();

	update_sprite(player_horizontal, PLAYER_SPRITE_ID, 1, PLAYER_VPAL, 0, 0,
			player_x, player_y);

	score_display(10, 1, (player_score > 0) ? 9:10, player_score, 26);

	int i, x, temp1, temp2;
	x = 6;
	temp1 = FUEL_RECHARGE;
	temp2 = DRILL_HEAL;
	for (i = 100; i > 0; i /= 10) {
		// fuel
		printDigit(temp1 / i, x, 8, 12, 26);
		temp1 = temp1 % i;
		// drill
		printDigit(temp2 / i, x, 16, 12, 26);
		temp2 = temp2 % i;
		x += 2;
	}
	oamUpdate(&oamMain);
}
