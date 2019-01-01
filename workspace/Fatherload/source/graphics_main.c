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

void configureSprites() {
	//Set up memory bank to work in sprite mode (offset since we are using VRAM A for backgrounds)
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;

	//Initialize sprite manager and the engine
	oamInit(&oamMain, SpriteMapping_1D_32, false);

	//Allocate space for the graphic to show in the sprite
	gfx_vertical = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_16Color);
	gfx_horizontal = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_16Color);
	diamond_pic = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_16Color);

	//Copy data for the graphic (palette and bitmap)
	dmaCopy(PlayerHorizontalPal, &SPRITE_PALETTE[0], PlayerHorizontalPalLen);
	dmaCopy(PlayerHorizontalTiles, gfx_horizontal, PlayerHorizontalTilesLen);
	dmaCopy(PlayerVerticalPal, &SPRITE_PALETTE[1*16], PlayerVerticalPalLen);
	dmaCopy(PlayerVerticalTiles, gfx_vertical, PlayerVerticalTilesLen);
	dmaCopy(diamondPal, &SPRITE_PALETTE[2*16], diamondPalLen);
	dmaCopy(diamondTiles, diamond_pic, diamondTilesLen);
}


void init_background2(){
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	REG_DISPCNT = MODE_3_2D | DISPLAY_BG2_ACTIVE;
	BGCTRL[2] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_64x64;
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

	dmaCopy(FONDSPal, BG_PALETTE, FONDSPalLen);
}

void setObjects(){
	int i;

	for(i = 0; i < DIAMOND_NUMBER; i++){
		diamond[i].x = rand()%(512);
		diamond[i].y = (rand()%(512-128))+128;
	}
}

void printDiamond(){
	int i;
	for(i = 0; i < DIAMOND_NUMBER; i++){
		if(((diamond[i].x >  - 32) && (diamond[i].x < REG_BG2HOFS + 256)) &&
				((diamond[i].y > REG_BG2VOFS - 32) && (diamond[i].y < REG_BG2VOFS + 192))){

			oamSet(&oamMain, 	// oam handler
				OFFSET_DIAMOND_SPRITE + i,				// Number of sprite
				diamond[i].x - REG_BG2HOFS, diamond[i].y - REG_BG2VOFS,			// Coordinates
				0,				// Priority
				2,				// Palette to use
				SpriteSize_32x32,			// Sprite size
				SpriteColorFormat_16Color,	// Color format
				diamond_pic,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
				);
		}
		else
			oamSet(&oamMain, 	// oam handler
				OFFSET_DIAMOND_SPRITE + i,				// Number of sprite
				diamond[i].x - REG_BG2HOFS, diamond[i].y - REG_BG2VOFS,			// Coordinates
				0,				// Priority
				2,				// Palette to use
				SpriteSize_32x32,			// Sprite size
				SpriteColorFormat_16Color,	// Color format
				diamond_pic,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				true,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
				);
	}
}
