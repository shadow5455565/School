#include "stdafx.h"
#include "gamerule.h"

int gamerule::checkusernums() {
	/*
	ALGORITHM ID 01
	AUTH: CRY0g3n aka Shadow5455565 Aka Raul Radu
	USAGE: Check if numbers are in the same position in arrays, and check who are not
	VERSION: 1.0.1
	*/

	for (int i = 0; i < 4; i = i + 1) {
		if (rand_nums[i+1] == instream[i]) {
			ulocks[i] = instream[i];
			rlocks[i] = rand_nums[i+1];
			right_pos = right_pos + 1;
		}
	}
	for (int i = 0; i < 4; i = i + 1) {
		for (int x = 0; x < 4; x = x + 1) {
			if (rand_nums[x+1] == instream[i] && instream[i] != ulocks[i] && i != x && rand_nums[x+1] != rlocks[x] && instream[i] != uwlocks[i]) {
					rlocks[x] = rand_nums[x+1];
					uwlocks[i] = instream[i];
					wrong_pos = wrong_pos + 1;
				}
			}
		}
	tentativi--;
	if (right_pos == 4) return END_GAME;
	else return CONTINUE_GAME;
}

void gamerule::runtime() {
	//game_state;
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

int gamerule::menu()
{
	system("cls");
	printf("+----------------------------------------------+\n");
	printf("| 1234-5678-9098-7654-3212-3456-7890-9876-5432 |\n");
	printf("|---->          Mastermind  v1.5          <----|\n");
	printf("| 2345-6789-0987-6543-2123-4567-8909-8765-4321 |\n");
	printf("+----------------------------------------------+\n\n\n\n");
	
	int difficulty;
	printf("[*]Livelli di difficolta': \n[0]\tFacile : 50 Tentativi\n[1]\tMedio : 25 Tentativi\n[2]\tDifficile: 12 Tentativi\n[99]\tEsci\n\n\n");
	printf("[#]Inserisci il livello di difficolta'(0/1/2):");
	scanf_s("%d", &difficulty);
	switch (difficulty)
	{
		case 0:
			setdefaulttent(EASY_TENTATIVI);
			break;
		case 1:
			setdefaulttent(MEDIUM_TENTATIVI);
			break;
		case 2:
			setdefaulttent(HARD_TENTATIVI);
			break;
		case 99:
			return -200;
		default:
			menu();
			break;
	}
	return 1;
}

int gamerule::updscreen(int out_mode)
{
	system("cls");
	printf("ERRORI E AVVERTENZE: \n");
	printerr();
	if (debugcheck(0) == 1)
	{
		printf("DEBUG: la sequenza generata e': ");
		for (int i = 1; i < 5; i++) {
			printf("%d", rand_nums[i]);
		}
		printf("\n");
	}
	printf("NUMERI NELLA POSIZIONE CORRETTA: %d\n", right_pos);
	printf("NUMERI NELLA POSIZIONE SBAGLIATA: %d\n", wrong_pos);
	printf("ULTIME 3 SEQUENZE: ");
	for (int i = 0; i < 3; i++) {
		printf("%d.", i + 1);
		for (int x = 4 * i; x < 4 * (i + 1); x++) {
			printf("%d", histr[x]);
		}
		if (i !=2) printf(" ,");
		else printf("\n");
	}
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
	else if (isdebug == DEBUG_ISDEBUG_ON && init!=1)
	{
		return 1;
	}
	else {
		return -1;
	}
	updscreen(NULL);
	return -1;
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
	}
	return 0;
}

int gamerule::setusernums()
{
	for (int i = 0; i<5; i++)
	{
		instream[i] = _getch() - '0';
		if (instream[i] >= 0 && instream[i] <= 9 && i <= 3 )
		{
				printf("%d", instream[i]);
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
				updHistory();
				return 1;
			}
			else if(i<4){ i--; seterrormex(ERR_002); updscreen(NULL);}
			else i--;
		}
	}
	return 0;
}

void gamerule::updHistory()
{
	//Moving values from 4,5,6,7 to 8,9,10,11
	for (int i = 4; i < 8; i++) {
		histr[i + 4] = histr[i];
	}
	//Moving Values from 0,1,2,3 to 4,5,6,7
	for (int i = 0; i < 4; i++) {
		histr[i + 4] = histr[i];
	}
	//Moving Values from instream to 0,1,2,3
	for (int i = 0; i < 4; i++) {
		histr[i] = instream[i];
	}
}

void gamerule::clearcluevars() { //Pulisce, quindi azzera le variabili right_pos e wrong_pos;
	right_pos = 0;
	wrong_pos = 0;
}
gamerule::gamerule()
{
	instream = (int *)malloc((4 * sizeof(int)));
	for (int i = 0; i < 12; i++) {
		histr[i] = 0;
	}
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
