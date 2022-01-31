#pragma once
#include "Guthabenverwaltung.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void gameRoutine();

unsigned int calcWalze();

unsigned int randNum(unsigned int max);

char roundWinLetter(char* walzen);

bool wannaPlay();