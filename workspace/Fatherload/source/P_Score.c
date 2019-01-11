
#include "P_Score.h"
#include <stdio.h>
#include <fat.h>

int max_score = 0;

void updateScore(int score)
{
	if(player_score < 9999999){
		player_score += score;
		if(player_score > 9999999)
			player_score = 9999999;
		score_changed = 1;
	}

	//Display the score
	score_display(20, 1, 10, player_score);
	//Update highest score
	if(player_score > max_score){
		score_display(20, 5, 9, player_score);
	}
}

void readMaxScore(){
	//Open the file in read mode
	FILE* file = fopen("/record.txt","r");
	if(file != NULL)
	{
		//Read the value and put it into the variable max_score
		fscanf(file,"%i\n",&max_score);
		// close the file
		fclose(file);
		printf("%d\n", max_score);
	}
	score_display(20, 5, 9, max_score);
}

void writeMaxScore(int score)
{
	//Open the file in write mode to overwrite
	FILE* file = fopen("/record.txt","w+");
	if(file != NULL){
		//Print the value in the file
		fprintf(file,"%i\n",score);
		//Close the file
		fclose(file);
	}
}
