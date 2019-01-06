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
#include "P_Audio.h"
#include "graphics_main.h"
#include "graphics_sub.h"
#include "game.h"
#include "timer_game.h"

// define sprite IDs
#define PLAYER_SPRITE_ID 0
#define OFFSET_MINERAL_SPRITE 1

// define the score assigned to the different minerals
#define DIAMOND_SCORE 1000
#define AMAZONITE_SCORE 500
#define BRONZE_SCORE 10
#define ALEXXZANDRITE_SCORE 5000

// specification for the minerals
#define DIAMOND_NUMBER 10
#define AMAZONITE_NUMBER 20
#define BRONZE_NUMBER 40
#define ALEXXZANDRITE_NUMBER 5
#define MINERAL_NUMBER (DIAMOND_NUMBER + AMAZONITE_NUMBER + BRONZE_NUMBER + ALEXXZANDRITE_NUMBER)

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

extern int min, sec, msec;

extern int start_pressed, score_changed, score_player;

extern Objects_coord *mineral;

#endif
