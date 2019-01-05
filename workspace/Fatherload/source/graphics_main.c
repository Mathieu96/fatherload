/*
 * graphics_main.c
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "graphics_main.h"
#include "P_Audio.h"

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

u8 troubleTile[64] = {
	0,0,254,254,0,0,254,254,
	0,0,254,254,0,0,254,254,
	254,254,0,0,254,254,0,0,
	254,254,0,0,254,254,0,0,
	0,0,254,254,0,0,254,254,
	0,0,254,254,0,0,254,254,
	254,254,0,0,254,254,0,0,
	254,254,0,0,254,254,0,0
};

void config_main_background(){
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE | DISPLAY_BG2_ACTIVE | DISPLAY_BG3_ACTIVE;
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_BG;

	// Init BG0
	BGCTRL[3] = BG_COLOR_256 | BG_MAP_BASE(10) | BG_TILE_BASE(10) | BG_32x32;
	dmaCopy(Game_OverTiles, BG_TILE_RAM(16), Game_OverTilesLen);

	// Init BG1
	BGCTRL[1] = BG_COLOR_256 | BG_MAP_BASE(9) | BG_TILE_BASE(1) | BG_32x32;
	dmaCopy(emptyTile, (u8*)BG_TILE_RAM(1), 64);
	dmaCopy(fondTile, (u8*)BG_TILE_RAM(1) + 1*64, 64);
	dmaCopy(endTile, (u8*)BG_TILE_RAM(1) + 2*64, 64);
	dmaCopy(troubleTile, (u8*)BG_TILE_RAM(1) + 3*64, 64);

	// Init BG2
	BGCTRL[2] = BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_64x64;

	dmaCopy(FONDSPal, BG_PALETTE, FONDSPalLen);
	BG_PALETTE[254] = ARGB16(1,15,15,15);
	BG_PALETTE[255] = ARGB16(1,21,17,12);

	// Init background 3
	BGCTRL[3] = BG_COLOR_256 | BG_MAP_BASE(4) | BG_TILE_BASE(2) | BG_64x64;
	dmaCopy(FONDSTiles, BG_TILE_RAM(2), FONDSTilesLen);
}

void init_main_bg(){
	int i,j;
	// init the map of BG1
	for(i = 0; i < 24; i++){
		for(j = 0; j < 32; j++){
			BG_MAP_RAM(9)[i*32 + j] = 0;
		}
	}

	// Init map of BG2
	for(i = 0; i < 32; i++){
		for(j = 0; j < 32; j++){
			BG_MAP_RAM(0)[i*32 + j] = 0;
			BG_MAP_RAM(1)[i*32 + j] = 0;
			BG_MAP_RAM(2)[i*32 + j] = 0;
			BG_MAP_RAM(3)[i*32 + j] = 0;
		}
	}

	// Init Map of BG2
	for(i = 0; i < 32; i++){
		BG_MAP_RAM(2)[31*32 + i] = 2;
		BG_MAP_RAM(3)[31*32 + i] = 2;
	}

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
	amazonite_pic = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_16Color);
	bronze_pic = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_16Color);
	alexxzandrite_pic = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_16Color);

	//Copy data for the graphic (palette and bitmap)
	// Horizontal player
	dmaCopy(PlayerHorizontalPal, &SPRITE_PALETTE[0], PlayerHorizontalPalLen);
	dmaCopy(PlayerHorizontalTiles, gfx_horizontal, PlayerHorizontalTilesLen);
	// Vertical player
	dmaCopy(PlayerVerticalPal, &SPRITE_PALETTE[1*16], PlayerVerticalPalLen);
	dmaCopy(PlayerVerticalTiles, gfx_vertical, PlayerVerticalTilesLen);
	// diamond
	dmaCopy(diamondPal, &SPRITE_PALETTE[2*16], diamondPalLen);
	dmaCopy(diamondTiles, diamond_pic, diamondTilesLen);
	// amazonite
	dmaCopy(amazonitePal, &SPRITE_PALETTE[3*16], amazonitePalLen);
	dmaCopy(amazoniteTiles, amazonite_pic, amazoniteTilesLen);
	// bronze
	dmaCopy(bronzePal, &SPRITE_PALETTE[4*16], bronzePalLen);
	dmaCopy(bronzeTiles, bronze_pic, bronzeTilesLen);
	// alexxzandrite
	dmaCopy(alexxzandritePal, &SPRITE_PALETTE[5*16], alexxzandritePalLen);
	dmaCopy(alexxzandriteTiles, alexxzandrite_pic, alexxzandriteTilesLen);
}


void setObjects(){
	int i;
	// Generate the diamonds, deep on the map
	for(i = 0; i < DIAMOND_NUMBER; i++){
		mineral[i].x = (rand()%512);
		mineral[i].y = (rand()%(512-384-16-8)) + 384;
		// isTook = 0 when not took, 1 when the player took it
		mineral[i].isTook = 0;
		strcpy(mineral[i].type,"diamond");
	}
	// Generate the amazonite
	for(i = DIAMOND_NUMBER; i < DIAMOND_NUMBER + AMAZONITE_NUMBER; i++){
			mineral[i].x = (rand()%512);
			mineral[i].y = (rand()%(512-256-16-8))+ 256;
			// isTook = 0 when not took, 1 when the player took it
			mineral[i].isTook = 0;
			strcpy(mineral[i].type,"amazonite");
	}
	// Generate the bronzes
	for(i = DIAMOND_NUMBER + AMAZONITE_NUMBER; i < DIAMOND_NUMBER + AMAZONITE_NUMBER + BRONZE_NUMBER; i++){
			mineral[i].x = (rand()%512);
			mineral[i].y = (rand()%(512-128-16-8)) + 128;
			// isTook = 0 when not took, 1 when the player took it
			mineral[i].isTook = 0;
			strcpy(mineral[i].type,"bronze");
	}
	// Generate the alexxzandrites
	for(i = DIAMOND_NUMBER + AMAZONITE_NUMBER + BRONZE_NUMBER;
			i < DIAMOND_NUMBER + AMAZONITE_NUMBER + BRONZE_NUMBER + ALEXXZANDRITE_NUMBER; i++){
			mineral[i].x = (rand()%512);
			mineral[i].y = (rand()%(512-384-16-8))+ 384;
			// isTook = 0 when not took, 1 when the player took it
			mineral[i].isTook = 0;
			strcpy(mineral[i].type,"bronze");
	}
}

void update_state(){
	int i;
	int position_y = player_y + screen_y;
	int position_x = player_x + screen_x;

	if(position_y > 112 + 15){
		int base = (((position_y)>255)?2:0) + (position_x)/256;
		int x = ((position_x)%256)/8;
		int y = ((position_y)%256)/8;
		if(orientation == UP || orientation == DOWN){
			for(i = y; i < y + 2; i++){
				if(i > 31){
					BG_MAP_RAM(base+2)[0*32 + x] = 1;
					break;
				}
				if(x == 31 && (base == 0 || base == 2)){
					BG_MAP_RAM(base)[i*32 + x] = 1;
					BG_MAP_RAM(base+1)[i*32 + 0] = 1;
					continue;
				}
				BG_MAP_RAM(base)[i*32 + x] = 1;
				BG_MAP_RAM(base)[i*32 + x + 1] = 1;
//				BG_MAP_RAM(base)[i*32 + x + 2] = 1; //for 32*32 sprite
//				BG_MAP_RAM(base)[i*32 + x + 3] = 1;
			}
		}
		else{
			for(i = x; i < x + 2; i++){
				if(i > 31){
					if(base == 0 || base == 2)
						BG_MAP_RAM(base+1)[y*32 + 0] = 1;
					break;
				}
				if(y == 31){
					if(base == 0 || base == 1){
						BG_MAP_RAM(base)[y*32 + i] = 1;
						BG_MAP_RAM(base+2)[0*32 + i] = 1;
					}
					continue;
				}
				BG_MAP_RAM(base)[y*32 + i] = 1;
				BG_MAP_RAM(base)[(y + 1)*32 + i] = 1;
//				BG_MAP_RAM(base)[(y + 2)*32 + i] = 1; //for 32*32 sprite
//				BG_MAP_RAM(base)[(y + 3)*32 + i] = 1;
			}
		}
	}
	check_alexxzandrite(position_x, position_y);
	check_amazonite(position_x, position_y);
	check_diamond(position_x, position_y);
	check_bronze(position_x, position_y);
		oamUpdate(&oamMain);
}

void check_diamond(int position_x, int position_y){
	int i;
	for(i = 0; i < DIAMOND_NUMBER; i++){
		if(!mineral[i].isTook && (
		(((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) //abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isTook = 1;
			oamSet(&oamMain, 	// oam handler
								OFFSET_MINERAL_SPRITE + i,				// Number of sprite
								mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
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

		if(!mineral[i].isTook){
			if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
					((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){

				oamSet(&oamMain, 	// oam handler
					OFFSET_MINERAL_SPRITE + i,				// Number of sprite
					mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
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
					OFFSET_MINERAL_SPRITE + i,				// Number of sprite
					mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
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
	}
}

void check_amazonite(int position_x, int position_y){
	int i;
	for(i = DIAMOND_NUMBER; i < DIAMOND_NUMBER + AMAZONITE_NUMBER; i++){
		if(!mineral[i].isTook && (
		(((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) //abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isTook = 1;
			oamSet(&oamMain, 	// oam handler
								OFFSET_MINERAL_SPRITE + i,				// Number of sprite
								mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
								0,				// Priority
								2,				// Palette to use
								SpriteSize_16x16,			// Sprite size
								SpriteColorFormat_16Color,	// Color format
								amazonite_pic,			// Loaded graphic to display
								-1,				// Affine rotation to use (-1 none)
								false,			// Double size if rotating
								true,			// Hide this sprite
								false, false,	// Horizontal or vertical flip
								false			// Mosaic
								);
		}

		if(!mineral[i].isTook){
			if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
					((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){

				oamSet(&oamMain, 	// oam handler
					OFFSET_MINERAL_SPRITE + i,				// Number of sprite
					mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
					0,				// Priority
					2,				// Palette to use
					SpriteSize_16x16,			// Sprite size
					SpriteColorFormat_16Color,	// Color format
					amazonite_pic,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					false,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
					);
			}
			else{
				oamSet(&oamMain, 	// oam handler
					OFFSET_MINERAL_SPRITE + i,				// Number of sprite
					mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
					0,				// Priority
					2,				// Palette to use
					SpriteSize_16x16,			// Sprite size
					SpriteColorFormat_16Color,	// Color format
					amazonite_pic,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					true,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
					);
			}
		}
	}
}

void check_bronze(int position_x, int position_y){
	int i;
	for(i = DIAMOND_NUMBER + AMAZONITE_NUMBER; i < DIAMOND_NUMBER + AMAZONITE_NUMBER + BRONZE_NUMBER; i++){
		if(!mineral[i].isTook && (
		(((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) //abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isTook = 1;
			oamSet(&oamMain, 	// oam handler
								OFFSET_MINERAL_SPRITE + i,				// Number of sprite
								mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
								0,				// Priority
								2,				// Palette to use
								SpriteSize_16x16,			// Sprite size
								SpriteColorFormat_16Color,	// Color format
								bronze_pic,			// Loaded graphic to display
								-1,				// Affine rotation to use (-1 none)
								false,			// Double size if rotating
								true,			// Hide this sprite
								false, false,	// Horizontal or vertical flip
								false			// Mosaic
								);
		}

		if(!mineral[i].isTook){
			if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
					((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){

				oamSet(&oamMain, 	// oam handler
					OFFSET_MINERAL_SPRITE + i,				// Number of sprite
					mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
					0,				// Priority
					2,				// Palette to use
					SpriteSize_16x16,			// Sprite size
					SpriteColorFormat_16Color,	// Color format
					bronze_pic,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					false,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
					);
			}
			else{
				oamSet(&oamMain, 	// oam handler
					OFFSET_MINERAL_SPRITE + i,				// Number of sprite
					mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
					0,				// Priority
					2,				// Palette to use
					SpriteSize_16x16,			// Sprite size
					SpriteColorFormat_16Color,	// Color format
					bronze_pic,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					true,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
					);
			}
		}
	}
}

void check_alexxzandrite(int position_x, int position_y){
	int i;
	for(i = DIAMOND_NUMBER + AMAZONITE_NUMBER + BRONZE_NUMBER;
		i < DIAMOND_NUMBER + AMAZONITE_NUMBER + BRONZE_NUMBER + ALEXXZANDRITE_NUMBER; i++){
		if(!mineral[i].isTook && (
		(((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) //abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isTook = 1;
			oamSet(&oamMain, 	// oam handler
								OFFSET_MINERAL_SPRITE + i,				// Number of sprite
								mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
								0,				// Priority
								2,				// Palette to use
								SpriteSize_16x16,			// Sprite size
								SpriteColorFormat_16Color,	// Color format
								alexxzandrite_pic,			// Loaded graphic to display
								-1,				// Affine rotation to use (-1 none)
								false,			// Double size if rotating
								true,			// Hide this sprite
								false, false,	// Horizontal or vertical flip
								false			// Mosaic
								);
		}

		if(!mineral[i].isTook){
			if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
					((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){

				oamSet(&oamMain, 	// oam handler
					OFFSET_MINERAL_SPRITE + i,				// Number of sprite
					mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
					0,				// Priority
					2,				// Palette to use
					SpriteSize_16x16,			// Sprite size
					SpriteColorFormat_16Color,	// Color format
					alexxzandrite_pic,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					false,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
					);
			}
			else{
				oamSet(&oamMain, 	// oam handler
					OFFSET_MINERAL_SPRITE + i,				// Number of sprite
					mineral[i].x - screen_x, mineral[i].y - screen_y,			// Coordinates
					0,				// Priority
					2,				// Palette to use
					SpriteSize_16x16,			// Sprite size
					SpriteColorFormat_16Color,	// Color format
					alexxzandrite_pic,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					true,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
					);
			}
		}
	}
}


void restart_display(){
	dmaCopy(Game_OverMap, BG_MAP_RAM(10), Game_OverMapLen);
}

void load_start_display(){
	int i, j;
	for(i = 0; i < 24; i++){
		for(j = 0; j < 32; j++){
			BG_MAP_RAM(9)[i*32 + j] = 3;
		}
	}
	print_start();
}

void print_start(){
	int i;
	irqDisable(IRQ_TIMER0);

	// Drawing S
	BG_MAP_RAM(9)[9*32 + 5] = 1;
	BG_MAP_RAM(9)[9*32 + 4] = 1;
	BG_MAP_RAM(9)[9*32 + 3] = 1;
	BG_MAP_RAM(9)[9*32 + 2] = 1;
	BG_MAP_RAM(9)[10*32 + 1] = 1;
	BG_MAP_RAM(9)[10*32 + 2] = 1;
	BG_MAP_RAM(9)[11*32 + 3] = 1;
	BG_MAP_RAM(9)[11*32 + 4] = 1;
	BG_MAP_RAM(9)[12*32 + 5] = 1;
	BG_MAP_RAM(9)[13*32 + 5] = 1;
	BG_MAP_RAM(9)[13*32 + 4] = 1;
	BG_MAP_RAM(9)[14*32 + 4] = 1;
	BG_MAP_RAM(9)[14*32 + 3] = 1;
	BG_MAP_RAM(9)[15*32 + 3] = 1;
	BG_MAP_RAM(9)[15*32 + 2] = 1;
	BG_MAP_RAM(9)[15*32 + 1] = 1;

	// Drawing T
	for(i = 7; i < 12; i++)
			BG_MAP_RAM(9)[9*32 + i] = 1;
		for(i = 9; i < 17; i++)
			BG_MAP_RAM(9)[i*32 + 9] = 1;

	// Drawing A
	BG_MAP_RAM(9)[9*32 + 16] = 1;
	BG_MAP_RAM(9)[9*32 + 15] = 1;
	BG_MAP_RAM(9)[9*32 + 17] = 1;
	BG_MAP_RAM(9)[10*32 + 15] = 1;
	BG_MAP_RAM(9)[10*32 + 14] = 1;
	BG_MAP_RAM(9)[10*32 + 17] = 1;
	BG_MAP_RAM(9)[10*32 + 18] = 1;
	BG_MAP_RAM(9)[11*32 + 18] = 1;
	BG_MAP_RAM(9)[11*32 + 19] = 1;
	BG_MAP_RAM(9)[11*32 + 14] = 1;
	BG_MAP_RAM(9)[11*32 + 13] = 1;

	for(i = 12; i < 17; i++){
		BG_MAP_RAM(9)[i*32 + 13] = 1;
		BG_MAP_RAM(9)[i*32 + 19] = 1;
	}
	for(i = 13; i < 19; i++)
		BG_MAP_RAM(9)[13*32 + i] = 1;

	// Drawing R
	for(i = 9; i < 17; i++)
			BG_MAP_RAM(9)[i*32 + 21] = 1;
	for(i = 1; i < 4; i++)
		BG_MAP_RAM(9)[(12+i)*32 + 21+i] = 1;
	BG_MAP_RAM(9)[16*32 + 24] = 1;
	BG_MAP_RAM(9)[9*32 + 22] = 1;
	BG_MAP_RAM(9)[9*32 + 23] = 1;
	BG_MAP_RAM(9)[9*32 + 24] = 1;
	BG_MAP_RAM(9)[10*32 + 24] = 1;
	BG_MAP_RAM(9)[11*32 + 24] = 1;
	BG_MAP_RAM(9)[11*32 + 23] = 1;
	BG_MAP_RAM(9)[12*32 + 22] = 1;
	BG_MAP_RAM(9)[12*32 + 23] = 1;

	// Drawing T
	for(i = 26; i < 31; i++)
		BG_MAP_RAM(9)[9*32 + i] = 1;
	for(i = 9; i < 17; i++)
		BG_MAP_RAM(9)[i*32 + 28] = 1;

}

void release_start_display(){
	int i, j;
	for(i = 0; i < 24; i++){
		for(j = 0; j < 32; j++){
			BG_MAP_RAM(9)[i*32 + j] = 0;
		}
	}
}

