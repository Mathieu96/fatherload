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

// Initialization of the backgrounds
void init_main_background();

void configureSprites();

void setObjects();

void update_state();

void load_start_display();

void print_start();

void release_start_display();

void restart_display();

void check_alexxzandrite(int position_x, int position_y);
void check_amazonite(int position_x, int position_y);
void check_diamond(int position_x, int position_y);
void check_bronze(int position_x, int position_y);

#endif /* GRAPHICS_MAIN_H_ */
