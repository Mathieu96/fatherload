/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "graphics_main.h"

#define PLAYER_SPRITE_ID 0
#define OFFSET_DIAMOND_SPRITE 1

enum {UP, DOWN, LEFT, RIGHT} orientation;

u16 *gfx_horizontal, *gfx_vertical;

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

int main(void){
	srand(time(NULL));
	init_background3();
	int player_x = 128; int player_y = 192/2; int screen_x = 128; int screen_y = 0;
	orientation = RIGHT;
//	Objects_coord diamond[DIAMOND_NUMBER];

//	setObjects(&diamond);

	u16 keys;
	configureSprites(&gfx_horizontal, &gfx_vertical);

    while(1){
    	scanKeys();
    	keys = keysHeld();
    	if((keys & KEY_DOWN) && (screen_y < 512 - 192)){
    		orientation = DOWN;
    		dmaCopy(PlayerVerticalPal, SPRITE_PALETTE, PlayerVerticalPalLen);
    		screen_y +=3;
    		if(player_y < 152)
    			player_y++;
    	}
    	if((keys & KEY_UP) && (screen_y > 0)){
    		orientation = UP;
    		dmaCopy(PlayerVerticalPal, SPRITE_PALETTE, PlayerVerticalPalLen);
			screen_y -=3;
			if(player_y > 96)
				player_y--;
    	}
    	if((keys & KEY_RIGHT) && (screen_x < 512 - 256 - 32)){
    		orientation = RIGHT;
    		dmaCopy(PlayerHorizontalPal, SPRITE_PALETTE, PlayerHorizontalPalLen);
    		screen_x++;
    		player_x++;
    	}
    	if((keys & KEY_LEFT) && (screen_x > 0)){
    		dmaCopy(PlayerHorizontalPal, SPRITE_PALETTE, PlayerHorizontalPalLen);
    		orientation = LEFT;
    		screen_x--;
    		player_x--;
    	}

    	REG_BG0HOFS = screen_x;
    	REG_BG0VOFS = screen_y;
		swiWaitForVBlank();

		switch(orientation){
		case RIGHT:
			oamSet(&oamMain, 	// oam handler
				PLAYER_SPRITE_ID,				// Number of sprite
				player_x, player_y,			// Coordinates
				0,				// Priority
				0,				// Palette to use
				SpriteSize_32x32,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				gfx_horizontal,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
				);
			break;
		case LEFT:
			oamSet(&oamMain, 	// oam handler
				PLAYER_SPRITE_ID,				// Number of sprite
				player_x, player_y,			// Coordinates
				0,				// Priority
				0,				// Palette to use
				SpriteSize_32x32,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				gfx_horizontal,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				true, false,	// Horizontal or vertical flip
				false			// Mosaic
				);
			break;
		case UP:
			oamSet(&oamMain, 	// oam handler
				PLAYER_SPRITE_ID,				// Number of sprite
				player_x, player_y,			// Coordinates
				0,				// Priority
				0,				// Palette to use
				SpriteSize_32x32,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				gfx_vertical,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
				);
			break;
		case DOWN:
			oamSet(&oamMain, 	// oam handler
				PLAYER_SPRITE_ID,				// Number of sprite
				player_x, player_y,			// Coordinates
				0,				// Priority
				0,				// Palette to use
				SpriteSize_32x32,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				gfx_vertical,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, true,	// Horizontal or vertical flip
				false			// Mosaic
				);
			break;
		}

		oamUpdate(&oamMain);
		//shifting horizontally from left to right
/*		for(i=0; i<=512-256; i++){
			swiWaitForVBlank();
			REG_BG0HOFS = i;
		}
		//shifting vertically from up to down
		for(i=0; i<=512-192; i++){
			swiWaitForVBlank();
			REG_BG0VOFS = i;
		}
		//shifting horizontally from right to left
		for(i=512-256; i>=0; i--){
			swiWaitForVBlank();
			REG_BG0HOFS = i;
		}
		//shifting vertically from down to up
		for(i=512-192; i>=0; i--){
			swiWaitForVBlank();
			REG_BG0VOFS = i;
		}
*/
    }
}
