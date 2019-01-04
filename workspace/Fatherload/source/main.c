/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "graphics_main.h"
#include "P_Audio.h"
#include "graphics_sub.h"

int player_x = 128; int player_y = 112; int screen_x = 128; int screen_y = 0;

int diamond_count = 0;

Objects_coord mineral[DIAMOND_NUMBER];

dir orientation;

u16 *gfx_horizontal, *gfx_vertical, *diamond_pic;

int main(void){
	srand(time(NULL));
	init_main_background();
	init_sub_background();

	orientation = RIGHT;

	u16 keys;
	configureSprites();

	setObjects();

//	Audio_Init();
//	Audio_PlayMusic();

    while(1){
    	scanKeys();
		touchPosition touch;

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
    	if(keys & KEY_TOUCH){
			touchRead(&touch);
			if(((touch.py >= 0) && (touch.py < 70)) && (touch.px >= 85) && (touch.px <= 165)){
	        	if(screen_y > 0){
	        		orientation = UP;
	    			screen_y -=3;
	    			if(player_y > 112)
	    				player_y--;
	        	}
			}
			if(((touch.py >= 120) && (touch.py < 192)) && (touch.px >= 85) && (touch.px <= 165)){
	        	if(screen_y < 512 - 192){
	        		orientation = DOWN;
	        		screen_y +=3;
	        		if(player_y < 168)
	        			player_y++;
	        	}
			}
			if(((touch.py >= 45) && (touch.py < 120)) && (touch.px >= 3) && (touch.px <= 70)){
	        	if(screen_x > 0){
	        		orientation = LEFT;
	        		screen_x--;
	        		if(player_x > 0)
	        			player_x--;
	        	}
			}
			if(((touch.py >= 45) && (touch.py < 120)) && (touch.px >= 185) && (touch.px <= 253)){
	        	if(screen_x < 512 - 256){
	        		orientation = RIGHT;
	        		screen_x++;
	        		if(player_x < 256-16)
	        			player_x++;
	        	}
			}

    	}
		swiWaitForVBlank();
		REG_BG3HOFS = screen_x;
		REG_BG3VOFS = screen_y;
		REG_BG2HOFS = screen_x;
		REG_BG2VOFS = screen_y;
		//printf("REG_BG2HOFS: %d, screen_x: %d, REG_BG2VOFS: %d, y: %d\n",REG_BG2HOFS, screen_x, REG_BG2VOFS, screen_y);

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
