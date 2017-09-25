// mastermindrem.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include "gamerule.h"


int main(int argc, char* argv[])
{
	gamerule gamerules;
	gamerules.setdefaultvariables();
	if (argc>0 && atoi(argv[0]) == 1)
	{
		gamerules.setdebugmode(DEBUG_ISDEBUG_ON);
	}
	gamerules.debugcheck(1);
	if (gamerules.menu() == -200) return 0;
	gamerules.runtime();
	printf("\n\n");
    return 0;
}

