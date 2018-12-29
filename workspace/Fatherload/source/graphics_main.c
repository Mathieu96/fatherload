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

void configureSprites(u16 **gfx1, u16 **gfx2) {
	//Set up memory bank to work in sprite mode (offset since we are using VRAM A for backgrounds)
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;

	//Initialize sprite manager and the engine
	oamInit(&oamMain, SpriteMapping_1D_32, false);

	//Allocate space for the graphic to show in the sprite
	*gfx1 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	*gfx2 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

	//Copy data for the graphic (palette and bitmap)
	dmaCopy(PlayerHorizontalPal, SPRITE_PALETTE, PlayerHorizontalPalLen);
	dmaCopy(PlayerHorizontalTiles, *gfx1, PlayerHorizontalTilesLen);
	dmaCopy(PlayerVerticalTiles, *gfx2, PlayerVerticalTilesLen);
}


void init_background3(){
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	REG_DISPCNT = MODE_5_2D | DISPLAY_BG0_ACTIVE;
	BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_64x64;
	dmaCopy(FONDSTiles, BG_TILE_RAM(1), FONDSTilesLen);
	int i;
	for(i=0; i<32; i++){
		dmaCopy(&FONDSMap[i*64], &BG_MAP_RAM(0)[i*32], 64);
		dmaCopy(&FONDSMap[i*64 + 32], &BG_MAP_RAM(1)[i*32], 64);
	}

	for(i = 0; i<31; i++){
		dmaCopy(&FONDSMap[(i + 32)*64], &BG_MAP_RAM(2)[i*32], 64);
		dmaCopy(&FONDSMap[(i + 32)*64 + 32], &BG_MAP_RAM(3)[i*32], 64);
	}

	dmaCopy(&FONDSMap[0], &BG_MAP_RAM(2)[31*32], 64);
	dmaCopy(&FONDSMap[32], &BG_MAP_RAM(3)[31*32], 64);

	dmaCopy(FONDSPal, BG_PALETTE, FONDSPalLen);
}

void setObjects(Objects_coord **diamond){
	int i;

	u16* diamond_pic;

	oamInit(&oamMain, SpriteMapping_1D_32, false);

	//Allocate space for the graphic to show in the sprite
	diamond_pic = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

	//Copy data for the graphic (palette and bitmap)
	dmaCopy(diamondPal, SPRITE_PALETTE, diamondPalLen);
	dmaCopy(diamondTiles, diamond_pic, diamondTilesLen);

	for(i = 0; i < DIAMOND_NUMBER; i++){
		diamond[i]->x = rand()%(512-128) + 128;
		diamond[i]->y = rand()%512;
		oamSet(&oamMain, 	// oam handler
			0,				// Number of sprite
			diamond[i]->x, diamond[i]->x,			// Coordinates
			0,				// Priority
			0,				// Palette to use
			SpriteSize_32x32,			// Sprite size
			SpriteColorFormat_256Color,	// Color format
			diamond_pic,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
			);
	}
}
