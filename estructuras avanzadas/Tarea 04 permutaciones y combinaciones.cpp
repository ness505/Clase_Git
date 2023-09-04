#include <iostream>
#include <vector>
using namespace std;


int fact(int);

void generatePermutations(vector<int>& elements, vector<int>& permutation, vector<bool>& used, int r) {
    if (permutation.size() == r) {		//la longitud del vector permutacion es igual a r
        for (int i =0; i<permutation.size(); i++) {
            cout << permutation[i] << " ";	//imprimimos la permutacion
        }
        cout << endl;
        return;		//regresa a la funcion anterior
    }
	
	//recorremos el arreglo
    for (int i = 0; i < elements.size(); ++i) { 
        if (!used[i]) {			//verifica si el elemento en la posición i del vector used es false
            used[i] = true;		//cambiamos a true para no repetirlo
            permutation.push_back(elements[i]);		//agregamos el elemento a la permutacion
            generatePermutations(elements, permutation, used, r);		//llamamos de nuevo a la funcion
            used[i] = false;		//cambiamos a false el ultimo elemento agregado a la permutacion 
            permutation.pop_back();	//sacamos el ultimo elemento agregado a la permutacion
        }
    }
}



int main() {
    int n, r;
    cout << "\n\tIngrese el valor de n: ";
    cin >> n;
    
    do  //validar r
    {
    	cout << "\tIngrese el valor de r: ";
    	cin >> r;
    	
	}while( r > n );cout<<endl;
	
    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        cout<<"\tPosicion "<<i+1<<": ";cin>>elements[i];	//guardamos los elementos en el vector
    }
    
    //cantidad de permutaciones
	int permu= fact(n)/fact(n-r);    // n! / (n-r)!
	cout<<"\n\tCantidad de permutaciones con R = "<<r<<": "<<permu<<endl;

    vector<int> permutation;	//aqui se guarda cada permutacion, al inicio esta vacia
    vector<bool> used(n, false);	//vector de n elementos, todos en false
    generatePermutations(elements, permutation, used, r);

    return 0;
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

