/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include "graphics_main.h"
#include "ball.h"

u16* gfx;

void configureSprites() {
	//Set up memory bank to work in sprite mode (offset since we are using VRAM A for backgrounds)
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;

	//Initialize sprite manager and the engine
	oamInit(&oamMain, SpriteMapping_1D_32, false);

	//Allocate space for the graphic to show in the sprite
	gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

	//Copy data for the graphic (palette and bitmap)
	swiCopy(ballPal, SPRITE_PALETTE, ballPalLen/2);
	swiCopy(ballTiles, gfx, ballTilesLen/2);
}


int main(void) {
	init_background3();
	int x = 0; int y = 0;
	u16 keys;
	configureSprites();

    while(1){
    	scanKeys();
    	keys = keysHeld();
    	if((keys & KEY_DOWN) && (y < 512 - 192 - 32))
    		y++;
    	if((keys & KEY_UP) && (y > 0))
    		y--;
    	if((keys & KEY_RIGHT) && (x < 512 - 256 - 32))
    		x++;
    	if((keys & KEY_LEFT) && (x > 0))
    		x--;

    	oamSet(&oamMain, 	// oam handler
    		0,				// Number of sprite
    		x, y,			// Coordinates
    		0,				// Priority
    		0,				// Palette to use
    		SpriteSize_32x32,			// Sprite size
    		SpriteColorFormat_256Color,	// Color format
    		gfx,			// Loaded graphic to display
    		-1,				// Affine rotation to use (-1 none)
    		false,			// Double size if rotating
    		false,			// Hide this sprite
    		false, false,	// Horizontal or vertical flip
    		false			// Mosaic
    		);
    	REG_BG0HOFS = x;
    	REG_BG0VOFS = y;
		oamUpdate(&oamMain);
		swiWaitForVBlank();
		//shifting horizontally from left to right
/*		for(i=0; i<=512-256; i++){
			swiWaitForVBlank();
			REG_BG0HOFS = i;
		}
		//shifting vertically from up to down
		for(i=0; i<=512-192; i++){
			swiWaitForVBlank();
			REG_BG0VOFS = i;
		}
		//shifting horizontally from right to left
		for(i=512-256; i>=0; i--){
			swiWaitForVBlank();
			REG_BG0HOFS = i;
		}
		//shifting vertically from down to up
		for(i=512-192; i>=0; i--){
			swiWaitForVBlank();
			REG_BG0VOFS = i;
		}
*/
    }
}