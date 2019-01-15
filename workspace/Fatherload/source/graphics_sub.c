/*
 * graphics_main.c
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
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[9*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[10*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[11*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[12*16], numbers_smallPalLen);
	BG_PALETTE_SUB[145] = ARGB16(1,31,0,0);
	BG_PALETTE_SUB[161] = ARGB16(1,0,31,0);
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
					BG_MAP_RAM_SUB(base)[(i + y) * 32 + j + x] = ((u16) (i * 2 + j
							+ 2) + 8 * number) | TILE_PALETTE(pal);
}

void updateChronoDisp(int min, int sec, int msec, int pal, int base) {
	int i, j;

	printDigit((int) min / 10, 0, 20, pal, base);
	printDigit((int) min % 10, 2, 20, pal, base);

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			BG_MAP_RAM_SUB(base)[(i + 20) * 32 + j + 4] = ((u16) (i * 2 + j + 2)
					+ 8 * 10) | TILE_PALETTE(pal);
		}
	}
	printDigit((int) sec / 10, 6, 20, pal, base);
	printDigit((int) sec % 10, 8, 20, pal, base);

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			BG_MAP_RAM_SUB(base)[(i + 22) * 32 + j + 10] = ((u16) (i * 2 + j + 8)
					+ 8 * 10) | TILE_PALETTE(pal);
		}
	}

	printDigit((int) msec / 100, 11, 20, pal, base);
	printDigit((int) (msec % 100) / 10, 13, 20, pal, base);
	printDigit((int) msec % 10, 15, 20, pal, base);
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

void print_fuel(int x, int y, int pal){
	int i;
	int temp = player_fuel;
	for(i = 10000; i > 0; i /= 10){
		x += 2;
		printDigit(temp / i, x, y, pal, 26);
		temp = temp % i;
	}
}

void GameOver_sub_display(){
	REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE;
	BGCTRL_SUB[0] = BG_COLOR_16 | BG_MAP_BASE(1) | BG_TILE_BASE(2) | BG_32x32;
	BGCTRL_SUB[1] = BG_COLOR_16 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32;

	dmaCopy(game_over_subTiles, BG_TILE_RAM_SUB(1), game_over_subTilesLen);
	dmaCopy(game_over_subMap, BG_MAP_RAM_SUB(0), game_over_subMapLen);
	dmaCopy(game_over_subPal, BG_PALETTE_SUB, game_over_subPalLen);

	dmaCopy(numbers_smallTiles, BG_TILE_RAM_SUB(2), numbers_smallTilesLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[1*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[2*16], numbers_smallPalLen);
	dmaCopy(numbers_smallPal, &BG_PALETTE_SUB[3*16], numbers_smallPalLen);
	BG_PALETTE_SUB[17] = ARGB16(1,31,0,0);
	BG_PALETTE_SUB[33] = ARGB16(1,0,31,0);
	BG_PALETTE_SUB[49] = ARGB16(1,0,0,31);

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
	updateChronoDisp(min, sec, msec, 3, 1);
}

void starting_sub_display(){
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
	REG_DISPCNT_SUB = MODE_3_2D | DISPLAY_BG0_ACTIVE;

	BGCTRL_SUB[0] = BG_TILE_BASE(1) | BG_MAP_BASE(0) | BG_COLOR_256 | BG_32x32;

	dmaCopy(press_to_beginTiles, BG_TILE_RAM_SUB(1), press_to_beginTilesLen);
	dmaCopy(press_to_beginMap, BG_MAP_RAM_SUB(0), press_to_beginMapLen);
	dmaCopy(press_to_beginPal,   BG_PALETTE_SUB, press_to_beginPalLen);
}
