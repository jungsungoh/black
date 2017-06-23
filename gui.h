


#include <stdio.h>
#include <stdlib.h>

//void displayMenu(PLAYER**);
void welcomeScreen();

void blackjack() {
	system("clear");
	printf("\n\n");
	printf("\tXXXXXXXX   XXX             XXX       XXXXXXXX  XX     XX          \n");
	printf("\tXX     XX  XXX           XX   XX     XX        XX   XX           \n");
	printf("\tXX     XX  XXX          XX     XX    XX        XX XX             \n");
	printf("\tXXXXXXXX   XXX          XXXXXXXXX    XX        XX X              \n");
	printf("\tXX    XX   XXX         XXXXXXXXXXX   XX        XX X              \n");
	printf("\tXX     XX  XXX         XX       XX   XX        XX  XX            \n");
	printf("\tXX     XX  XXX        XX         XX  XX        XX    XX          \n");
	printf("\tXXXXXXXX   XXXXXXXXX XX           XX XXXXXXXX  XX      XX      \n\n");

	printf("\t      XXXXXXXXXXXXX     XXXX        XXXXXXXX     XX     XX          \n");
	printf("\t           XXXX        XX  XX       XX           XX    XX           \n");
	printf("\t           XXXX       XX    XX      XX           XX  XX             \n");
	printf("\t           XXXX       XXXXXXXXX     XX           XX XX              \n");
	printf("\t           XXXX      XXXXXXXXXXX    XX           XX XX              \n");
	printf("\t           XXXX      XX       XX    XX           XX   XX            \n");
	printf("\t       XX  XXXX     XX         XX   XX           XX     XX          \n");
	printf("\t        XXXXXX      XX         XX   XXXXXXXX     XX       XX      \n\n");
	printf("\n");
	mypause();
}//End function blackjack

void welcomeScreen() {
	system("clear");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n $        $  $$$$$$$  $      $$$$$$$  $$$$$$$$$  $$$   $$$  $$$$$$$   \n");
	printf(" $        $  $        $      $        $       $  $  $ $  $  $         \n");
	printf(" $        $  $$$$$$$  $      $        $  $$$  $  $  $ $  $  $$$$$$$    \n");
	printf(" $  $$$   $  $        $      $        $  $$$  $  $  $$$  $  $         \n");
	printf(" $  $  $  $  $        $      $	      $       $  $       $  $         \n");
	printf(" $$$$  $$$$  $$$$$$$  $$$$$$ $$$$$$$  $$$$$$$$$  $       $  $$$$$$$  \n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

	printf("\n\n");
	printf("\t\t\tRULES OF THE GAME:\n");
	printf("---------------------------------------------------------------------\n");
	printf("1.Blackjack은 52장의 카드로 게임을 하는 카드게임입니다.\n");
	printf("2.카드에 적힌 숫자의 합이 21(Black jack)에 가까운 player의 승리입니다\n");
	printf("3.각각의 player가 가지고 있는 카드의 합이 21을 넘으면 \n");
	printf("  bust되었다고 하며 게임에서 패배하게 됩니다.\n");
	printf("4.기본으로 두장의 카드를 받으며 player가 원할 시 추가로 받을 수 있습니다.\n");
	printf("5.A의 값은 1혹은 11로 Player가 선택할수 있습니다.\n");
	printf("6.Black jack 게임에서 문양은 큰 의미가 없습니다.\n");
	printf("\n\n");
	mypause();
}//End function welcomeScreen



void drawCard(char card) {
	printf("-------\n");
	printf("|      |\n");
	printf("|  %c   |\n", card);
	printf("|      |\n");
	printf("-------\n");
} //End drawCard
