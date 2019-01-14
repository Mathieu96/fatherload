/*
 * graphics_main.h
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#ifndef TIMER_GAME_H_
#define TIMER_GAME_H_

#include "fatherload_defines.h"

void init_timers();

void restart_timer();

void timer0_ISR();

void timer1_ISR();

#endif /* GRAPHICS_MAIN_H_ */
