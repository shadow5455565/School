#pragma once
//TODO: Aggiungere lingua inglese

#ifndef GAMERULE_H
#define GAMERULE_H

/*TUTTE LE AVVERTENZE VERRANNO SCRITTE QUI
*** Il codice e' stato scritto da CRYogen ***
*** L'utilizzo dei codici e' libero sotto obbligata citazione dell'autore (CRYogen) e di chiunque abbia contribuito al progetto ***
*** DATA crezione: 03/02/2017 ***
*** DATA ultima modifica : 03/02/2017 da CRYogen***
--> Ogni avvertenza e' segnata da un id, stampato a schermo di default e scritto nei file log <-- 
*/
#define AVV_001 "AVVERTENZA (Id 0): mancano 5 tentativi !"
#define AVV_002 "AVVERTENZA (Id 1): mancano 3 tentativi !!"
#define AVV_003 "AVVERTENZA (Id 2): ultimo tentativo !!!"
#define AVV_004 "AVVERTENZA (Id 3): DEBUG: debug mode on"
#define AVV_005 "AVVERTENZA (Id 4): DEBUG: debug mode off"
#define AVV_006 "AVVERTENZA (Id 5): Sto generando 4 numeri casuali"
#define AVV_007 "AVVERTENZA (Id 6): L'utente ora puo' inserire i numeri"
#define AVV_008 "AVVERTENZA (Id 7): Sto inizializzando il programma"
#define AVV_009 "AVVERTENZA (Id 8): Complimenti hai vinto, premere un qualsiasi tasto  per uscire"
#define AVV_010 "AVVERTENZA (Id 9): Mi dispiace ma hai perso, premere invio per vedere la sequenza corretta"
#define AVV_011 "AVVERTENZA (Id 10): La sequenza corretta e': "
#define AVV_012 "AVVERTENZA (Id 11): GAME OVER!!!"
/*FINE AVVERTENZE*/

/*TUTTI GLI ERRORI VERRANNO SCRITTI QUI
*** Il codice e' stato scritto da CRYogen ***
*** L'utilizzo dei codici e' libero sotto obbligata citazione dell'autore (CRYogen) e di chiunque abbia contribuito al progetto ***
*** DATA crezione: 03/02/2017 ***
*** DATA ultima modifica : 03/02/2017 da CRYogen***
--> Ogni errore e' segnato da un id, stampato a schermo di default e scritto nei file log <--
*/
#define ERR_001 "ERRORE (Id 0): Numero gia' inserito"
#define ERR_002 "ERRORE (Id 1): input NON e' un numero"
#define ERR_003 "ERRORE (Id 2): Impossibile aggiornare lo schermo, riavviare e ritentare"
/*FINE ERRORI*/

/*TUTTI I VALORI DI DEFAULT VERRANNO SCRITTI QUI
*** Il codice e' stato scritto da CRYogen ***
*** L'utilizzo dei codici e' libero sotto obbligata citazione dell'autore (CRYogen) e di chiunque abbia contribuito al progetto ***
*** DATA crezione: 03/02/2017 ***
*** DATA ultima modifica : 03/02/2017 da CRYogen***
--> Ogni valore di default e' pubblico quindi utilizzabile in ogni parte del programma che include questa libreria<--
*/
#define DEBUG_ISDEBUG_ON 3
#define DEBUG_ISDEBUG_OFF 4
#define MAX_TENTATIVI 10
#define HOWEND_WIN 1
#define HOWEND_LOSE 2
#define CONTINUE_GAME 0x00000011
#define END_GAME 0x00000010
#define WAIT_PRESS_KEY 0x00000020
/*FINE VALORI DI DEFAULT*/

class gamerule
{
private:
	int tentativi = MAX_TENTATIVI;
	int right_pos;
	int wrong_pos;
	int gamefinish_count = 0;
	char* error;
	int* instream; //user nums
	int* rand_nums;
	int isdebug;
	int gamestate;
public:
	void clearcluevars();
	int updscreen(int out_mode);
	int seterrormex(const char* str);
	int isgamefinished(int HOWEND);
	int debugcheck(int init);
	int setdebugmode(int isdebugset);
	int emptymexerror();
	void printerr();
	int setdefaultvariables();
	int setdefaulttent(int tent);
	int setrandnums(int randseed);
	int setusernums();
	int checkusernums();
	void runtime();
	gamerule();
	~gamerule();
};

#endif

