/*
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "timer_game.h"
#include "graphics_sub.h"
#include "game.h"

int msec, sec, min;
int audioCycles = 0;
soundEffectType currentSF;

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

	if (audioCycles == 0 && nextSF != NONE) {
		currentSF = nextSF;
		nextSF = NONE;
	}

	switch (currentSF){
	case COIN:
		Audio_PlaySoundEX(SFX_COIN_PICKUP);
		audioCycles = 10;
		currentSF = NONE;
		break;
	case DRILL:
		Audio_PlaySoundEX(SFX_BULLDOZER);
		audioCycles = 10;
		currentSF = NONE;
		break;
	default:
		if (audioCycles != 0)
			audioCycles--;
		break;
	}


}
