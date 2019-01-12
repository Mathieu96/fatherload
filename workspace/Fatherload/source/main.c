/*
 * Template Nintendo DS
 * May 2011
 */

#include <fat.h>
#include <nds.h>
#include <stdbool.h>
#include "fatherload_defines.h"
#include "mineral.h"
#include "graphics_main.h"
#include "P_Audio.h"
#include "graphics_sub.h"
#include "game.h"
#include "P_Score.h"

int main(void) {
	srand(time(NULL));
	fatInitDefault();
	u16 keys;
	do {
		// set the player and screen starting coordinates
		showInitImage();
		while(1){
			swiWaitForVBlank();
			scanKeys();
			keys = keysDown();
			if((keys & KEY_START) || (keys & KEY_A) || (keys & KEY_B) ||
			   (keys & KEY_R) || (keys & KEY_L) || (keys & KEY_TOUCH) ||
			   (keys & KEY_SELECT) || (keys & KEY_UP) || (keys & KEY_DOWN) ||
			   (keys & KEY_LEFT) || (keys & KEY_RIGHT))
				break;
		}
		init_game();
		start_game();
		readMaxScore();
		while(1){
			swiWaitForVBlank();
			scanKeys();
			keys = keysHeld();

			if(keys & KEY_START)
				player_pressed_start();

			if (!start_pressed) {
				if(keys & KEY_A)
					player_drills();

				else{
					if(keys & KEY_DOWN)
						player_move_down();

					if(keys & KEY_RIGHT)
						player_move_right();

					if(keys & KEY_LEFT)
						player_move_left();

					if(keys & KEY_UP)
						player_move_up();

					if (keys & KEY_TOUCH) {
						player_pressed_touchscreen();
					}
				}

				// move the background 3 => the main background
				REG_BG3HOFS = screen_x;
				REG_BG3VOFS = screen_y;
				// move the background 2 => the digged parts
				REG_BG2HOFS = screen_x;
				REG_BG2VOFS = screen_y;

				// update the player's movements
				update_vehicle();

				// Update the drilled path
				update_state();

				if(!flying)
					player_fall();

				refreshMineralSprites();

				if (score_changed) {
					score_display(20, 5, 10, player_score);
					score_changed = 0;
				}

				oamUpdate(&oamMain);
				// Show the time since the game began
				updateChronoDisp(min, sec, msec, 11);
				// Stop the while if the player reaches the number of mineral generated
				if (mineral_count == N_TOT_MINERALS)
					break;

				if(player_fuel <= 0)
					break;

			}
			swiWaitForVBlank(); // slow down the game
		}

		if(max_score < player_score)
			writeMaxScore(player_score);

		player_fuel = 0;
		print_fuel(20, 10, 12);
		// restart part
		free(mineralMap);
		hide_all_minerals();
	} while(gameOverState());

	// Shutdown the NDS
	powerOn(PM_SYSTEM_PWR);

	return 0;
}
