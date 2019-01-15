/*
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#include "timer_game.h"
#include "graphics_sub.h"
#include "game.h"

int msec, sec, min, overSec;
int audioCycles = 0;
soundEffectType currentSF;

void init_timers(){
	TIMER_DATA(0) = TIMER_FREQ(100);
	TIMER0_CR = TIMER_ENABLE | TIMER_DIV_64 | TIMER_IRQ_REQ;
	irqSet(IRQ_TIMER0, timer0_ISR);

	TIMER_DATA(1) = TIMER_FREQ(60);
	TIMER1_CR = TIMER_ENABLE | TIMER_DIV_64 | TIMER_IRQ_REQ;
	irqSet(IRQ_TIMER1, timer1_ISR);
}

void restart_timer(){
	msec = 0;
	sec = 0;
	min = 0;
}

void timer0_ISR() {
	if (msec < 1000)
		msec += 10;
	else {
		msec = 0;
		if (sec < 60){
			sec++;
			if(gameOver)
				overSec++;
		}
		else {
			sec = 0;
			if (min < 60)
				min++;
			else
				min = 0;
		}
	}
	drilling = false;
}

void timer1_ISR() {
	flying = 0;
	print_fuel(20, 10, 8);

	// sound effect state machine
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
