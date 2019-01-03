/*
 * graphics_main.c
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "graphics_main.h"

u8 fondTile[64] = {
		255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255
};

u8 endTile[64] = {
		255, 255, 254, 254, 255, 255, 254, 254,
		255, 255, 254, 254, 255, 255, 254, 254,
		254, 254, 255, 255, 254, 254, 255, 255,
		254, 254, 255, 255, 254, 254, 255, 255,
		255, 255, 254, 254, 255, 255, 254, 254,
		255, 255, 254, 254, 255, 255, 254, 254,
		254, 254, 255, 255, 254, 254, 255, 255,
		254, 254, 255, 255, 254, 254, 255, 255
};

u8 emptyTile[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0
};

void init_main_background(){
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG2_ACTIVE | DISPLAY_BG3_ACTIVE;
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_BG;

	// Init BG0
	BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_64x64;
	dmaCopy(emptyTile, (u8*)BG_TILE_RAM(1), 64);
	dmaCopy(fondTile, (u8*)BG_TILE_RAM(1) + 1*64, 64);
	dmaCopy(endTile, (u8*)BG_TILE_RAM(1) + 2*64, 64);

	dmaCopy(FONDSPal, BG_PALETTE, FONDSPalLen);
	BG_PALETTE[254] = ARGB16(1,15,15,15);
	BG_PALETTE[255] = ARGB16(1,21,17,12);

	int i, j;
	for(i = 0; i < 32; i++){
		for(j = 0; j < 32; j++){
			BG_MAP_RAM(0)[i*32 + j] = 0;
			BG_MAP_RAM(1)[i*32 + j] = 0;
			BG_MAP_RAM(2)[i*32 + j] = 0;
			BG_MAP_RAM(3)[i*32 + j] = 0;
		}
	}


	for(i = 0; i < 32; i++){
		BG_MAP_RAM(2)[31*32 + i] = 2;
		BG_MAP_RAM(3)[31*32 + i] = 2;
	}

	// Init background 2
	BGCTRL[2] = BG_COLOR_256 | BG_MAP_BASE(4) | BG_TILE_BASE(2) | BG_64x64;
	dmaCopy(FONDSTiles, BG_TILE_RAM(2), FONDSTilesLen);

	for(i=0; i<32; i++){
		dmaCopy(&FONDSMap[i*64], &BG_MAP_RAM(4)[i*32], 64);
		dmaCopy(&FONDSMap[i*64 + 32], &BG_MAP_RAM(5)[i*32], 64);
		dmaCopy(&FONDSMap[(i + 32)*64], &BG_MAP_RAM(6)[i*32], 64);
		dmaCopy(&FONDSMap[(i + 32)*64 + 32], &BG_MAP_RAM(7)[i*32], 64);
	}
}

void configureSprites() {
	//Set up memory bank to work in sprite mode (offset since we are using VRAM A for backgrounds)
	VRAM_F_CR = VRAM_ENABLE | VRAM_F_MAIN_SPRITE_0x06400000;

	//Initialize sprite manager and the engine
	oamInit(&oamMain, SpriteMapping_1D_32, false);

	//Allocate space for the graphic to show in the sprite
	gfx_vertical = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_16Color);
	gfx_horizontal = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_16Color);
	diamond_pic = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_16Color);

	//Copy data for the graphic (palette and bitmap)
	dmaCopy(PlayerHorizontalPal, &SPRITE_PALETTE[0], PlayerHorizontalPalLen);
	dmaCopy(PlayerHorizontalTiles, gfx_horizontal, PlayerHorizontalTilesLen);
	dmaCopy(PlayerVerticalPal, &SPRITE_PALETTE[1*16], PlayerVerticalPalLen);
	dmaCopy(PlayerVerticalTiles, gfx_vertical, PlayerVerticalTilesLen);
	dmaCopy(diamondPal, &SPRITE_PALETTE[2*16], diamondPalLen);
	dmaCopy(diamondTiles, diamond_pic, diamondTilesLen);
}


void setObjects(){
	int i;

	for(i = 0; i < DIAMOND_NUMBER; i++){
		diamond[i].x = (rand()%512);
		diamond[i].y = (rand()%(512-128-32-8))+ 128;
		// isTook = 0 when not took, 1 if the player took it
		diamond[i].isTook = 0;
	}
}

void update_state(){
	int i;

	if(player_y + REG_BG2VOFS > 112 + 16){
		int base = (((player_y + REG_BG2VOFS)>255)?2:0) + (player_x + REG_BG2HOFS)/256;
		int x = ((player_x + REG_BG2HOFS)%256)/8;
		int y = ((player_y + REG_BG2VOFS)%256)/8;
		printf("BASE found: %d, y: %d and x: %d.\n", base, y, x);
		if(orientation == UP || orientation == DOWN){
			for(i = y; i < y + 2; i++){
				if(i > 31)
					break;
				BG_MAP_RAM(base)[i*32 + x] = 1;
				BG_MAP_RAM(base)[i*32 + x + 1] = 1;
//				BG_MAP_RAM(base)[i*32 + x + 2] = 1;
//				BG_MAP_RAM(base)[i*32 + x + 3] = 1;
			}
		}
		else{
			for(i = x; i < x + 2; i++){
				if(i > 31)
					break;
				BG_MAP_RAM(base)[y*32 + i] = 1;
				BG_MAP_RAM(base)[(y + 1)*32 + i] = 1;
//				BG_MAP_RAM(base)[(y + 2)*32 + i] = 1;
//				BG_MAP_RAM(base)[(y + 3)*32 + i] = 1;
			}
		}
	}

	for(i = 0; i < DIAMOND_NUMBER; i++){
		if(!diamond[i].isTook && ((player_x + REG_BG2HOFS) == diamond[i].x &&
				(player_y + REG_BG2VOFS) == diamond[i].y)){
			diamond[i].isTook = 1;
			oamSet(&oamMain, 	// oam handler
								OFFSET_DIAMOND_SPRITE + i,				// Number of sprite
								diamond[i].x - REG_BG2HOFS, diamond[i].y - REG_BG2VOFS,			// Coordinates
								0,				// Priority
								2,				// Palette to use
								SpriteSize_16x16,			// Sprite size
								SpriteColorFormat_16Color,	// Color format
								diamond_pic,			// Loaded graphic to display
								-1,				// Affine rotation to use (-1 none)
								false,			// Double size if rotating
								true,			// Hide this sprite
								false, false,	// Horizontal or vertical flip
								false			// Mosaic
								);
		}

		if(!diamond[i].isTook){
			if(((diamond[i].x >  - 32) && (diamond[i].x < REG_BG2HOFS + 256)) &&
					((diamond[i].y > REG_BG2VOFS - 32) && (diamond[i].y < REG_BG2VOFS + 192))){

				oamSet(&oamMain, 	// oam handler
					OFFSET_DIAMOND_SPRITE + i,				// Number of sprite
					diamond[i].x - REG_BG2HOFS, diamond[i].y - REG_BG2VOFS,			// Coordinates
					0,				// Priority
					2,				// Palette to use
					SpriteSize_16x16,			// Sprite size
					SpriteColorFormat_16Color,	// Color format
					diamond_pic,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					false,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
					);
			}
			else{
				oamSet(&oamMain, 	// oam handler
					OFFSET_DIAMOND_SPRITE + i,				// Number of sprite
					diamond[i].x - REG_BG2HOFS, diamond[i].y - REG_BG2VOFS,			// Coordinates
					0,				// Priority
					2,				// Palette to use
					SpriteSize_16x16,			// Sprite size
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
		oamUpdate(&oamMain);
	}
}


