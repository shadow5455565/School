#include "stdafx.h"
#include "gamerule.h"


int gamerule::updscreen()
{
	//TODO: codifica la griglia grafica sul quaderno;
	system("cls");
	printf("ERRORI E AVVERTENZE: \n");
	printerr();
	if (debugcheck(0) == 1)
	{
		printf("DEBUG: la sequenza generata e': %s\n",rand_nums);
	}
	printf("NUMERI NELLA POSIZIONE CORRETTA: %d\n", right_pos);
	printf("NUMERI NELLA POSIZIONE SBAGLIATA: %d\n", wrong_pos);
	printf("NUMERO DI TENTATIVI RIMASTI: %d\n", tentativi);
	printf("Inserisci qui la sequenza: ");
	return 0;
}

int gamerule::seterrormex(const char* str)
{
	error = (char*) malloc(sizeof (str));
	error = (char*) str;
	return 0;
}

int gamerule::isgamefinished(int HOWEND)
{
	if (HOWEND == HOWEND_WIN)
	{
		seterrormex(AVV_009);
		updscreen();
		return 0;
	}
	if (HOWEND == HOWEND_LOSE)
	{
		seterrormex(AVV_010);
		updscreen();
		_getch();
		emptymexerror();
		seterrormex("sequenza in stringa");
		updscreen();
		emptymexerror();
	}
}

int gamerule::debugcheck(int init)
{
	if (isdebug == DEBUG_ISDEBUG_OFF && init==1)
	{
		seterrormex(AVV_005);
	}
	else if (isdebug == DEBUG_ISDEBUG_ON && init==1)
	{
		seterrormex(AVV_004);
	}
	else
	{
		return -1;
	}
	updscreen();
}

int gamerule::setdebugmode(int isdebugset)
{
	isdebug = isdebugset;
	return 0;
}

int gamerule::emptymexerror()
{
	error = NULL;
	free(error);
	return 0;
}

void gamerule::printerr()
{
	printf("%s\n",error);
	emptymexerror();
}

int gamerule::setdefaultvariables()
{
	setdebugmode(DEBUG_ISDEBUG_OFF);
	setdefaulttent(MAX_TENTATIVI);
	setrandnums( (time(NULL)) );
	return 0;
}

int gamerule::setdefaulttent(int tent)
{
	tentativi = tent;
	return 0;
}

int gamerule::setrandnums(int randseed)
{
	seterrormex(AVV_006);
	updscreen();
	srand(randseed);
	rand_nums = (int *)malloc((5 * sizeof(int)));
	for (int i = 1; i < 5; i++)
	{
		rand_nums[i] = rand() % 10;
		for (int a = 1; a<i; a++)
		{
			if (rand_nums[a] == rand_nums[i] || rand_nums[i]<0 || rand_nums[i]>9)
			{
				i--;
			}
		}
	}
	return 0;
}

int gamerule::setusernums()
{
	int num_err = 0;
	instream = (int *)malloc((4 * sizeof(int)));
	for (int i = 0; i<5; i++)
	{
		instream[i] = _getch() - '0';
		if (instream[i] >= 0 && instream[i] <= 9 && i <= 3)
		{
			for (int a = 0; a<i; a++)
			{
				if (instream[a] == instream[i])
				{
					num_err = 1;
					seterrormex(ERR_001);
					updscreen();
					i--;
					for (int f = 0; f <= i; f++)
						printf("%d", instream[f]);
				}
			}
			if (num_err == 0)
			{
				printf("%d", instream[i]);
			}
			num_err = 0;
		}
		else
		{
			if (instream[i] == -40 && i>0)
			{
				printf("\b");
				printf(" ");
				printf("\b");
				i=i-2;
			}
			else if (instream[i] == (13 - '0') && i == 4) { seterrormex("La sequenza giusta e' 1234"); updscreen(); } //TEST
			else if(i<4){ i--; seterrormex(ERR_002); updscreen();}
			else i--;
		}
	}
	return 0;
}

gamerule::gamerule()
{
}


gamerule::~gamerule()
{
}
