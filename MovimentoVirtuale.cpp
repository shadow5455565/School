#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char var;
	int i;
	int pos_x;
	int pos_y;
	int count=0;
	int count_last=0;
	int count_err=0;
	pos_x=0;
	pos_y=1;
	for(;;)
	{
		var=getch();
		count++;
		if(var=='s')
		{
			pos_x++;
		}
		else if(var=='w')
		{
			pos_x--;
		}
		else if(var=='d')
		{
			pos_y++;
		}
		else if(var=='a'&&pos_y>0)
		{
			pos_y--;
		}
		else{
			count_err++;
		}
		if(count-count_last==1)
		{
			system("cls");
			cout << "PosX= " << pos_x << endl << "PosY= " << pos_y << endl;
			cout << "Error count: " << count_err;
			cout << endl << "--------------------------------------------------------------------------------" <<endl;
			for(i=0; i <= pos_x;i++)
			{
				cout << endl;
			}
			if (pos_x >= 17){
				pos_x = 1;
			}
			if (pos_x == 0){
				pos_x = 17;
			}
			i=0;
			if (pos_y<=78)
			{
				if (pos_y<=0)
				{
					pos_y=77;
				}
				if (pos_y>77)
				{
					pos_y=0;
				}
				for (i=0;i<= pos_y;i++)
				{
					cout << " ";
				}
			}
			cout << "#";
			count_last=count;
		}
	}
	return 0;
}
