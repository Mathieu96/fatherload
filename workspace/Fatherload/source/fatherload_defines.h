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
#include <stdbool.h>
#include "P_Audio.h"
#include "graphics_main.h"
#include "graphics_sub.h"
#include "game.h"
#include "timer_game.h"


// define sprite IDs
#define PLAYER_SPRITE_ID 0
#define OFFSET_MINERAL_SPRITE 1

// define the score assigned to the different minerals
#define SCORE_DIAMONDS 1000
#define SCORE_AMAZONITE 500
#define SCORE_BRONZE 10
#define SCORE_ALEXANDRITE 5000

// specification for the minerals
#define N_DIAMOND 10
#define N_AMAZONITE 20
#define N_BRONZE 40
#define N_ALEXXZANDRITE 5
#define N_TOT_MINERALS (N_DIAMOND + N_AMAZONITE + N_BRONZE + N_ALEXXZANDRITE)

// palettes numbers
#define PLAYER_HPAL 0
#define PLAYER_VPAL 1
#define DIAMOND_PAL 2
#define AMAZONITE_PAL 3
#define BRONZE_PAL 4
#define ALEXX_PAL 5

#define SPRITE_WIDTH 32
#define SPRITE_HEIGTH 32

typedef enum {DIRT, DRILLED, DIAMOND, AMAZONITE, BRONZE, ALEXXZANDRITE} mineralType;

typedef struct{
	int x;
	int y;
	bool isDrilled;
	mineralType type;
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
