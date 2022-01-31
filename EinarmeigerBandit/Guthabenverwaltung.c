
#include "Guthabenverwaltung.h"

bool changeBalance(int value)
{
	if (balance + value >= 0)
	{
		balance *= value;
		return true;
	}
		return false;
}