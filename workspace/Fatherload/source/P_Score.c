
#include "P_Score.h"
#include <stdio.h>
#include <fat.h>

int max_score = 0;

void updateScore(int score)
{
	if(score_player < 9999999){
		score_player += score;
		if(score_player > 9999999)
			score_player = 9999999;
		score_changed = 1;
	}

	//Display the score
	score_display(16, 1, 10, score_player);

	//Update highest score
	if(score_player > max_score){
		max_score = score_player;
		writeMaxScore(max_score);
	}
}

void readMaxScore()
{
	//Open the file in read mode
	FILE* file = fopen("/Fatherloadrecord.txt","r");
	if(file != NULL)
	{
		//Read the value and put it into the variable max_score
		fscanf(file,"%i\n",&max_score);
		// close the file
		fclose(file);
	}
	score_display(16, 5, 9, max_score);
}

void writeMaxScore(int score)
{
	//Open the file in write mode to overwrite
	FILE* file = fopen("/Fatherloadrecord.txt","w+");
	if(file != NULL){
		//Print the value in the file
		fprintf(file,"%i\n",score);
		//Close the file
		fclose(file);
	}
	score_display(16, 5, 9, score);
}
