/*
Tarea 03 Sacar las posibles Permutaciones y combinaciones 
Por Evelyn Vanessa Campos Aguayo 
Fecha: 11/08/2023

Nivel de entendimiento: muy bueno
*/

#include <iostream>
#include <stdio.h>

using namespace std;

//funcion factorial
int fact(int);
void perm(int nFact, string arr[], int);

int main()
{
	int n=4;
	string arr[4]={"a","b","c","d"};
	
	cout<<"== ARREGLO =="<<endl;	//imprimir el arreglo
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"   ";
	}
	cout<<endl<<endl;
	
	int nFact = fact(n);	//n!
	int fact2=0;
	
	//permutacion
	perm( nFact,  arr,  n);
	
	//combinacion 
	cout<<"\n\nCombinacion"<<endl;
	int rFact;
	double comb = 0;
	
	fact2 = fact(n-2);      //(n-r)!
	rFact = fact(2);	    //r!
	fact2 = fact2*rFact;	//(n-r)!r!
		
	comb = nFact/fact2;		// n! / (n-r)!r!
	cout<<"N = 4"<<endl;
	cout<<"R = "<<2<<": "<<comb<<endl<<endl;
	
	string strComb="";
	
	for(int i =0 ; i<n-1; i++) //seleccionar el primer elemento, n-1 porque no llega al elemento final 
	{
		for(int j=i+1; j<n; j++)  //combinar con los demás elementos frente a el
		{
			strComb = arr[i] + arr[j];
			cout<<strComb<<" ";
		}
		cout<<endl;
	}
}

//funcion factorial
int fact(int num)
{
	if(num==0 || num ==1)
	{
		return 1;	//caso base, retornamos 1 
	}
	return num * fact(num-1);	//volvemos a llamar a la funcion
}

void perm(int nFact, string arr[], int n)
{
	//permutacion
	cout<<"\nPermutacion"<<endl;
	double permu=0;
	
	int fact2 = fact(n-2);     //(n-r)!
	permu= nFact/fact2;    // n! / (n-r)!
	cout<<"N = 4"<<endl;
	cout<<"R = "<<2<<": "<<permu<<endl;
	
	cout<<endl<<endl;
	
	string strPerm="";
	
	for(int i = 0; i<n; i++) //seleccionar 1 elemento
	{
		for(int j=0; j<n; j++) //permutar con los demás elementos
		{
			if(j!=i)
			{
				strPerm = arr[i] + arr[j];
				cout<<strPerm<<" ";
			}
		}
		cout<<endl;
	}
}





