/*
 * graphics_main.h
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#ifndef FATHERLOAD_DEFINES_H_
#define FATHERLOAD_DEFINES_H_

#include <nds.h>
#include <string.h>

// define sprite IDs
#define PLAYER_SPRITE_ID 0
#define OFFSET_MINERAL_SPRITE 1

// specification for the diamond objects
#define DIAMOND_NUMBER 5
#define AMAZONITE_NUMBER 10
#define BRONZE_NUMBER 12
#define ALEXXZANDRITE_NUMBER 3
#define MINERAL_NUMBER 30
#define SPRITE_WIDTH 32
#define SPRITE_HEIGTH 32

typedef struct{
	int x;
	int y;
	char isTook;
	char type[20];
} Objects_coord;

typedef enum {UP, DOWN, LEFT, RIGHT} dir;

extern u16* diamond_pic, *amazonite_pic, *bronze_pic, *alexxzandrite_pic;

extern u16 *gfx_horizontal, *gfx_vertical;

extern dir orientation;

extern int player_x, player_y, screen_x, screen_y;

extern int mineral_count;

extern Objects_coord *mineral;

#endif
