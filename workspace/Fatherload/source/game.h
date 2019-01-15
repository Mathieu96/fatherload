/*
 * game.h
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#ifndef GAME_H_
#define GAME_H_

#include <fat.h>
#include <nds.h>
#include <stdbool.h>
#include "fatherload_defines.h"
#include "mineral.h"
#include "timer_game.h"
#include "P_Score.h"
#include "P_Audio.h"

void starting_game_screen();

int update_game();

void init_game();

void start_game();

void update_state();

void player_move_right();

void player_move_left();

void player_move_down();

void player_move_up();

void player_drills();

void player_pressed_start();

void player_pressed_touchscreen();

void update_vehicle();

void player_fall();

int gameOverState();

#endif /* GRAPHICS_MAIN_H_ */
