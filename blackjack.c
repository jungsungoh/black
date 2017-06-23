#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "gui.h"
#include "operation.h"
#include "game.h"

void welcomeScreen();

int main() {
	int choice = 0, i, flag = 0;
	FILE *scores;
	PLAYER user[10];
	PLAYER** playerArray;
	int bet;

	playerArray = calloc(10, sizeof(PLAYER*));

	for (i = 0; i < SIZE; i++) {
		playerArray[i] = calloc(1, sizeof(PLAYER));
	}
	blackjack();
	welcomeScreen();

	scores = fopen("scores.bin", "rb");
	if (scores == NULL) {
		scores = fopen("scores.bin", "wb");

		for (i = 0; i < SIZE; i++) {
			playerArray[i]->bank = 0;
			playerArray[i]->wins = 0;
			playerArray[i]->loses = 0;
			playerArray[i]->streak = 0;
			playerArray[i]->gamesPlayed = 0;
			strcpy(playerArray[i]->name, "name");
		}
		fwrite(user, sizeof(PLAYER), 10, scores);


	}
	else
		fread(user, sizeof(PLAYER), 10, scores);

	fclose(scores);
	for (i = 0; i < SIZE; i++) {
		playerArray[i]->bank = user[i].bank;
		playerArray[i]->gamesPlayed = user[i].gamesPlayed;
		playerArray[i]->loses = user[i].loses;
		playerArray[i]->wins = user[i].wins;
		playerArray[i]->streak = user[i].streak;
		strcpy(playerArray[i]->name, user[i].name);
	}

	//getScores(playerArray);
	playerSelect(playerArray);
	do {

		choice = getChoice(playerArray);
		switch (choice) {
		case 1: //Play BlackJack

			printf("%s님 얼마를 베팅 하시겠습니까??:  ", playerArray[0]->name);
			scanf("%i", &bet); 
			fflush(stdin);

			mypause();
			system("clear");
			
			if (bet > playerArray[0]->bank) {
				printf("잔고가 충분하지 않습니다!!\n");
			}
			else { 
			flag = play();
			switch (flag) {
			case 0:
				playerArray[0]->bank = playerArray[0]->bank - bet;
				playerArray[0]->loses = (playerArray[0]->loses + 1);
				if (playerArray[0]->streak > 0) {
					playerArray[0]->streak = -1;
				}
				else {
					playerArray[0]->streak = playerArray[0]->streak - 1;
				}
				break;
			case 1:
				playerArray[0]->bank = playerArray[0]->bank + bet;
				playerArray[0]->wins = (playerArray[0]->wins + 1);
				if (playerArray[0]->streak < 0) {
					playerArray[0]->streak = 1;
				}
				else {
					playerArray[0]->streak = playerArray[0]->streak + 1;
				}
				break;
			case 3:
				printf("신기록 입니다.!!\n");
				break;
			}
			}
			mypause();
			playerArray[0]->gamesPlayed = playerArray[0]->gamesPlayed + 1;

			break;
		case 2: //Quit Message
			system("clear");
			printf("\n\tBLACKJACK을 플레이해주셔서 감사합니다!!! 다음번에 만나요.\n\n");
			saveScores(playerArray);
			break;
		default:
			printf("제대로 입력해주십시오.\n\n");
			break;
		}// End switch
	} while (choice != 2);
	mypause();
	return 0;
}//End main
