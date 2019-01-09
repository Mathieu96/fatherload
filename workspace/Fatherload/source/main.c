/*
 * Template Nintendo DS
 * May 2011
 */

#include <stdbool.h>
#include "fatherload_defines.h"
#include "mineral.h"
#include "graphics_main.h"
#include "P_Audio.h"
#include "graphics_sub.h"
#include "game.h"

int main(void) {
	srand(time(NULL));
	init_game();
	u16 keys;

	do {
		// set the player and screen starting coordinates
		start_game();
		while (1) {
			swiWaitForVBlank();
			scanKeys();
			keys = keysHeld();
			switch (keys) {
			case KEY_DOWN:
				player_move_down();
				break;
			case KEY_UP:
				player_move_up();
				break;
			case KEY_RIGHT:
				player_move_right();
				break;
			case KEY_LEFT:
				player_move_left();
				break;
			case KEY_A:
				player_drills();
				break;
			case KEY_START:
				player_pressed_start();
				break;
			}

			if (!start_pressed) {
				if (keys & KEY_TOUCH) {
					player_pressed_touchscreen();
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

				refreshMineralSprites();

				if (score_changed) {
					update_scoreboard();
				}

				oamUpdate(&oamMain);
				// Show the time since the game began
				updateChronoDisp(min, sec, msec);
				// Stop the while if the player reaches the number of mineral generated
				if (mineral_count == N_TOT_MINERALS)
					break;
			}
			swiWaitForVBlank(); // slow down the game
		}
	} while (1);
	return 0;
}
