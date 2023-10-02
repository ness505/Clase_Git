/*
Programa que imprime las componentes conexas de un grafo 

Evelyn Vanessa Campos Aguayo
Maria Fernanda Rodriguez Rodriguez
Olga Daniela Calderón Amescua
Yaretzi Castillo Morales

29/09/23
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout<<"Ingresa la cantidad de nodos: ";cin>>n;
	int matAdy[n][n];
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			matAdy[i][j] = 0;
		}
	}
	
	int artistas;
	cout<<"Ingresa la cantidad de aristas: ";cin>>artistas;
	for (int i = 0; i < artistas; i++) {
        int nodoA, nodoB;
        cout << "Ingrese la arista " << i + 1 << " (nodoA nodoB): ";
        cin >> nodoA >> nodoB;
        matAdy[nodoA][nodoB] = 1;
	}
	
	cout<<endl;
	cout<<"MATRIZ ORIGINAL"<<endl;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			cout<<matAdy[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	//llenar la diagonal de la matriz de unos
	for(int i = 0; i<n; i++)
	{
		matAdy[i][i] = 1;
	}
	
	
	//recorrer cada fila y completar con unos de nodos adyacentes
	for(int i = 0; i<n ; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(matAdy[i][j]==1)
			{
				for(int k = 0; k<n; k++)
				{
					if(matAdy[j][k]==1)
					{
						matAdy[i][k] = 1;
						
						//recorrer la fila que se acaba de agregar
						for(int h =0 ; h<n; h++)
						{
							if(matAdy[k][h]==1)
							{
								matAdy[i][h]=1;
							}
						}
					}
				}
			}
		}
	}
	
	//ordenar filas de mayor a menor en cantidad de unos 
	int unos[2][n];
	int cont=0;
	for(int i = 0; i<n; i++)
	{
		unos[0][i] = i;
		for(int j = 0; j<n; j++)
		{
			if(matAdy[i][j]==1)
			{
				cont++;
			}
		}
		unos[1][i]=cont;
		cont = 0;
	}
	
	//ordenar calificacion
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n-1; j++)
		{
			if(unos[1][j]<unos[1][j+1])
			{
				int temp = unos[1][j+1];
				int posTemp = unos[0][j+1];
				
				unos[1][j+1] = unos[1][j];
				unos[0][j+1] = unos[0][j];
				
				unos[1][j] = temp;
				unos[0][j] = posTemp;
			}
		}
	}
	
	int matNueva[n][n];
	//filas ordenadas
	for(int i = 0; i<n; i++)
	{
		int pos = unos[0][i];
		for(int j = 0; j<n; j++)
		{
			matNueva[i][j] = matAdy[pos][j];
		}	
	}		
	
	//columnas ordenadas
	int matFinal[n][n];
	for(int i = 0; i<n; i++)
	{
		int pos = unos[0][i];
		for(int j = 0; j<n; j++)
		{
			matFinal[j][i] = matNueva[j][pos];
		}	
	}
	
	cout<<endl;
	cout<<"\nMatriz final"<<endl;
	cout<<"\t";
	for(int i = 0; i<n ; i++)
	{
		cout<<unos[0][i]<<" ";
	}
	cout<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<unos[0][i]<<"\t";
		for(int j = 0; j<n; j++)
		{
			cout<<matFinal[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl<<endl;
	//recorrer diagonal principal e imprimir nodos
	cout<<"Las componentes conexas seran: "<<endl;
	for(int i = 0; i<n; i++)
	{
		//cout<<matFinal[i][i]<<", ";
		cout<<unos[0][i]<<", ";
		if(matFinal[i+1][i] == 0)
		{
			cout<<endl;
		}
	}
	
}

