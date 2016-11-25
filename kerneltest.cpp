#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int A_print(char* qry);

int main()
{
	bool loop=true,cmd_end = false;
	char cmd[100], qry[100];
	char cr_dir[100],cmd_qry[100];
	strcpy(cr_dir, "C:/");
	strcpy(qry,"");
	while (loop==true)
	{
		printf("%s>> ",cr_dir);
		scanf("%[^\n]%c", cmd_qry);
		for (int i=0; i < strlen(cmd_qry);i++)
		{
			if(cmd_qry[i]!=' '&&cmd_end==false)
			{
				cmd[i]=cmd_qry[i];
			}
			else
			{
				cmd_end=true;
				qry[i-strlen(cmd)]=cmd_qry[i];
			}
		}
		if(strcmp(cmd,"print")==0)
		{
			A_print(qry);
		}
		else
		{
			printf("No command recognized\n");
		}
		printf("%s, %s, %s\n",cmd_qry, cmd, qry);
		strcpy(cmd_qry,"");
		strcpy(cmd,"");
		strcpy(qry,"");
		printf("%s, %s, %s\n",cmd_qry, cmd, qry);
		cmd_end=false;
	}
}

int A_print(char* qry)
{
	if(qry[1]=='-')
	{
		switch(qry[2])
		{
			case 's':
				for (int i=4;i<strlen(qry);i++)
				{
					printf("%c",qry[i]);
				}
				printf("\n");
				return 1;//used for debugging
				break;
			case 'h':
				printf("Letter		Function\n");
				printf("-h			Shows this page\n");
				printf("-s			prints a string defined right next to the s\n");
				return 2;//Used for debugging
				break;
			default:
				printf("No command recognized, try -h for help.\n");
				return 0;//used for debugging
		}
	}
	else
	{	
		printf("No command recognized, try -h for help.\n");
		return 0;
	}
}
