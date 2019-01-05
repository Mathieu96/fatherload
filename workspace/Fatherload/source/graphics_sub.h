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
#include "graphics_main.h"
#include "numbers.h"

// Initialization of the backgrounds
void init_sub_background();

void printDigit(int number, int x, int y);

void updateChronoDisp(int min, int sec, int msec);

#endif /* GRAPHICS_MAIN_H_ */
