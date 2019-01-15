/*
 * graphics_main.h
 *
 *  Created on: Dec 11, 2018
 *      Author: nds
 */

#ifndef GRAPHICS_MAIN_H_
#define GRAPHICS_MAIN_H_

#include "fatherload_defines.h"
#include "FONDS.h"
#include "diamond.h"
#include "PlayerHorizontal.h"
#include "PlayerVertical.h"
#include "amazonite.h"
#include "bronze.h"
#include "alexxzandrite.h"
#include "Game-Over.h"
#include "launcherImage.h"
#include "game_over2.h"

void showInitImage();

// Initialization of the backgrounds
void config_main_background();

void init_main_bg();

void configureSprites();

void load_start_display();

void print_start();

void release_start_display();

void restart_display();

void update_sprite(u16* gfx, int spriteID, int hide, int paletteNum, int hFlip, int vFlip, int x, int y);

void drilling_path(int base, int x, int y);

#endif /* GRAPHICS_MAIN_H_ */
