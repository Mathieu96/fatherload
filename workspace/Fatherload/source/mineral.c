#include "mineral.h"

bool isMineralPlaceValid(int pos_x, int pos_y, int n_mineral) {
	int i;
	for (i = 0; i < n_mineral; i++) {
		if ((((pos_y - mineral[i].y > 0) ? (pos_y - mineral[i].y) : (mineral[i].y - pos_y)) < 20)
		 && (((pos_x - mineral[i].x > 0) ? (pos_x - mineral[i].x) : (mineral[i].x - pos_x)) < 20)
		) {
			return false;
			break;
		}
	}
	return true;
}

void initMinerals(){
	int i;
	// Generate the diamonds, deep on the map
	for(i = 0; i < N_DIAMOND; i++){
		mineral[i].isDrilled = false;
		mineral[i].type = DIAMOND;
		do {
			mineral[i].x = (rand()%512);
			mineral[i].y = (rand()%(512-384-16-8)) + 384;
		} while (isMineralPlaceValid(mineral[i].x, mineral[i].y, i) == false);

	}
	// Generate the amazonite
	for(i = N_DIAMOND; i < N_DIAMOND + N_AMAZONITE; i++){
		mineral[i].isDrilled = false;
		mineral[i].type = AMAZONITE;
		do {
			mineral[i].x = (rand()%512);
			mineral[i].y = (rand()%(512-256-16-8))+ 256;
		} while (isMineralPlaceValid(mineral[i].x, mineral[i].y, i) == false);

	}
	// Generate the bronzes
	for(i = N_DIAMOND + N_AMAZONITE; i < N_DIAMOND + N_AMAZONITE + N_BRONZE; i++){
		mineral[i].isDrilled = false;
		mineral[i].type = BRONZE;
		do {
			mineral[i].x = (rand()%512);
			mineral[i].y = (rand()%(512-128-16-8)) + 128;
		} while (isMineralPlaceValid(mineral[i].x, mineral[i].y, i) == false);

	}
	// Generate the alexxzandrites
	for(i = N_DIAMOND + N_AMAZONITE + N_BRONZE; i < N_TOT_MINERALS; i++){
		mineral[i].isDrilled = false;
		mineral[i].type = ALEXXZANDRITE;
		do {
			mineral[i].x = (rand()%512);
			mineral[i].y = (rand()%(512-384-16-8))+ 384;
		} while (isMineralPlaceValid(mineral[i].x, mineral[i].y, i) == false);

	}
}

Mineral * getMineral(int pos_x, int pos_y) {
	int i;
	for (i = 0; i < N_TOT_MINERALS; i++) {
		if ((((pos_y - mineral[i].y > 0) ? (pos_y - mineral[i].y):(mineral[i].y - pos_y)) < 16) // abs(diamond.y - pos_y) < 16
		 && (((pos_x - mineral[i].x > 0) ? (pos_x - mineral[i].x):(mineral[i].x - pos_x)) < 16) // abs(diamond.x - pos_x) < 16
		) {
			return &mineral[i];
			break;
		}
	}
	return NULL;
}

void hide_all_minerals(){
	int i;
	for(i = 0; i < N_TOT_MINERALS; i++){
		if(!mineral[i].isDrilled){
			//update_sprite(u16* gfx, int spriteID, int hide, int paletteNum, int x, int y)
			update_sprite(NULL, OFFSET_MINERAL_SPRITE + i,
				1, 0, 0, 0, mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
}

void refreshMineralSprites() {
	int i;
	for(i = 0; i < N_DIAMOND; i++){
		if(((mineral[i].x > - 16) 		   && (mineral[i].x < screen_x + 256)) &&
		   ((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){
			update_sprite(diamond_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, DIAMOND_PAL,0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
	for(i = N_DIAMOND; i < N_DIAMOND + N_AMAZONITE; i++){
		if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
			((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){
			update_sprite(amazonite_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, AMAZONITE_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
	for(i = N_DIAMOND + N_AMAZONITE; i < N_DIAMOND + N_AMAZONITE + N_BRONZE; i++){
		if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
			((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){
			update_sprite(bronze_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, BRONZE_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
	for(i = N_DIAMOND + N_AMAZONITE + N_BRONZE; i < N_TOT_MINERALS; i++){
		if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
			((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){
				update_sprite(alexxzandrite_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, ALEXX_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
}




void check_diamond(int position_x, int position_y){
	int i;
	for(i = 0; i < N_DIAMOND; i++){
		if(!mineral[i].isDrilled && (
		   (((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) // abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			if(score_player < 999999){
				score_player += SCORE_DIAMONDS;
				if(score_player > 999999)
					score_player = 999999;
				score_changed = 1;
			}
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isDrilled = true;
			update_sprite(diamond_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, DIAMOND_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}

		if(((mineral[i].x > - 16) 		   && (mineral[i].x < screen_x + 256)) &&
		   ((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){
			update_sprite(diamond_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, DIAMOND_PAL,0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
}

void check_amazonite(int position_x, int position_y){
	int i;
	for(i = N_DIAMOND; i < N_DIAMOND + N_AMAZONITE; i++){
		if(!mineral[i].isDrilled && (
		(((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) //abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			if(score_player < 999999){
				score_player += SCORE_AMAZONITE;
				if(score_player > 999999)
					score_player = 999999;
				score_changed = 1;
			}
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isDrilled = true;
			//update_sprite(u16* gfx, int spriteID, int hide, int paletteNum, int x, int y)
			update_sprite(amazonite_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, AMAZONITE_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}

		if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
				((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){

			update_sprite(amazonite_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, AMAZONITE_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
}

void check_bronze(int position_x, int position_y){
	int i;
	for(i = N_DIAMOND + N_AMAZONITE; i < N_DIAMOND + N_AMAZONITE + N_BRONZE; i++){
		if(!mineral[i].isDrilled && (
		(((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) //abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			if(score_player < 999999){
				score_player += SCORE_BRONZE;
				if(score_player > 999999)
					score_player = 999999;
				score_changed = 1;
			}
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isDrilled = true;

			update_sprite(bronze_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, BRONZE_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);

		}

		if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
				((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){

			update_sprite(bronze_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, BRONZE_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
}

void check_alexxzandrite(int position_x, int position_y){
	int i;
	for(i = N_DIAMOND + N_AMAZONITE + N_BRONZE;
		i < N_DIAMOND + N_AMAZONITE + N_BRONZE + N_ALEXXZANDRITE; i++){
		if(!mineral[i].isDrilled && (
		(((position_y - mineral[i].y > 0) ? (position_y - mineral[i].y):(mineral[i].y - position_y)) < 16) //abs(diamond.y - position_y) < 16
		&& (((position_x - mineral[i].x > 0) ? (position_x - mineral[i].x):(mineral[i].x - position_x)) < 16) // abs(diamond.x - position_x) < 16
		)){
			mineral_count++;
			if(score_player < 999999){
				score_player += SCORE_ALEXANDRITE;
				if(score_player > 999999)
					score_player = 999999;
				score_changed = 1;
			}
			Audio_PlaySoundEX(SFX_COIN_PICKUP);
			mineral[i].isDrilled = true;

			update_sprite(alexxzandrite_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, ALEXX_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}

		if(((mineral[i].x >  - 16) && (mineral[i].x < screen_x + 256)) &&
				((mineral[i].y > screen_y - 16) && (mineral[i].y < screen_y + 192))){

			update_sprite(alexxzandrite_pic, OFFSET_MINERAL_SPRITE + i,
						  mineral[i].isDrilled, ALEXX_PAL, 0, 0,
						  mineral[i].x - screen_x, mineral[i].y - screen_y);
		}
	}
}
