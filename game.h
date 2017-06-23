#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

void shuff(int[]);
int convert(int);
void pic(int num);
int play();


void shuff(int cards[]) {
	int t;
	int i;
	int desk[52] = { 0 };
	for (i = 0; i < 52; i++)
		desk[i] = (i / 13 + 3) * 100 + i % 13 + 1;

	srand((unsigned)time(NULL));
	for (i = 0; i < 52; i++) {
		do {
			t = rand() % 52;
		} while (desk[t] == 0);
		cards[i] = desk[t];
		desk[t] = 0;
	} //end for
} //end shuff

int convert(int a) {
	if ((a % 100 == 11) || (a % 100 == 12) || (a % 100 == 13))
		return (a / 100) * 100 + 10;
	else
		return a;
} //end convert

void pic(int num) {
	int cardNum;

	cardNum = num % 100;
	switch (cardNum) {
	case 1: {
		printf("******\n");
		printf("*    *\n");
		printf("*  A *\n");
		printf("*    *\n");
		printf("******\n");
		break;
	}
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10: {
		printf("******\n");
		printf("*    *\n");
		printf("* %2d *\n", cardNum);
		printf("*    *\n");
		printf("******\n");
		break;
	}
	case 11: {
		printf("******\n");
		printf("*    *\n");
		printf("*  J *\n");
		printf("*    *\n");
		printf("******\n");
		break;
	}
	case 12: {
		printf("******\n");
		printf("*    *\n");
		printf("*  Q *\n");
		printf("*    *\n");
		printf("******\n");
		break;
	}
	case 13: {
		printf("******\n");
		printf("*    *\n");
		printf("*  K *\n");
		printf("*    *\n");
		printf("******\n");
		break;
	}
	} //end switch
} //end pic

int play() {
	int i;
	int playerSum = 0;
	int dealerSum = 0;
	int playerCards[5] = { 0 };
	int dealerCards[5] = { 0 };
	int cards[52];
	//char choice;
	int aChoice;

	//shuff the cards
	shuff(cards);

	//give the cards
	playerCards[0] = cards[0];
	playerCards[1] = cards[1];
	dealerCards[0] = cards[2];
	dealerCards[1] = cards[3];

	//the 2 cards player get
	printf("컴퓨터의 카드 중 하나:\n");
	pic(dealerCards[0]);
	printf("\n");
	printf("플레이어의 카드:\n");
	pic(playerCards[0]);
	pic(playerCards[1]);

	i = 0;
	for (i = 0; i < 2; i++) {
		if (playerCards[i] % 100 == 1) {
			printf("%d번째 카드 A의 값을 1또는 11로 선택해주세요 : ", i + 1);
			do {
				scanf("%i", &aChoice); 
				fflush(stdin);
				switch (aChoice) {
				case 1:
					break;
				case 11:
					break;
				default:
					printf("\t1 또는 11로 답해주세요!!\n");
					break;
				} 
			} while (aChoice != 1 && aChoice != 11);

			if (aChoice == 11) {
				printf("당신은 A의 값을 11로 선택했습니다.\n");
				playerSum = playerSum + 11;
			}
			else if (aChoice == 1) {
				printf("당신은 A의 값을 1로 선택했습니다.\n");
				playerSum = playerSum + 1;
			}
		}
		else if (convert(playerCards[i]) % 100 == 10)
			playerSum = playerSum + 10;
		else
			playerSum = playerSum + playerCards[i] % 100;
		
		if (playerSum > 21) {
			printf("현재 플레이어의 카드의 합은:%d\n\n", playerSum);
			printf("Computer의 승리입니다!베팅한 금액을 잃습니다\n");
			mypause();
			return 1;
		}

		else if (playerSum == 21) {
			
			printf("현재 플레이어의 카드의 합은:%d\n\n", playerSum);
			printf("Player의 승리입니다!, 베팅한 금액만큼 돈을 얻습니다\n");
			mypause();
			return 1;
		} 
	}
	printf("현재 플레이어의 카드의 합은:%d\n\n", playerSum);

	//whether player get another cards
	for (i = 0; i < 3; i++) {
		char choice = 'n';
		printf("카드를 새로 받으시겠습니까? y또는 n으로 답해주세요: ");
		do {
			scanf("%c", &choice);
			fflush(stdin);
			tolower(choice);
			if (choice != 'y' && choice != 'n')
				printf("\ty또는 n으로 답해주세요!!\n");
		} while (choice != 'y' && choice != 'n');

		if (choice == 'y') {
			printf("새로운 카드를 받았습니다.\n");
			playerCards[i + 2] = cards[i + 4];
			printf(" 당신의 %d번째 카드입니다:\n", i + 3);
			pic(playerCards[i + 2]);

			if (playerCards[i + 2] % 100 == 1) {
			printf("%d번째 카드 A의 값을 11(Y)또는 1(N)중에서 선택해주세요.: ", i+3);
				do {
					scanf("%c", &choice);
					fflush(stdin);
					tolower(choice);
					if (choice != 'y' || choice != 'n')
						printf("\ty또는 n으로 답해주세요!!\n");
				} while (choice != 'y' && choice != 'n');
				if (choice == 'y') {
					printf("플레이어는 A의 값을 11로 정했습니다.\n");
					playerSum = playerSum + 11;
				}
				else if (choice == 'n') {
					printf("플레이어는 A의 값을 1로 정했습니다..\n");
					playerSum = playerSum + 1;
				}
			}
			else if (convert(playerCards[i + 2]) % 100 == 10)
				playerSum = playerSum + 10;
			else
				playerSum = playerSum + playerCards[i + 2] % 100;

			if (playerSum > 21) {
				printf("플레이어의 현재 카드의 합은: %i\n\n", playerSum);
				printf("Computer의 승리입니다.!베팅한 금액을 잃습니다\n");
				mypause();
				return 0;
			}
			else if (playerSum == 21) {
				printf("플레이어의 현재 카드의 합은: %i\n\n", playerSum);
				printf("Player의 승리입니다!베팅한 금액만큼 돈을 얻습니다\n");
				mypause();
				return 1;
			}
			else
				printf("플레이어의 현재 카드의 합은: %i\n\n", playerSum);
		}
		else {
			printf("플레이어의 현재 카드의 합은: %i\n\n", playerSum);
			break;
		}
	}
	if (i == 3) {
		printf("당신의 5개의 card의 합이 21보다 작으므로 player의 승리입니다\n");
		mypause();
		return 0;
	} 

	  
	printf("Computer의 카드는:\n");
	pic(dealerCards[0]);
	pic(dealerCards[1]);

	if (dealerCards[0] % 100 + dealerCards[1] % 100 == 2) {
		dealerSum = 12; 
		printf("컴퓨터의 현재 카드의 합은: %i\n\n", dealerSum);
	}
	else if ((convert(dealerCards[0])) % 100 + (convert(dealerCards[1])) % 100 == 1) {
		dealerSum = 21;
		printf("컴퓨터의 현재 카드의 합은: %i\n\n", dealerSum);
		printf("Computer의 승리입니다!베팅한 금액을 잃습니다.\n");
		mypause();
		return 0;
	}
	else if (dealerCards[0] % 100 == 1 || dealerCards[1] % 100 == 1) {
		dealerSum = (dealerCards[0] + dealerCards[1]) % 100 + (rand() % 2) * 10;
		printf("컴퓨터의 현재 카드의 합은: %i\n\n", dealerSum);
	}
	else {
		dealerSum = (convert(dealerCards[0])) % 100 + (convert(dealerCards[1])) % 100;
		printf("컴퓨터의 현재 카드이 합은: %i\n\n", dealerSum);
	}

	 
	for (i = 0; i < 3 && dealerSum < 17; i++) {
		dealerCards[i + 2] = cards[i + 7];
		printf("Computer의 카드는  %i 입니다.: \n", i + 3);
		pic(dealerCards[i + 2]);

		if (dealerCards[i + 2] % 100 == 1) {
			if (dealerSum + 11 <= 21) {
				printf("Computer는 A의 값을 11로 정했습니다.\n");
				dealerSum = dealerSum + 11;
				printf("컴퓨터이 현재 카드의 합은: %i\n\n", dealerSum);
			}
			else {
				printf("Compuer는 A의 값을 1로 정했습니다\n");
				dealerSum = dealerSum + 1;
				printf("컴퓨터의 현재 카드의 합은: %i\n\n", dealerSum);
			}
		}
		else {
			dealerSum = dealerSum + convert(dealerCards[i + 2]) % 100;
			printf("Computer의 현재 카드의 합은 : %i\n\n", dealerSum);
		} 
	}
	if ( i == 3){
		printf("컴퓨터의 5장의 카드의 합이 21을 넘지 않았으므로 컴퓨터의 승리입니다.\n");
		mypause();
		return 0;
	}	

	
	if (dealerSum>21 || playerSum>dealerSum) {
		printf("Player의 승리입니다.!베팅한 금액만큼 돈을 얻습니다.\n");
		mypause();
		return 1;
	}
	else if (playerSum == dealerSum) {
		printf("player와 computer가 같은 점수를 획득했습니다!\n");
		mypause();
		return 3;
	}
	else if (playerSum < dealerSum) {
		printf("Computer의 승리입니다! 베팅한 금액을 잃습니다.\n");
		mypause();
		return 0;
	}
	return 3;
} 
