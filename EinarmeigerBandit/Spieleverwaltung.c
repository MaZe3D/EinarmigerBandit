#include "Spieleverwaltung.h"

const char walze[] = { 'A', 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'E', '7' };
const unsigned char anzWalzen = 3;
unsigned int freispiele = 0;
//unsigned int auszahlungsqoute = 0;

void gameRoutine()
{
	while (wannaPlay())
	{
		printf("Game Started!\n");
		changeBalance(-20);
		char walzen[3] = {calcWalze(), calcWalze(), calcWalze()};
		printf("Ergebnis: %c | %c | %c\n", walzen[0], walzen[0], walzen[0]);
		char winLetter = roundWinLetter(&walzen);
		unsigned int winBetrag = 0;
		switch (winLetter)
		{
		case 0:
			printf("You lost this game!\n");
			break;
		case '7':
			freispiele += 10;
			printf("You won 10 free games");
			break;
		default:
			winBetrag = getValueFromWinLetter(winLetter);
			break;
		}
		for (unsigned char i = 0; i < 2 && winBetrag > 0; i++)
		{
			printf("You won %f. do you want to double it with a risky game? (y|n)\n", 50 / (float)winBetrag);
			char h;
			scanf_s("&c", &h);
			if (h == "y")
			{
				winBetrag = winBetrag * (randNum(1) * 2);

			}
			else
				break;
			if (winBetrag > 0)
				printf("Perfect choice! You doubled your win");
			else
				printf("You will win next time. Your win has been reset!");
		}
		printf("You have added %.2f to your account", (float)(getBalance() / 100));
		changeBalance(winBetrag);
		
	}
}

unsigned int calcWalze()
{
	return rand(10);
}

getValueFromWinLetter(char letter)
{
	switch (letter)
	{
	case 'A':
		return 20;
	case 'B':
		return 40;
	case 'C':
		return 80;
	case 'D':
		return 160;
	case 'E':
		return 320;
	default:
		return 0;
	}
}

unsigned int randNum(unsigned int max)
{
	srand(time(0));
	return (unsigned)rand() % max + 1;
}

char roundWinLetter(char* walzen)
{
	bool b = true;
	for (char i = 1; i < anzWalzen; i++)
	{
		if (walzen[0] != walzen[i])
			b = false;
	}
	if (b)
		return walzen[0];
	return 0;
}

bool wannaPlay()
{
	if (freispiele > 0)
	{
		printf("You have %u free games left!", freispiele = freispiele - 1);
		return true;
	}
	if (getBalance > 0)
	{
		char h;
		printf("You have %.2f on your Account. Do you want to play a game?\n (y|n)", getBalance() / 100);
		scanf_s("&c", &h);
		if (h = 'y')
			return true;
		return false;
	}
	printf("Your Balance is to low for a game! \n");
	return false;
}