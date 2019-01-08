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

// Initialization of the backgrounds
void config_main_background();

void init_main_bg();

void configureSprites();

void initMinerals();



void load_start_display();

void print_start();

void release_start_display();

void restart_display();

void hide_objects();



#endif /* GRAPHICS_MAIN_H_ */
