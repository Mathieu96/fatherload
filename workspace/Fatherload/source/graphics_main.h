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
#include "PlayerRight.h"
#include "PlayerLeft.h"
#include "PlayerRight-ConvertImage.h"
#include "PlayerLeft-ConvertImage.h"

#define DIAMOND_NUMBER 16

typedef struct{
	int x;
	int y;
} Objects_coord;

// Initialization of the background 3, ext. rotoscale mode
void init_background3();

void configureSprites(u16 **gfx1, u16 **gfx2);

void setObjects(Objects_coord **diamond);

#endif /* GRAPHICS_MAIN_H_ */
