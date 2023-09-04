#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<time.h> //rand
using namespace std;


int main()
{
	srand(time(NULL));
	int mat[100][20];  //100 cromosomas 20 genes
	int unos=0;
	
	cout<<"\n\t\t\tGENOMA"<<endl<<endl;
	for(int i = 0; i<100; i++) //filas
	{
		for(int j=0; j<20; j++) //columnas
		{
			mat[i][j] = rand()%2;
			cout<<mat[i][j]<<"  ";
			if(mat[i][j]==1)
			{
				unos++;
			}
		}
		cout<<"\tUnos: "<<unos;
		unos = 0;
		cout<<endl;
	}
	
	
}


