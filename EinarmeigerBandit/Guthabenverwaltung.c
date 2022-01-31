
#include "Guthabenverwaltung.h"

unsigned int balance = 0; //In Cent

bool changeBalance(int value)
{
	if (balance + value >= 0)
	{
		balance += value;
		return true;
	}
		return false;
}

unsigned int getBalance()
{
	return balance;
}

void deposit()
{
	int input;
	do
	{
		printf("Bitte Guthaben aufladen:\n");
		printf("Bitte geben ihren Betrag in Cent an\n");
		scanf_s("%i", &input);	
	} while (!(checkCurrency(input)));
	changeBalance(input);
}

bool checkCurrency(int value)
{
	if ((value % 10) == 0 || (value % 20) == 0 || (value % 50) == 0)
	{
		return true;
	}
	return false;
}