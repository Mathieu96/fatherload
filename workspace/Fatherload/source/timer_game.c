/*
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "timer_game.h"
#include "graphics_sub.h"

int msec, sec, min;

void timer0_ISR() {
	if (msec < 1000)
		msec += 10;
	else {
		msec = 0;
		if (sec < 60)
			sec++;
		else {
			sec = 0;
			if (min < 60)
				min++;
			else
				min = 0;
		}
	}
}

void timer1_ISR() {
	flying = 0;
	print_fuel(18, 10, 12);
}
