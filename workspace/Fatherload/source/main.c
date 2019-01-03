/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "graphics_main.h"
#include "P_Audio.h"

int player_x = 128; int player_y = 112; int screen_x = 128; int screen_y = 0;

int diamond_id[DIAMOND_NUMBER];

Objects_coord diamond[DIAMOND_NUMBER];

dir orientation;

u16 *gfx_horizontal, *gfx_vertical, *diamond_pic;

int main(void){
	init_main_background();

	orientation = RIGHT;

	u16 keys;
	configureSprites();

	setObjects();

//	Audio_Init();
//	Audio_PlayMusic();

	consoleDemoInit();

    while(1){
    	scanKeys();
    	keys = keysHeld();
    	switch(keys){
    	case KEY_DOWN:
        	if(screen_y < 512 - 192){
        		orientation = DOWN;
        		screen_y +=3;
        		if(player_y < 168)
        			player_y++;
        	}
        	break;
    	case KEY_UP:
        	if(screen_y > 0){
        		orientation = UP;
    			screen_y -=3;
    			if(player_y > 112)
    				player_y--;
        	}
        	break;
    	case KEY_RIGHT:
        	if(screen_x < 512 - 256){
        		orientation = RIGHT;
        		screen_x++;
        		if(player_x < 256-16)
        			player_x++;
        	}
        	break;
    	case KEY_LEFT:
        	if(screen_x > 0){
        		orientation = LEFT;
        		screen_x--;
        		if(player_x > 0)
        			player_x--;
        	}
        	break;
    	}
    	/*
    	if((keys & KEY_DOWN) && (screen_y < 512 - 192)){
    		orientation = DOWN;
    		screen_y +=3;
    		if(player_y < 152)
    			player_y++;
    	}
    	if((keys & KEY_UP) && (screen_y > 0)){
    		orientation = UP;
			screen_y -=3;
			if(player_y > 96)
				player_y--;
    	}
    	if((keys & KEY_RIGHT) && (screen_x < 512 - 256 - 32)){
    		orientation = RIGHT;
    		screen_x++;
    		player_x++;
    	}
    	if((keys & KEY_LEFT) && (screen_x > 0)){
    		orientation = LEFT;
    		screen_x--;
    		player_x--;
    	}
    	*/
		swiWaitForVBlank();
		REG_BG2HOFS = screen_x;
		REG_BG2VOFS = screen_y;
		REG_BG0HOFS = screen_x;
		REG_BG0VOFS = screen_y;

		switch(orientation){
		case RIGHT:
			oamSet(&oamMain, 	// oam handler
				PLAYER_SPRITE_ID,				// Number of sprite
				player_x, player_y,			// Coordinates
				0,				// Priority
				0,				// Palette to use
				SpriteSize_16x16,			// Sprite size
				SpriteColorFormat_16Color,	// Color format
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
				SpriteSize_16x16,			// Sprite size
				SpriteColorFormat_16Color,	// Color format
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
				1,				// Palette to use
				SpriteSize_16x16,			// Sprite size
				SpriteColorFormat_16Color,	// Color format
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
				1,				// Palette to use
				SpriteSize_16x16,			// Sprite size
				SpriteColorFormat_16Color,	// Color format
				gfx_vertical,			// Loaded graphic to display
				-1,				// Affine rotation to use (-1 none)
				false,			// Double size if rotating
				false,			// Hide this sprite
				false, true,	// Horizontal or vertical flip
				false			// Mosaic
				);
			break;
		}

		update_state();

		oamUpdate(&oamMain);
    }
}
