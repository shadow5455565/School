#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100

int main()
{
	//Graphics
	system("COLOR 0a");
	system("TITLE Ordinatore di numeri");
	
	//Variables
	int num,nums[MAX_NUM],swtchs,cl,tmp;
	
	//Description
	printf("***Ordinatore di numeri***\n\n\n");
	
	//Main program
	printf("Quanti numeri vuoi ordinare?\n");
	printf("-->");
	scanf("%d",&num);
	for(int i=0;i<num;i++)//Input
	{
		printf("Inserisci il  %d numero:", i);
		scanf("%d",&nums[i]);
	}
	cl=num;
	do//Orderer
	{
		swtchs=0;
		cl--;
		for(int i=0;i<cl;i++)
		{
			if(nums[i]>nums[i+1])
			{
				tmp = nums[i];
				nums[i] = nums[i+1];
				nums[i+1] = tmp;
				swtchs++;
			}
		}
	}while(swtchs!=0);
	printf("I numeri ordinati in ordine crescente sono: ");
	for(int i=0;i<num;i++)//Output
	{
		printf("%d ",nums[i]);
	}
	printf("\nI numeri pari sono: ");
	for(int i=0;i<num;i++)
	{
		if(nums[i]%2==0)
		{
			printf("%d ", nums[i]);
		}
	}
	printf("\nI numeri dispari sono: ");
	for(int i = 0;i<num;i++)
	{
		if(nums[i]%2!=0)
		{
			printf("%d ", nums[i]);
		}
	}
	printf("\nPremere un tasto per uscire dal programma...");
	getchar();//clears input buffer
	getchar();//Equivalent to system("PAUSE");
	return 0;//Return result to kernel
}
