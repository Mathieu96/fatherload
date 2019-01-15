/*
 * Template Nintendo DS
 * May 2011
 */

#include "game.h"

int main(void) {
	srand(time(NULL));
	fatInitDefault();
	u16 keys;
	do {
		// Send to the starting game state
		starting_game_screen();

		// Initialize the game
		init_game();
		// Set all the variables to the starting step
		start_game();
		// Reads the previous maximum score and prints it (0 if no previous score)
		readMaxScore();
		while(1){
			swiWaitForVBlank();

			// The update_game function returns 0 if the game is ended
			if(update_game() == 0)
				break;

			swiWaitForVBlank(); // slow down the game
		}
	} while(gameOverState());
	irqDisable(IRQ_TIMER0);
	// Shutdown the NDS
	powerOn(PM_SYSTEM_PWR);

	return 0;
}
