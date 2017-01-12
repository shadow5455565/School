#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int num,i,num_ins,count=0;
	int num_indovinati[10];
	bool giocofinito=false,numerogiainserito=false;
	num=rand()%10;
	printf("%d\n",num);
	do
	{
		printf("Inserisci il numero da eliminare:");
		scanf("%d",&num_ins);
		if(count == 8)
		{
			printf("Hai vinto!\n");
			break;
		}
		else if(num_ins==num)
		{
			printf("Hai perso!\n");
			break;
		}
		else
		{
			for(int i=0; i <= count;i++)
			{
				if(num_ins==num_indovinati[i])
				{
					numerogiainserito=true;
				}
			}
			if(numerogiainserito==false)
			{
				printf("Il numero %d e' stato eliminato\n",num_ins);
				num_indovinati[count]=num_ins;
				count++;
			}
			else
			{
				printf("Hai gia inserito questo numero\n");
				numerogiainserito=false;
			}
		}
	}while(giocofinito == false);
	return 0;
}
