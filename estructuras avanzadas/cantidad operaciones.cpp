#include <iostream>

using namespace std;

int main()
{
	int n, cont=0;
	cin>>n;
	cout<<endl;
	for(int i = 0; i<=n ; i++)
	{
		cont++;
		if(i%2==0)
		{
			cont++;
			cout<<i<<" ";
		}
		cont++;
	}
	cout<<endl;
	cout<<cont<<endl;
	cout<<"Cantidad de operaciones con 1 for y numeros pares: "<<( (2*(n+1)) + ((n+1)/2) )<<endl;
	
	cout<<"Cantidad de operaciones con 2 for y numeros pares e impares: "<< 2 * ( (2*(n+1)) + ((n+1)/2) );
	
	return 0;
}
