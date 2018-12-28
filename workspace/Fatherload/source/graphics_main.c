/*
 * graphics_main.c
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "graphics_main.h"

u8 dirtTile[64] = {
		255, 254, 255, 254, 254, 255, 255, 254,
		255, 254, 254, 255, 254, 255, 255, 254,
		255, 254, 254, 254, 254, 255, 255, 255,
		254, 254, 255, 254, 254, 255, 255, 255,
		255, 254, 254, 255, 254, 254, 255, 254,
		254, 254, 255, 255, 254, 255, 254, 255,
		255, 254, 255, 254, 254, 254, 255, 255,
		254, 255, 254, 255, 254, 255, 255, 254
};

void init_background3(){
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	REG_DISPCNT = MODE_5_2D | DISPLAY_BG0_ACTIVE;
	BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_64x64;
	swiCopy(FONDSTiles, BG_TILE_RAM(1), FONDSTilesLen/2);
	int i;
	for(i=0; i<32; i++){
		dmaCopy(&FONDSMap[i*64], &BG_MAP_RAM(0)[i*32], 64);
		dmaCopy(&FONDSMap[i*64 + 32], &BG_MAP_RAM(1)[i*32], 64);
		dmaCopy(&FONDSMap[(i + 32)*64], &BG_MAP_RAM(2)[i*32], 64);
		dmaCopy(&FONDSMap[(i + 32)*64 + 32], &BG_MAP_RAM(3)[i*32], 64);
	}


	dmaCopy(FONDSPal, BG_PALETTE, FONDSPalLen);
}