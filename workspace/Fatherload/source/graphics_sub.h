/*
 * graphics_main.h
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#ifndef GRAPHICS_SUB_H_
#define GRAPHICS_SUB_H_

#include "fatherload_defines.h"
#include "controls.h"
#include "numbers.h"
#include "numbers_small.h"

// Initialization of the backgrounds
void init_sub_background();

void printDigitChrono(int number, int x, int y);

void printDigitScore(int number, int x, int y, int pal);

void updateChronoDisp(int min, int sec, int msec, int pal);

void score_display(int x, int y, int pal, int score);

void print_fuel(int x, int y, int pal);

#endif /* GRAPHICS_MAIN_H_ */
