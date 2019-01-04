/*
 * graphics_main.h
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#ifndef GRAPHICS_MAIN_H_
#define GRAPHICS_MAIN_H_

#include <nds.h>
#include <string.h>
#include "FONDS.h"
#include "diamond.h"
#include "PlayerHorizontal.h"
#include "PlayerVertical.h"

// define sprite IDs
#define PLAYER_SPRITE_ID 0
#define OFFSET_DIAMOND_SPRITE 1

// specification for the diamond objects
#define DIAMOND_NUMBER 16
#define SPRITE_WIDTH 32
#define SPRITE_HEIGTH 32

typedef struct{
	int x;
	int y;
	char isTook;
	char type[20];
} Objects_coord;

typedef enum {UP, DOWN, LEFT, RIGHT} dir;

extern u16* diamond_pic;

extern u16 *gfx_horizontal, *gfx_vertical;

extern dir orientation;

extern int player_x, player_y, screen_x, screen_y;

extern int diamond_count;

extern Objects_coord mineral[DIAMOND_NUMBER];

// Initialization of the backgrounds
void init_main_background();

void configureSprites();

void setObjects();

void update_state();

#endif /* GRAPHICS_MAIN_H_ */
