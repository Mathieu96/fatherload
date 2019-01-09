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
	REG_DISPCNT_SUB = MODE_3_2D | DISPLAY_BG1_ACTIVE | DISPLAY_BG2_ACTIVE | DISPLAY_BG3_ACTIVE;
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	// Init BG1
	BGCTRL_SUB[1] = BG_TILE_BASE(4) | BG_MAP_BASE(8) | BG_COLOR_16 | BG_32x32;

	// Init BG2
	BGCTRL_SUB[2] = BG_TILE_BASE(4) | BG_MAP_BASE(9) | BG_COLOR_16 | BG_32x32;

	// Init BG3
	BGCTRL_SUB[3] = BG_MAP_BASE(0) | BG_BMP8_128x128;

	dmaCopy(controlsPal, BG_PALETTE_SUB, controlsPalLen);
	dmaCopy(controlsBitmap, BG_MAP_RAM_SUB(0), controlsBitmapLen);

	dmaCopy(numbers_smallTiles, BG_TILE_RAM_SUB(4), numbers_smallTilesLen);
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
			BG_MAP_RAM_SUB(8)[i * 32 + j] = 0 | TILE_PALETTE(9);
		}
	}

	for (i = 0; i < 32; i++) {
		for (j = 0; j < 32; j++) {
			BG_MAP_RAM_SUB(9)[i * 32 + j] = 0 | TILE_PALETTE(11);
		}
	}

	// Set up affine matrix
	REG_BG3PA_SUB = 256;
	REG_BG3PC_SUB = 0;
	REG_BG3PB_SUB = 0;
	REG_BG3PD_SUB = 256;
}

void printDigit(int number, int x, int y, int pal) {
	int i, j;

	if (number >= 0 && number < 10)
		for (i = 0; i < 4; i++)
			for (j = 0; j < 2; j++)
				if (number >= 0)
					BG_MAP_RAM_SUB(8)[(i + y) * 32 + j + x] = ((u16) (i * 2 + j
							+ 2) + 8 * number) | TILE_PALETTE(pal);
}

void updateChronoDisp(int min, int sec, int msec, int pal) {
	int i, j;

	printDigit((int) min / 10, 0, 20, pal);
	printDigit((int) min % 10, 2, 20, pal);

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			BG_MAP_RAM_SUB(9)[(i + 20) * 32 + j + 4] = ((u16) (i * 2 + j + 2)
					+ 8 * 10) | TILE_PALETTE(pal);
		}
	}
	printDigit((int) sec / 10, 6, 20, pal);
	printDigit((int) sec % 10, 8, 20, pal);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			BG_MAP_RAM_SUB(9)[(i + 22) * 32 + j + 10] = ((u16) (i * 2 + j + 8)
					+ 8 * 10) | TILE_PALETTE(pal);
		}
	}
	printDigit((int) msec / 100, 11, 20, pal);
	printDigit((int) (msec % 100) / 10, 13, 20, pal);
	printDigit((int) msec % 10, 15, 20, pal);
}

void score_display(int x, int y, int pal, int score){
	int i;
	int temp = player_score;
	for (i = 1000000; i > 0; i /= 10) {
		x += 2;
		printDigit(temp / i, x, y, pal);
		temp = temp % i;
	}
}

void print_fuel(int x, int y, int pal){
	int i;
	int temp = player_fuel;
	for(i = 100000; i > 0; i /= 10){
		x += 2;
		printDigit(temp / i, x, y, pal);
		temp = temp % i;
	}
}
