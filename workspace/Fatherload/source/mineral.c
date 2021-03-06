#include "mineral.h"

bool isMineralPlaceValid(int pos_x, int pos_y, int n_mineral) {
	int i;
	for (i = 0; i < n_mineral; i++) {
		if ((((pos_y - mineralMap[i].y > 0) ? (pos_y - mineralMap[i].y) : (mineralMap[i].y - pos_y)) < 20)
		 && (((pos_x - mineralMap[i].x > 0) ? (pos_x - mineralMap[i].x) : (mineralMap[i].x - pos_x)) < 20)) {
			return false;
		}
	}
	return true;
}

void initMinerals() {
	mineralMap = (Mineral *) malloc(N_TOT_MINERALS * sizeof(Mineral));
	int i;
	// Generate the diamonds, deep on the map
	for (i = 0; i < N_DIAMOND; i++) {
		mineralMap[i].isDrilled = false;
		mineralMap[i].type = DIAMOND;
		mineralMap[i].n = i;
		do {
			mineralMap[i].x = (rand() % 512 - 32) + 16;
			mineralMap[i].y = (rand() % (512 - 384 - 16 - 8)) + 384;
		} while (!(isMineralPlaceValid(mineralMap[i].x, mineralMap[i].y, i)));

	}
	// Generate the amazonite
	for (i = N_DIAMOND; i < N_DIAMOND + N_AMAZONITE; i++) {
		mineralMap[i].isDrilled = false;
		mineralMap[i].type = AMAZONITE;
		mineralMap[i].n = i;
		do {
			mineralMap[i].x = (rand() % 512 - 16);
			mineralMap[i].y = (rand() % (512 - 256 - 16 - 8)) + 256;
		} while (!(isMineralPlaceValid(mineralMap[i].x, mineralMap[i].y, i)));

	}
	// Generate the bronzes
	for (i = N_DIAMOND + N_AMAZONITE; i < N_DIAMOND + N_AMAZONITE + N_BRONZE; i++) {
		mineralMap[i].isDrilled = false;
		mineralMap[i].type = BRONZE;
		mineralMap[i].n = i;
		do {
			mineralMap[i].x = (rand() % 512 - 16);
			mineralMap[i].y = (rand() % (512 - 128 - 16 - 8)) + 128;
		} while (!(isMineralPlaceValid(mineralMap[i].x, mineralMap[i].y, i)));

	}
	// Generate the alexxzandrites
	for (i = N_DIAMOND + N_AMAZONITE + N_BRONZE; i < N_TOT_MINERALS; i++) {
		mineralMap[i].isDrilled = false;
		mineralMap[i].type = ALEXXZANDRITE;
		mineralMap[i].n = i;
		do {
			mineralMap[i].x = (rand() % 512 - 16);
			mineralMap[i].y = (rand() % (512 - 384 - 16 - 8)) + 384;
		} while (!(isMineralPlaceValid(mineralMap[i].x, mineralMap[i].y, i)));
	}
}

void hide_all_minerals() {
	int i;
	for (i = 0; i < N_TOT_MINERALS; i++) {
		if (!mineralMap[i].isDrilled) {
			update_sprite(NULL, OFFSET_MINERAL_SPRITE + i, 1, 0, 0, 0, mineralMap[i].x - screen_x, mineralMap[i].y - screen_y);
		}
	}
}

Mineral * getMineral(int pos_x, int pos_y) {
	int i;
	for (i = 0; i < N_TOT_MINERALS; i++) {
		if ((((pos_y - mineralMap[i].y > 0) ? (pos_y - mineralMap[i].y) : (mineralMap[i].y - pos_y)) < 16) // abs(diamond.y - pos_y) < 16
		 && (((pos_x - mineralMap[i].x > 0) ? (pos_x - mineralMap[i].x) : (mineralMap[i].x - pos_x)) < 16) // abs(diamond.x - pos_x) < 16
		) {
			return &mineralMap[i];
		}
	}
	return NULL;
}

mineralType drillMineralReturnValue(int pos_x, int pos_y) {
	Mineral *mineral = getMineral(pos_x, pos_y);
	if (mineral == NULL || mineral->isDrilled) {
		return DIRT;
	} else {
		mineral_count++;
		int i = mineral->n;
		switch (mineral->type) {
		case DIAMOND:
			mineralMap[i].isDrilled = true;
			mineralMap[i].type = DRILLED;
			update_sprite(diamond_pic, OFFSET_MINERAL_SPRITE + i, mineralMap[i].isDrilled, DIAMOND_PAL, 0, 0, mineralMap[i].x - screen_x, mineralMap[i].y - screen_y);
			return DIAMOND;

		case AMAZONITE:
			mineralMap[i].isDrilled = true;
			mineralMap[i].type = DRILLED;
			update_sprite(amazonite_pic, OFFSET_MINERAL_SPRITE + i, mineralMap[i].isDrilled, AMAZONITE_PAL, 0, 0, mineralMap[i].x - screen_x, mineralMap[i].y - screen_y);
			return AMAZONITE;

		case BRONZE:
			mineralMap[i].isDrilled = true;
			mineralMap[i].type = DRILLED;
			update_sprite(bronze_pic, OFFSET_MINERAL_SPRITE + i, mineralMap[i].isDrilled, BRONZE_PAL, 0, 0, mineralMap[i].x - screen_x, mineralMap[i].y - screen_y);
			return BRONZE;

		case ALEXXZANDRITE:
			mineralMap[i].isDrilled = true;
			mineralMap[i].type = DRILLED;
			update_sprite(alexxzandrite_pic, OFFSET_MINERAL_SPRITE + i, mineralMap[i].isDrilled, ALEXX_PAL, 0, 0, mineralMap[i].x - screen_x, mineralMap[i].y - screen_y);
			return ALEXXZANDRITE;

		default: // DIRT or DRILLED
			return DRILLED;
		}
	}
}

void refreshMineralSprites() {
	int i;
	for (i = 0; i < N_DIAMOND; i++) {
		if (((mineralMap[i].x > -16)		   && (mineralMap[i].x < screen_x + 256))
		 && ((mineralMap[i].y > screen_y - 16) && (mineralMap[i].y < screen_y + 192))) {
			update_sprite(diamond_pic, OFFSET_MINERAL_SPRITE + i, mineralMap[i].isDrilled, DIAMOND_PAL, 0, 0, mineralMap[i].x - screen_x, mineralMap[i].y - screen_y);
		}
	}
	for (i = N_DIAMOND; i < N_DIAMOND + N_AMAZONITE; i++) {
		if (((mineralMap[i].x > -16) 		   && (mineralMap[i].x < screen_x + 256))
		 && ((mineralMap[i].y > screen_y - 16) && (mineralMap[i].y < screen_y + 192))) {
			update_sprite(amazonite_pic, OFFSET_MINERAL_SPRITE + i, mineralMap[i].isDrilled, AMAZONITE_PAL, 0, 0, mineralMap[i].x - screen_x, mineralMap[i].y - screen_y);
		}
	}
	for (i = N_DIAMOND + N_AMAZONITE; i < N_DIAMOND + N_AMAZONITE + N_BRONZE; i++) {
		if (((mineralMap[i].x > -16) 		   && (mineralMap[i].x < screen_x + 256))
		 && ((mineralMap[i].y > screen_y - 16) && (mineralMap[i].y < screen_y + 192))) {
			update_sprite(bronze_pic, OFFSET_MINERAL_SPRITE + i, mineralMap[i].isDrilled, BRONZE_PAL, 0, 0, mineralMap[i].x - screen_x, mineralMap[i].y - screen_y);
		}
	}
	for (i = N_DIAMOND + N_AMAZONITE + N_BRONZE; i < N_TOT_MINERALS; i++) {
		if (((mineralMap[i].x > -16) 		   && (mineralMap[i].x < screen_x + 256))
		 && ((mineralMap[i].y > screen_y - 16) && (mineralMap[i].y < screen_y + 192))) {
			update_sprite(alexxzandrite_pic, OFFSET_MINERAL_SPRITE + i,
					mineralMap[i].isDrilled, ALEXX_PAL, 0, 0, mineralMap[i].x
							- screen_x, mineralMap[i].y - screen_y);
		}
	}
}
