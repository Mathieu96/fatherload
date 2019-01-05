/*
 * graphics_main.c
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "graphics_sub.h"

void init_sub_background(){
	REG_DISPCNT_SUB = MODE_3_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG3_ACTIVE;
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	// Init BG3
	BGCTRL_SUB[3] = BG_MAP_BASE(0) | BG_BMP8_128x128;
	BGCTRL_SUB[0] = BG_TILE_BASE(4) | BG_MAP_BASE(8) | BG_COLOR_256 | BG_32x32;

	dmaCopy(controlsPal, BG_PALETTE_SUB, controlsPalLen);
	dmaCopy(controlsBitmap, BG_MAP_RAM_SUB(0), controlsBitmapLen);

	dmaCopy(numbersTiles, BG_TILE_RAM_SUB(4), numbersTilesLen);
	dmaCopy(numbersPal, BG_PALETTE_SUB, numbersPalLen);
    // Set up affine matrix
    REG_BG3PA_SUB = 256;
    REG_BG3PC_SUB = 0;
    REG_BG3PB_SUB = 0;
    REG_BG3PD_SUB = 256;
}

void printDigit(int number, int x, int y){
	int i,j;

	if(number >= 0 && number < 10)
		for(i = 0; i<8;i++)
			for(j = 0; j<4; j++)
				if(number >= 0)
					BG_MAP_RAM_SUB(8)[(i + y)*32+j+x] = (u16)(i*4+j)+32*number;
}



void updateChronoDisp(int min, int sec, int msec){
	int i, j;
	for(i = 0; i < 32; i++){
		for(j = 0; j < 32; j++){
			BG_MAP_RAM_SUB(8)[i*32 + j] = 32;
		}
	}

	printDigit((int)min/10, 0, 16);
	printDigit((int)min%10, 4, 16);

	for(i=0; i<8; i++){
		for(j=0; j<2; j++){
			BG_MAP_RAM_SUB(8)[(i+16)*32 + j + 8] = (u16)(i*4+j+2) + 32*10;
		}
	}
	printDigit((int)sec/10, 10, 16);
	printDigit((int)sec%10, 14, 16);
	for(i=0; i<8; i++){
		for(j=0; j<2; j++){
			BG_MAP_RAM_SUB(8)[(i+16)*32 + j + 18] = (u16)(i*4+j) + 32*10;
		}
	}
	printDigit((int)msec/100, 20, 16);
	printDigit((int)(msec%100)/10, 24, 16);
	printDigit((int)msec%10, 28, 16);
}
