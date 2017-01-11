#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
	printf("Gioco di \"Mastermind\" \n\n\n");
	int gamenums[4],usernums[4],tentativi=10,wrongpos,goodpos,gamefinish_count;
	srand(time(NULL));
	printf("\nSto generando 4 numeri casuali...");
	for (int i=0;i < 4; i++)
	{
		gamenums[i]=rand()%10;
		for(int a=0;a<i;a++)
		{
			if (gamenums[a]==gamenums[i])
			{
				i--;
			}
		}
	}
	printf("FATTO!");
	if (argc>=2)
	{
		if (atoi(argv[2])==1)
		{
			printf("\nDEBUG: numeri casuali creati:");
			for (int i=0; i < 4; i++)
			{
				printf("%d ", gamenums[i]);
			}
		}
	}
	printf("\n");
	printf("il numero dei tentativi iniziali e': %d",tentativi);
	while(tentativi > 0&&gamefinish_count<4)
	{
		gamefinish_count=0;
		wrongpos=0;
		goodpos=0;
		for (int i=0; i<4;i++)
		{
			printf("\nInserire il %d numero:",i+1);
			scanf("%d",&usernums[i]);
			for (int a=0;a<i;a++)
			{
				if (usernums[a]==usernums[i])
				{
					printf("Errore: il numero e' gia stato inserito, inserirne uno diverso");
					i--;
				}
			}
		}
		printf("La sequenza che hai inserito:");
		for (int i=0;i< 4;i++)
		{
			printf("%d ",usernums[i]);
		}
		printf("\n");
		for(int i=0; i < 4; i++)
		{
			for (int a=0; a <4; a++)
			{
				if (usernums[i]==gamenums[a])
				{
					if (a==i)
					{
						goodpos++;
						gamefinish_count++;
					}
					else
					{
						wrongpos++;
					}
				}
			}
		}
		if(gamefinish_count<4)
		{
			tentativi--;
			printf("\nil numero dei numeri che esistono ma sono nella posizione sbagliata: %d",wrongpos);
			printf("\nil numero dei numeri nella posizione giusta: %d",goodpos);
			printf("\nIl numero dei tentativi a disposizione e': %d", tentativi);
		}
		else
		{
			printf("Hai vinto, hai indovinato la sequenza!");
		}
	}
	return 0;
}
