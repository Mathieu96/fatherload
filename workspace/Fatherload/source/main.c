/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "graphics_main.h"

u16 *gfx_right, *gfx_left;

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
	int player_x = 0; int player_y = 192/2 + 10; int screen_x = 0; int screen_y = 0;
	int isLeft = 0;
//	Objects_coord diamond[DIAMOND_NUMBER];

//	setObjects(&diamond);

	u16 keys;
	configureSprites(&gfx_right, &gfx_left);

    while(1){
    	scanKeys();
    	keys = keysHeld();
    	if((keys & KEY_DOWN) && (screen_y < 512 - 192)){
    		screen_y+=2;
    		player_y++;
    	}
    	if((keys & KEY_UP) && (screen_y > 0)){
    		screen_y-=2;
    		player_y--;
    	}
    	if((keys & KEY_RIGHT) && (screen_x < 512 - 256 - 32)){
    		isLeft = 0;
    		screen_x++;
    		player_x++;
    	}
    	if((keys & KEY_LEFT) && (screen_x > 0)){
    		isLeft = 1;
    		screen_x--;
    		player_x--;
    	}

    	REG_BG0HOFS = screen_x;
    	REG_BG0VOFS = screen_y;
		swiWaitForVBlank();

		if(!isLeft){
			oamSet(&oamMain, 	// oam handler
				0,				// Number of sprite
				player_x, player_y,			// Coordinates
				0,				// Priority
				0,				// Palette to use
				SpriteSize_32x32,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				gfx_right,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
				);
		}
		else{
			oamSet(&oamMain, 	// oam handler
				0,				// Number of sprite
				player_x, player_y,			// Coordinates
				0,				// Priority
				0,				// Palette to use
				SpriteSize_32x32,			// Sprite size
				SpriteColorFormat_256Color,	// Color format
				gfx_left,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, false,	// Horizontal or vertical flip
				false			// Mosaic
				);
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
