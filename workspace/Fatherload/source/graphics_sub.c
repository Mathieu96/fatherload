/*
 * graphics_main.c
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "graphics_sub.h"

u8 emptyTile2[64] = {
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0
};

void init_sub_background() {
	REG_DISPCNT_SUB = MODE_3_2D | DISPLAY_BG2_ACTIVE | DISPLAY_BG3_ACTIVE;
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	// Init BG2
	BGCTRL_SUB[2] = BG_TILE_BASE(4) | BG_MAP_BASE(8) | BG_COLOR_256 | BG_32x32;

	// Init BG3
	BGCTRL_SUB[3] = BG_MAP_BASE(0) | BG_BMP8_128x128;

	dmaCopy(controlsPal, BG_PALETTE_SUB, controlsPalLen);
	dmaCopy(controlsBitmap, BG_MAP_RAM_SUB(0), controlsBitmapLen);

	dmaCopy(numbers_smallTiles, BG_TILE_RAM_SUB(4), numbers_smallTilesLen);

	int i, j;
	// initialize all the tiles of BG2 to transparent, to avoid overlapping the background 3
	for (i = 0; i < 32; i++) {
		for (j = 0; j < 32; j++) {
			BG_MAP_RAM_SUB(8)[i * 32 + j] = 0;
		}
	}

	// Set up affine matrix
	REG_BG3PA_SUB = 256;
	REG_BG3PC_SUB = 0;
	REG_BG3PB_SUB = 0;
	REG_BG3PD_SUB = 256;
}

void printDigitSmall(int number, int x, int y) {
	int i, j;

	if (number >= 0 && number < 10)
		for (i = 0; i < 4; i++)
			for (j = 0; j < 2; j++)
				if (number >= 0)
					BG_MAP_RAM_SUB(8)[(i + y) * 32 + j + x] = (u16) (i * 2 + j
							+ 2) + 8 * number;
}

void printDigit(int number, int x, int y) {
	int i, j;

	if (number >= 0 && number < 10)
		for (i = 0; i < 8; i++)
			for (j = 0; j < 4; j++)
				if (number >= 0)
					BG_MAP_RAM_SUB(9)[(i + y) * 32 + j + x] = (u16) (i * 4 + j)
							+ 32 * number;
}

void updateChronoDisp(int min, int sec, int msec) {
	int i, j;

	printDigitSmall((int) min / 10, 0, 20);
	printDigitSmall((int) min % 10, 2, 20);

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			BG_MAP_RAM_SUB(8)[(i + 20) * 32 + j + 4] = (u16) (i * 2 + j + 2)
					+ 8 * 10;
		}
	}
	printDigitSmall((int) sec / 10, 6, 20);
	printDigitSmall((int) sec % 10, 8, 20);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			BG_MAP_RAM_SUB(8)[(i + 22) * 32 + j + 10] = (u16) (i * 2 + j + 8)
					+ 8 * 10;
		}
	}
	printDigitSmall((int) msec / 100, 11, 20);
	printDigitSmall((int) (msec % 100) / 10, 13, 20);
	printDigitSmall((int) msec % 10, 15, 20);
}

void update_scoreboard() {
	int i, x;
	x = 14;
	int temp = player_score;
	for (i = 10000000; i > 0; i /= 10) {
		x += 2;
		printDigitSmall(temp / i, x, 1);
		temp = temp % i;
	}
}
