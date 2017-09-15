#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Aggiungere database

//Definizione dello struct alunno, contenente nome cognome e se e' stato interrogato o meno
typedef struct alunno
{//STRUCT alunno
		//Aggiungere s(truct)id per database
		char *nome;
		char *cognome;
		int interrogato; //Da leggere da DataBase in futuro
}alunno;//~STRUCT alunno

//Define di tutti gli struct alunno necessari (22); ALLSTRUCT
alunno alunno1;
alunno alunno2;
alunno alunno3;
alunno alunno4;
alunno alunno5;
struct alunno alunno6;
struct alunno alunno7;
struct alunno alunno8;
struct alunno alunno9;
struct alunno alunno10;
struct alunno alunno11;
struct alunno alunno12;
struct alunno alunno13;
struct alunno alunno14;
struct alunno alunno15;
struct alunno alunno16;
struct alunno alunno17;
struct alunno alunno18;
struct alunno alunno19;
struct alunno alunno20;
struct alunno alunno21;
struct alunno alunno22;
//~ALLSTRUCT
int setglobals(){
	
	//define alunnno 1: Manuel Bonacina default non interrogato; AL1
	alunno1.cognome=(char*)"Bonacina";
	alunno1.nome=(char*)"Manuel";
	alunno1.interrogato=0;
	//~AL1
	
	//define alunno 2: Francesco Brossa default non interrogato; AL2
	alunno2.cognome=(char*)"Brossa";
	alunno2.nome=(char*)"Francesco";
	alunno2.interrogato=0;
	//~AL2
	
	//define alunno 3: Matteo Caccia default non interrogato; AL3
	alunno3.cognome=(char*)"Caccia";
	alunno3.nome=(char*)"Matteo";
	alunno3.interrogato=0;
	//~AL3
	
	//Define alunno 4: Elena Catanzaro default non interrogata; AL4
	alunno4.cognome=(char*)"Catanzato";
	alunno4.nome=(char*)"Elena";
	alunno4.interrogato=0;
	//~AL4
	
	//Define alunno 5: Lorenzo Codega default non interrogato; AL5
	alunno5.cognome=(char*)"Codega";
	alunno5.nome=(char*)"Lorenzo";
	alunno5.interrogato=0;
	//~AL5
	
	//Define alunno 6: Cristina Gianola default non interrogato; AL6
	alunno6.cognome=(char*)"Gianola";
	alunno6.nome=(char*)"Cristina";
	alunno6.interrogato=0;
	//~AL6
	
	//Define alunno 7: Antonio Lia default non interrogato; AL7
	alunno7.cognome=(char*)"Lia";
	alunno7.nome=(char*)"Antonio";
	alunno7.interrogato=0;
	//~AL7
	
	//Define alunno 8: Michael Locatelli default non interrogato; AL8
	alunno8.cognome=(char*)"Locatelli";
	alunno8.nome=(char*)"Michael";
	alunno8.interrogato=0;
	//~AL8
	
	//Define alunno 9: Riccardo Micheli default non interrogato; AL9
	alunno9.cognome=(char*)"Micheli";
	alunno9.nome=(char*)"Riccardo";
	alunno9.interrogato=0;
	//~AL9
	
	//Define alunno 10: Carmine Morelli default non interrogato; AL10
	alunno10.cognome=(char*)"Morelli";
	alunno10.nome=(char*)"Carmine";
	alunno10.interrogato=0;
	//~AL10

	//Define alunno 11: Roberto Motta default non interrogato; AL11
	alunno11.cognome=(char*)"Motta";
	alunno11.nome=(char*)"Roberto";
	alunno11.interrogato=0;
	//~AL11
	
	//Define alunno 12: Awatif Moumouni default non interrogato; AL12
	alunno12.cognome=(char*)"Moumouni";
	alunno12.nome=(char*)"Awatif";
	alunno12.interrogato=0;
	//~AL12
	
	//Define alunno 13: Stefano Negri default non interrogato; AL13
	alunno13.cognome=(char*)"Negri";
	alunno13.nome=(char*)"Stefano";
	alunno13.interrogato=0;
	//~AL13
	
	//Define alunno 14: Mirco Ovidi default non interrogato; AL14
	alunno14.cognome=(char*)"Ovidi";
	alunno14.nome=(char*)"Mirco";
	alunno14.interrogato=0;
	//~AL14
	
	//Define alunno 15: Andrea Panetta; AL15
	alunno15.cognome=(char*)"Panetta";
	alunno15.nome=(char*)"Andrea";
	alunno15.interrogato=0;
	//~AL15
	
	//Define alunno 16: Lara Pomoni; AL16
	alunno16.cognome=(char*)"Pomoni";
	alunno16.nome=(char*)"Lara";
	alunno16.interrogato=0;
	//~AL16
	
	//Define alunno 17: Raul Radu; AL17
	alunno17.cognome=(char*)"Radu";
	alunno17.nome=(char*)"Raul";
	alunno17.interrogato=0;
	//~AL17

	//Define alunno 18: Jheremy Ramos; AL18
	alunno18.cognome=(char*)"Ramos";
	alunno18.nome=(char*)"Jheremy";
	alunno18.interrogato=0;
	//~AL18

	//Define alunno 19: Andrea Sirico; AL19
	alunno19.cognome=(char*)"Sirico";
	alunno19.nome=(char*)"Andrea";
	alunno19.interrogato=0;
	//~AL19

	//Define alunno 20: Ramon Sorrentino; AL20
	alunno20.cognome=(char*)"Sorrentino";
	alunno20.nome=(char*)"Ramon";
	alunno20.interrogato=0;
	//~AL20

	//Define alunno 21: Igor Tallarico; AL21
	alunno21.cognome=(char*)"Tallarico";
	alunno21.nome=(char*)"Igor";
	alunno21.interrogato=0;
	//~AL21	

	//Define alunno 22: Alessio Valnegri; AL22
	alunno22.cognome=(char*)"Valnegri";
	alunno22.nome=(char*)"Alessio";
	alunno22.interrogato=0;
	//~AL22
	return 0;
}
//RITORNA LA LISTA DELL'ALUNNO;
int lista_alunni(int id, struct alunno* AL_ID)
{//implementare il check dell'interrogazione: NECESSITA' Database
	switch(id)
	{
		case 1:
			*AL_ID=alunno1;
			break;
		case 2:
			*AL_ID=alunno2;
			break;
		case 3:
		 	*AL_ID=alunno3;
		 	break;
		case 4:
			*AL_ID=alunno4;
			break;
		case 5:
			*AL_ID=alunno5;
			break;
		case 6:
			*AL_ID=alunno6;
			break;
		case 7:
			*AL_ID=alunno7;
			break;
		case 8:
		 	*AL_ID=alunno8;
			break;
		case 9:
			*AL_ID=alunno9;
			break;
		case 10:
			*AL_ID=alunno10;
			break;
		case 11:
			*AL_ID=alunno11;
			break;
		case 12:
			*AL_ID=alunno12;
			break;
		case 13:
			*AL_ID=alunno13;
			break;
		case 14:
			*AL_ID=alunno14;
			break;
		case 15:
			*AL_ID=alunno15;
			break;
		case 16:
			*AL_ID=alunno16;
			break;
		case 17:
			*AL_ID=alunno17;
			break;
		case 18:
			*AL_ID=alunno18;
			break;
		case 19:
			*AL_ID=alunno19;
			break;
		case 20:
			*AL_ID=alunno20;
			break;
		case 21:
			*AL_ID=alunno21;
			break;
		case 22:
			*AL_ID=alunno22;
			break;
		default:
			printf("ERROR: id: number not in range 1-22\n");
			exit(1);
			break;
	}
}

int main()
{
	int is_globals;
	is_globals=setglobals();
	if(is_globals==0) printf("Correct settings of globals\n");
	int rand_id[4], rand_seed;
	struct alunno AL;
	rand_seed=time(NULL);
	srand(rand_seed);
	printf("Nominativi per l'interrogazione:\n");
	for (int i=0;i<4;i++)
	{
		rand_id[i]=(rand()%22)+1;
		for (int a=0;a<i;a++)
		{
			if(rand_id[i]==rand_id[a])
			{
				i--;
			}
		}
	}
	for (int i=0;i<4;i++)
	{
		lista_alunni(rand_id[i], &AL);
		printf("-%d- %s %s\n",i+1,AL.cognome, AL.nome);
	}
}
