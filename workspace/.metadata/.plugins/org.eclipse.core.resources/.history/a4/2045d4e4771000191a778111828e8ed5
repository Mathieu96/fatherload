/*
 * graphics_main.c
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "graphics_sub.h"

void init_sub_background(){
	REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG3_ACTIVE;
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	// Init BG3
	BGCTRL_SUB[3] = BG_MAP_BASE(0) | BgSize_B8_128x128;

	dmaCopy(controlsPal, BG_PALETTE_SUB, controlsPalLen);
	dmaCopy(controlsBitmap, BG_MAP_RAM_SUB(0), controlsBitmapLen);

    // Set up affine matrix
    REG_BG3PA_SUB = 256;
    REG_BG3PC_SUB = 0;
    REG_BG3PB_SUB = 0;
    REG_BG3PD_SUB = 256;
}
