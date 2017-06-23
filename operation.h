#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
	char name[50];
	double bank;
	int wins;
	int loses;
	int streak;
	int gamesPlayed;
}PLAYER;

void mypause(void);
void displayPlayerList(PLAYER*[]);
void getScores();
void shifter(PLAYER**, int);

void mypause(void)
{
	printf("넘어가려면 Enter를 눌러주세요!\n");
	fflush(stdout);
	getchar();
}

void displayMenu(PLAYER* playerArray[]) {
	system("clear");
	printf("\n\n");
	printf("\t ... B   L    A    C    K   J  A   C   K ...\n ");
	printf("\t============================================\n");
	printf("\t================= M E N U ==================\n");
	printf("\t1).              게임 시작                  \n");
	printf("\t2).              게임 종료                   \n");
	printf("\t============================================\n");
	printf("\t===========================================\n\n");
	printf("\t안녕하세요 %s님\t 당신의 잔고는:%.2f만원입니다\n", playerArray[0]->name, playerArray[0]->bank);
	printf("\n\n1번 또는 2번을 선택해주세요: ");
}//End displayMenu function

int getChoice(PLAYER* p[]) {
	int result;
	displayMenu(p);
	scanf("%i", &result); 
	fflush(stdin);
	return result;
}//End getChoice function

void getScores(PLAYER* *user) {
	FILE *scores;

	int i;


	scores = fopen("scores.bin", "rb");
	if (scores == NULL) {
		scores = fopen("scores.bin", "wb");

		for (i = 0; i < 10; i++) {
			user[i]->bank = 0;
			user[i]->wins = 0;
			user[i]->loses = 0;
			user[i]->streak = 0;
			user[i]->gamesPlayed = 0;
			strcpy(user[i]->name, "");
		} //end for
		fwrite(&user, sizeof(PLAYER), 10, scores);
	}
	else
		fread(&user, sizeof(PLAYER), 10, scores);
	fclose(scores);

	scores = fopen("scores.bin", "wb");
	fwrite(&user, sizeof(PLAYER), 10, scores);
	fclose(scores);
} // end getScores

void saveScores(PLAYER* *user) {
	FILE *scores;
	PLAYER tempUser[10];
	int i;

	for (i = 0; i< SIZE; i++) {
		tempUser[i] = *user[i];
	} //end for

	scores = fopen("scores.bin", "wb");
	fwrite(tempUser, sizeof(PLAYER), 10, scores);
	fclose(scores);
} //end saveScores

void playerSelect(PLAYER* players[]) {
	char choice;
	int pSelection = 0, i, flag = 0;
	printf("게임을 시작하려면 Y를 입력해주세요!!: ");
	do {
		scanf("%c", &choice); 
		fflush(stdin);
		choice = toupper(choice);
		switch (choice) {
		case 'Y':

			for (i = 8; i >= 0; i--) {
				players[i + 1]->gamesPlayed = players[i]->gamesPlayed;
				players[i + 1]->bank = players[i]->bank;
				players[i + 1]->wins = players[i]->wins;
				players[i + 1]->loses = players[i]->loses;
				players[i + 1]->streak = players[i]->streak;
				strcpy(players[i + 1]->name, players[i]->name);
			} //end for

			flag = 1;


			printf("닉네임을 정해주세요: ");
			scanf("%s", players[0]->name); 
			fflush(stdin);
			players[0]->bank = 100;
			players[0]->gamesPlayed = 0;
			players[0]->loses = 0;
			players[0]->wins = 0;
			players[0]->streak = 0;


			break;
		default:
			printf("\n\t제대로 입력해주십시오\n\n");
			playerSelect(players);
			flag = 0;
			break;
		} //end switch
	} while (flag == 0);
} //end playerSelect

void displayPlayerList(PLAYER* *p) {
	int i;

	for (i = 0; i < SIZE; i++) {
		printf("%i. %s\t%.2lf\n", i + 1, p[i]->name, p[i]->bank);
	}// end for

}// end displayPlayers

void shifter(PLAYER* *players, int selection) {
	int i;
	PLAYER temp;
	temp = *players[selection - 1];
	for (i = selection - 2; i >= 0; i--) {
		players[i + 1]->gamesPlayed = players[i]->gamesPlayed;
		players[i + 1]->bank = players[i]->bank;
		players[i + 1]->wins = players[i]->wins;
		players[i + 1]->loses = players[i]->loses;
		players[i + 1]->streak = players[i]->streak;
		strcpy(players[i + 1]->name, players[i]->name);
	} //end for
	players[0]->bank = temp.bank;
	players[0]->gamesPlayed = temp.gamesPlayed;
	players[0]->loses = temp.loses;
	players[0]->streak = temp.streak;
	players[0]->wins = temp.wins;
	strcpy(players[0]->name, temp.name);
} //end shifter

void showScores(PLAYER* *p) {
	int i;

	printf("지난 10명의 player들입니다: \n\n");
	printf("   닉네임\t\t잔고\t\t플레이횟수\t승리\t패배\t연승\n\n");
	for (i = 0; i<SIZE; i++) {
		printf("%i. %s,\t\t$%.2f,\t\t%i,\t%i,\t%i,\t%i\n", i + 1, p[i]->name, p[i]->bank, p[i]->gamesPlayed, p[i]->wins, p[i]->loses, p[i]->streak);
	} //end for
	mypause();
} //end showScores
