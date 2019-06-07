/*
 * graphics_sub.h
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#ifndef GRAPHICS_SUB_H_
#define GRAPHICS_SUB_H_

#include "fatherload_defines.h"
#include "controls.h"
#include "numbers_small.h"
#include "press_to_begin.h"
#include "game_over_sub.h"
#include "store_sub_display_sell.h"
#include "store_sub_display_buy.h"

// Initialization of the backgrounds
void init_sub_background();

void printDigit(int number, int x, int y, int pal, int base);

void updateChronoDisp(int min, int sec, int msec, int pal, int base, int isGameOver);

void score_display(int x, int y, int pal, int score, int base);

void print_fuel(int x, int y, int pal);

void GameOver_sub_display();

void starting_sub_display();

void print_drill_health(int x, int y, int pal);

void store_sub_display_sell();

void store_sub_display_buy();

void price_display(int x, int y, int pal, int score, int base);

void game_sub_resume();

#endif /* GRAPHICS_MAIN_H_ */
