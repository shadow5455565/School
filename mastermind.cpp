#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int main(int argc, char* argv[])
{
	printf("Gioco di \"Mastermind\" \n\n\n");
	int gamenums[5], usernums[4], tentativi = 10, wrongpos, goodpos, gamefinish_count = 0, num_err = 0;
	srand(time(NULL));
	printf("\nSto generando 4 numeri casuali...");
	for (int i = 1; i < 5; i++)
	{
		gamenums[i] = rand() % 10;
		for (int a = 1; a<i; a++)
		{
			if (gamenums[a] == gamenums[i] || gamenums[i]<0 || gamenums[i]>9)
			{
				i--;
			}
		}
	}
	printf("FATTO!");
	if (argc >= 1)
	{
		if (atoi(argv[1]) == 1)
		{
			printf("\nDEBUG: numeri casuali creati:");
			for (int i = 1; i < 5; i++)
			{
				printf("%d ", gamenums[i]);
			}
		}
	}
	printf("\n");
	printf("il numero dei tentativi iniziali e': %d", tentativi);
	while (tentativi > 0 && gamefinish_count<4)
	{
		gamefinish_count = 0;
		wrongpos = 0;
		goodpos = 0;
		printf("\nInserire i numeri: ");
		for (int i = 0; i<5; i++)
		{
			usernums[i] = _getch() - '0';
			if (usernums[i] >= 0 && usernums[i] <= 9 && i <= 3)
			{
				for (int a = 0; a<i; a++)
				{
					if (usernums[a] == usernums[i])
					{
						num_err = 1;
						printf("\nErrore: il numero e' gia stato inserito, inserirne uno diverso\n");
						i--;
						printf("Inserire i numeri: ");
						for (int f = 0; f <= i; f++)
							printf("%d", usernums[f]);
					}
				}
				if (num_err == 0)
				{
					printf("%d", usernums[i]);
				}
				num_err = 0;
			}
			else
			{
				if (usernums[i] == -40 && i>0)
				{
					printf("\b");
					printf(" ");
					printf("\b");
					i--;
				}
				if (usernums[i] == (13 - '0') && i == 4) printf("\n");
				else i--;
			}
		}
		for (int m = 0; m < 4; m++)
		{
			for (int n = 1; n <5; n++)
			{
				if (usernums[m] == gamenums[n])
				{
					if (n == (m+1))
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
		if (gamefinish_count<4)
		{
			tentativi--;
			printf("\nil numero dei numeri che esistono ma sono nella posizione sbagliata: %d", wrongpos);
			printf("\nil numero dei numeri nella posizione giusta: %d", goodpos);
			printf("\nIl numero dei tentativi a disposizione e': %d", tentativi);
		}
		else
		{
			printf("Hai vinto, hai indovinato la sequenza! \n");
			system("PAUSE");
			return 0;
		}
	}
	printf("\nHai perso la sequenza giusta era:");
	for (int m = 1; m < 5; m++)
	{
		printf("%d ", gamenums[m]);
	}
	printf("\n");
	system("PAUSE");
	return 0;
}
