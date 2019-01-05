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

int msec, sec, min;

void timer0_ISR(){
	if(msec < 1000)
		msec+=10;
	else{
		msec = 0;
		if(sec < 60)
			sec++;
		else{
			sec = 0;
			if(min < 60)
				min++;
			else
				min = 0;
		}
	}
}

int main(void){
	srand(time(NULL));
	mineral = (Objects_coord *) malloc(MINERAL_NUMBER * sizeof(Objects_coord));

	Audio_Init();
	Audio_PlayMusic();

	config_main_background();
//	consoleDemoInit();
	init_sub_background();
	int restart = 0;
	int start_pressed = 0;
	orientation = RIGHT;

	TIMER_DATA(0) = TIMER_FREQ(100);
	TIMER0_CR = TIMER_ENABLE | TIMER_DIV_64 | TIMER_IRQ_REQ;
	irqSet(IRQ_TIMER0, timer0_ISR);

	u16 keys;
	configureSprites();

	do{
		// set the player and screen starting coordinates
		player_x = 128;
		player_y = 112;
		screen_x = 128;
		screen_y = 0;
		mineral_count = 0;
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
		oamUpdate(&oamMain);
		// set the starting backgrounds
		init_main_bg();

		//set the objects coordinates
		setObjects();
		irqEnable(IRQ_TIMER0);
		while(1){
			scanKeys();
			touchPosition touch;
			keys = keysHeld();

			switch(keys){
			case KEY_DOWN:
				if(screen_y < 512 - 192 && !start_pressed){
					Audio_PlaySoundEX(SFX_BULLDOZER);
					orientation = DOWN;
					screen_y ++;
					if(player_y < 168)
						player_y++;
				}
				break;
			case KEY_UP:
				if(screen_y > 0  && !start_pressed){
					Audio_PlaySoundEX(SFX_BULLDOZER);
					orientation = UP;
					screen_y --;
					if(player_y > 112)
						player_y--;
				}
				break;
			case KEY_RIGHT:
				if(screen_x < 512 - 256  && !start_pressed){
					Audio_PlaySoundEX(SFX_BULLDOZER);
					orientation = RIGHT;
					screen_x++;
					if(player_x < 256-16)
						player_x++;
				}
				break;
			case KEY_LEFT:
				if(screen_x > 0  && !start_pressed){
					Audio_PlaySoundEX(SFX_BULLDOZER);
					orientation = LEFT;
					screen_x--;
					if(player_x > 0)
						player_x--;
				}
				break;

			case KEY_START:
				if(!start_pressed && !start_pressed){
					irqDisable(IRQ_TIMER0);
					mmPause();
					Audio_PlaySoundEX(SFX_TIRE_SCREECH);
					load_start_display();
					start_pressed = 1;
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
						true,			// Hide this sprite
						false, false,	// Horizontal or vertical flip
						false			// Mosaic
					);
					oamUpdate(&oamMain);
					swiDelay(15000000); // Delay to avoid going back out of start mode right after
				}
				else{
					mmResume();
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
					oamUpdate(&oamMain);
					release_start_display();
					start_pressed = 0;
					swiDelay(15000000); // Delay to avoid going back into start mode right after
					irqEnable(IRQ_TIMER0);
				}
			}
			if(!start_pressed){
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
				//swiWaitForVBlank();
				//swiWaitForVBlank();
				oamUpdate(&oamMain);
				updateChronoDisp(min, sec, msec);
				if(mineral_count == MINERAL_NUMBER)
					break;
			}
		}
	} while(1);
	return 0;
}
