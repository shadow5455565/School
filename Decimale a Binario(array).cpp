#include <iostream>
#include <stdlib.h>
#define MAX_LEN 64+1

using namespace std;

int main()
{
	//layout
	system("TITLE Binario --> Decimale");
	system("COLOR 0a");
	
	//variabili
	long int decim,count;
	int bin[MAX_LEN];//in ordine decim = numero decimale,bin=numero binario come array,count= conta quanti bit ci sono
	
	//programma
	cout << "Questo programma trasforma un numero da decimale a binario" << endl;
	cout << endl << "Inserisci il numero che vuoi trasformare in binario..." << endl << "Numero decimale:";
	cin >> decim;
	cout << "Trasformando da decimale a binario..." << endl;
	count = 0;
	while (decim > 0)
	{
		count++;
		bin[count]=decim % 2;
		decim = decim / 2;
	}
	cout << "Il numero in binario e'";
	while(count > 0)
	{
		cout << bin[count];
		count--;
	}
	cout << endl;
	system("PAUSE");
	return 0;
}


