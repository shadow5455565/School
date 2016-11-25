#include <stdio.h>
#include <stdlib.h>

//Counting function initialisation
int numerator(int array[100],int nnums,int num);

//Researching function initialisation
int resch(int array[100],int nnums, int num);
int main()
{
	//Initial commands
	system("TITLE Ricercatore/contatore");
	printf("Programma che ricerca o conta quante volte compare un numero dentro un array\n\n\n");
	
	//Variables
	int nums[100], nnum, i,chs, num, outpt;
	
	//Main program
	printf("Quanti numeri vuoi inserire nell'array?\n-->");
	scanf("%d",&nnum);
	for (i=0;i<nnum;i++)
	{
		printf("Inserisci il %d numero: ",i+1);
		scanf("%d",&nums[i]);
	}
	printf("Vuoi ricercare un numero (1) oppure vuoi vedere quante volte compare nell'array(2)?\n-->");
	scanf("%d", &chs);
	switch(chs)
	{
		case 2:
			printf("Che numero vuoi usare?\n-->");
			scanf("%d",&num);
			outpt=numerator(nums, nnum ,num);
			printf("Il numero e' comparso %d volte.\n",outpt);
			break;
		case 1:
			printf("Che numero vuoi ricercare?\n-->");
			scanf("%d",&num);
			outpt=resch(nums,nnum,num);
			if (outpt==-1)
			{
				printf("Il numero non esiste in questo array");
			}
			else
			{
				printf("Il numero si trova in posizione %d",outpt);
			}
			break;
		default:
			printf("Nessuna opzione trovata con %d si prega di ritentare...",chs);
			break;
	}
}
int numerator(int array[100]/*main array*/,int nnums, int num)//Counting function
{
	int count=0;
	for (int i = 0; i < nnums; i++)
	{
		if(array[i]==num)
		{
			count++;
		}
	}
	return count;
}
int resch(int array[100],int nnums, int num)
{
	int pos=-1;
	for(int i=0; i< nnums;i++)
	{
		if(array[i]==num)
		{
			pos=i;
			break;
		}
	}
	pos=pos+1;
	return pos;
}
