#include "stdafx.h"
#include "gamerule.h"

int gamerule::checkusernums() {
	for (int x = 0; x < 4; x++) {
		for (int i = 0; i < 4; i++) {
			if (instream[x] == rand_nums[i] && i==x) {
				right_pos++;
			}
			else if (instream[x] == rand_nums[i] && i!=x) {
				wrong_pos++;
			}
		}
	}
	tentativi--;
	if (right_pos == 4) return END_GAME;
	else return CONTINUE_GAME;
}

void gamerule::runtime() {
	//game_state;
	setdefaultvariables();
	do {
		setusernums();
		gamestate = checkusernums();
		updscreen(NULL);
		clearcluevars();
	} while (gamestate != END_GAME && tentativi > 0);
	if (tentativi == 0) {
		isgamefinished(HOWEND_LOSE);
	}
	else {
		isgamefinished(HOWEND_WIN);
	}
}

int gamerule::updscreen(int out_mode)
{
	system("cls");
	printf("ERRORI E AVVERTENZE: \n");
	printerr();
	if (debugcheck(0) == 1)
	{
		printf("DEBUG: la sequenza generata e': %s\n",rand_nums);
	}
	printf("NUMERI NELLA POSIZIONE CORRETTA: %d\n", right_pos);
	printf("NUMERI NELLA POSIZIONE SBAGLIATA: %d\n", wrong_pos);
	//printf("ULTIMA SEQUENZA: %s", iostream_history);
	printf("NUMERO DI TENTATIVI RIMASTI: %d\n", tentativi);
	switch (out_mode)
	{
		case HOWEND_LOSE:
			printf("La sequenza giusta era: ");
			for (int i = 1; i < 5; i++) {
				printf("%d", rand_nums[i]);
			}
			printf("\n");
			printf("Premere un qualsiasi tasto per uscire...");
			printf("\n");
			_getch();
			break;
		case HOWEND_WIN:
			_getch();
			break;
		case WAIT_PRESS_KEY:
			printf("Premere un qualsiasi tasto per uscire...");
			_getch();
			break;
		default:
			printf("Inserisci qui la sequenza: ");
			break;
	}
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
		updscreen(HOWEND_WIN);
		return 0;
	}
	if (HOWEND == HOWEND_LOSE)
	{
		seterrormex(AVV_010);
		updscreen(WAIT_PRESS_KEY);
		emptymexerror();
		seterrormex(AVV_012);
		updscreen(HOWEND_LOSE);
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
	updscreen(NULL);
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
	updscreen(NULL);
	srand(randseed);
	
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
					updscreen(NULL);
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
			else if (instream[i] == (13 - '0') && i == 4) { 
				return 1;
			} //TEST
			else if(i<4){ i--; seterrormex(ERR_002); updscreen(NULL);}
			else i--;
		}
	}
	return 0;
}

void gamerule::clearcluevars() { //Pulisce, quindi azzera le variabili right_pos e wrong_pos;
	right_pos = 0;
	wrong_pos = 0;
}
gamerule::gamerule()
{
	instream = (int *)malloc((4 * sizeof(int)));
	//instream_history = (int *)malloc(sizeof(instream)*4);
	rand_nums = (int *)malloc((5 * sizeof(int)));
}


gamerule::~gamerule()
{
	for (int i = 0; i < 4; i++) {
		instream[i] = NULL;
		rand_nums[i] = NULL;
		//instream_history[i] = NULL;
	}
	//free(instream_history);
	free(instream);
	free(rand_nums);
	clearcluevars();
}
