/*
Tarea 02 Permutaciones y combinaciones 
Por Evelyn Vanessa Campos Aguayo 
Fecha: 09/08/2023

Nivel de entendimiento: muy bueno
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int fact(int);

int main()
{
	int n=5;
	cout<<"Cantidad de elementos: ";cin>>n;
	
	int nFact = fact(n);	//n!
	int fact2=0;
	
	//permutacion
	cout<<"\nPermutacion"<<endl;
	double permu=0;
	
	for(int r = 1; r<=n; r++)  //posibles valores de r
	{
		fact2 = fact(n-r);     //(n-r)!
		permu= nFact/fact2;    // n! / (n-r)!
		
		cout<<"R = "<<r<<": "<<permu<<endl;
	}
	cout<<endl<<endl;
	
	//combinacion 
	cout<<"Combinacion"<<endl;
	int rFact;
	double comb = 0;
	for(int r = 1; r<=n; r++)  //posibles valores de r
	{
		fact2 = fact(n-r);      //(n-r)!
		rFact = fact(r);	    //r!
		fact2 = fact2*rFact;	//(n-r)!r!
		
		comb = nFact/fact2;		// n! / (n-r)!r!
		cout<<"R = "<<r<<": "<<comb<<endl;
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
