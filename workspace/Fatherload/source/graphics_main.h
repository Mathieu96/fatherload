/*
 * graphics_main.h
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#ifndef GRAPHICS_MAIN_H_
#define GRAPHICS_MAIN_H_

#include <nds.h>
#include "background.h"
#include "FONDS.h"
#include "diamond.h"
#include "PlayerHorizontal.h"
#include "PlayerVertical.h"

// define sprite IDs
#define PLAYER_SPRITE_ID 0
#define OFFSET_DIAMOND_SPRITE 1

// specification for the diamond objects
#define DIAMOND_NUMBER 16
#define DIAMOND_WIDTH 32
#define DIAMOND_HEIGTH 32

typedef struct{
	int x;
	int y;
} Objects_coord;

u16* diamond_pic;

extern u16 *gfx_horizontal, *gfx_vertical;

extern int player_x, player_y, screen_x, screen_y;

extern Objects_coord diamond[DIAMOND_NUMBER];
// Initialization of the background 3, ext. rotoscale mode
void init_background2();

void configureSprites();

void setObjects();

void printDiamond();

#endif /* GRAPHICS_MAIN_H_ */
