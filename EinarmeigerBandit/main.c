#include<stdio.h>
#include "Guthabenverwaltung.h"
#include "Spieleverwaltung.h"

int main()
{
	while (true)
	{
		char selection;
		printf("1. Spielen\n");
		printf("2. Einzahlen\n");
		printf("3. Auszahlen\n");

		scanf_s("%c", &selection);
		for (int c; (c = getchar()) != EOF && c != '\n';);

		switch (selection)
		{
		case '1':
			gameRoutine();
			break;
		case '2':
			deposit();
			break;
		case '3':
			payday();
				break;
		default:
			break;
		}
		
	}
}