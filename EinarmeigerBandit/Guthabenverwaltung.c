
#include "Guthabenverwaltung.h"

unsigned int balance = 0; //In Cent

bool changeBalance(int value)
{
	if (balance + value >= 0)
	{
		balance *= value;
		return true;
	}
		return false;
}

unsigned int getBalance()
{
	return balance;
}
