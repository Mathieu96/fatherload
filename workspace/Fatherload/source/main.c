/*
 * Template Nintendo DS
 * May 2011
 */

#include "fatherload_defines.h"
#include "graphics_main.h"
#include "P_Audio.h"
#include "graphics_sub.h"

int player_x = 128; int player_y = 112; int screen_x = 128; int screen_y = 0;

int mineral_count = 0;

Objects_coord *mineral;

dir orientation;

u16 *gfx_horizontal, *gfx_vertical, *diamond_pic, *amazonite_pic, *bronze_pic, *alexxzandrite_pic;

int main(void){
	srand(time(NULL));
	mineral = (Objects_coord *) malloc(MINERAL_NUMBER * sizeof(Objects_coord));

	Audio_Init();
	Audio_PlayMusic();

	init_main_background();
	consoleDemoInit();
//	init_sub_background();
	int restart = 0;
	int start_pressed = 0;
	orientation = RIGHT;

	u16 keys;
	configureSprites();

	setObjects();

	do{
		while(1){
			scanKeys();
			touchPosition touch;
			keys = keysHeld();
			if(start_pressed){
				if(keys&KEY_START){
					mmResume();
					start_pressed = 0;
					release_start_display();
				}
				else{
					swiWaitForVBlank();
					continue;
				}
			}
			switch(keys){
			case KEY_DOWN:
				if(screen_y < 512 - 192){
					Audio_PlaySoundEX(SFX_BULLDOZER);
					orientation = DOWN;
					screen_y +=3;
					if(player_y < 168)
						player_y++;
				}
				break;
			case KEY_UP:
				if(screen_y > 0){
					Audio_PlaySoundEX(SFX_BULLDOZER);
					orientation = UP;
					screen_y -=3;
					if(player_y > 112)
						player_y--;
				}
				break;
			case KEY_RIGHT:
				if(screen_x < 512 - 256){
					Audio_PlaySoundEX(SFX_BULLDOZER);
					orientation = RIGHT;
					screen_x++;
					if(player_x < 256-16)
						player_x++;
				}
				break;
			case KEY_LEFT:
				if(screen_x > 0){
					Audio_PlaySoundEX(SFX_BULLDOZER);
					orientation = LEFT;
					screen_x--;
					if(player_x > 0)
						player_x--;
				}
				break;

			case KEY_START:
				if(!start_pressed){
					mmPause();
					Audio_PlaySoundEX(SFX_TIRE_SCREECH);
					load_start_display();
					start_pressed = 1;
				}
			}

			if(keys & KEY_TOUCH){
				touchRead(&touch);
				if(((touch.py >= 0) && (touch.py < 50)) && (touch.px >= 45) && (touch.px <= 85)){
					if(screen_y > 0){
						Audio_PlaySoundEX(SFX_BULLDOZER);
						orientation = UP;
						screen_y -=3;
						if(player_y > 112)
							player_y--;
					}
				}
				if(((touch.py >= 75) && (touch.py <= 128)) && (touch.px >= 45) && (touch.px <= 85)){
					if(screen_y < 512 - 192){
						Audio_PlaySoundEX(SFX_BULLDOZER);
						orientation = DOWN;
						screen_y +=3;
						if(player_y < 168)
							player_y++;
					}
				}
				if(((touch.py >= 30) && (touch.py < 90)) && (touch.px >= 2) && (touch.px <= 37)){
					if(screen_x > 0){
						Audio_PlaySoundEX(SFX_BULLDOZER);
						orientation = LEFT;
						screen_x--;
						if(player_x > 0)
							player_x--;
					}
				}
				if(((touch.py >= 30) && (touch.py < 90)) && (touch.px >= 90) && (touch.px <= 128)){
					if(screen_x < 512 - 256){
						Audio_PlaySoundEX(SFX_BULLDOZER);
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
			swiWaitForVBlank();
			swiWaitForVBlank();
			swiWaitForVBlank();
			oamUpdate(&oamMain);
			if(mineral_count == MINERAL_NUMBER)
				break;
		}

	} while(restart);
	return 0;
}
