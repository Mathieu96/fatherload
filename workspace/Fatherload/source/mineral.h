#ifndef MINERAL_H_
#define MINERAL_H_

#include "fatherload_defines.h"

void initMinerals();

void hide_all_minerals();

//Mineral * getMineral(int pos_x, int pos_y);

mineralType drillMineralReturnValue(int pos_x, int pos_y);

//void check_alexxzandrite(int position_x, int position_y);
//
//void check_amazonite(int position_x, int position_y);
//
//void check_diamond(int position_x, int position_y);
//
//void check_bronze(int position_x, int position_y);

#endif
