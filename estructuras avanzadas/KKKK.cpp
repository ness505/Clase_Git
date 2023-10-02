/*
Programa que crea una matriz de adyacencia para un grafo

Evelyn Vanessa Campos Aguayo
Fecha 07/09/2023
*/
#include <iostream>

using namespace std;

int main() {
    int numNodos, numAristas, type;
    cout << "\n== GRAFOS DIRIGIDOS Y NO DIRIGIDOS =="<<endl;
	cout << "\nEl grafo es dirigido (1) o no dirigido (0): ";
    cin >> type;
    

    cout << "\nIngrese el número de nodos: ";
    cin >> numNodos;

    cout << "Ingrese el número de aristas: ";
    cin >> numAristas;

    // Crear una matriz de adyacencia como un vector de vectores
    int matrizAdyacencia[numNodos][numNodos];
     //llenar la matriz de ceros
    for(int i = 0; i<numNodos; i++)
    {
    	for (int j = 0; j < numNodos; j++) {
            matrizAdyacencia[i][j]=0;
        }
	}

    // Leer las aristas y actualizar la matriz de adyacencia
    for (int i = 0; i < numAristas; i++) {
        int nodoA, nodoB;
        cout << "\nIngrese la arista " << i + 1 << " (nodo_A nodo_B): ";
        cin >> nodoA >> nodoB;

/*      VALIDACION  // Asegurarse de que los nodos estén en el rango válido
        if (nodoA >= 0 && nodoA < numNodos && nodoB >= 0 && nodoB < numNodos) {
*/
        matrizAdyacencia[nodoA][nodoB] = 1;
        if(type==0) // Si el grafo es no dirigido
        {
            matrizAdyacencia[nodoB][nodoA] = 1; 
		}
/*   VALIDACION     } else {
            cout << "Nodo(s) fuera de rango. Ignorando la arista." << endl;
        }
*/
    }

    // Imprimir la matriz de adyacencia
    cout << "\nMatriz de adyacencia:" << endl<<endl;
    
	//num columna
    cout<<"   ";
    for(int k = 0; k< numNodos; k++){ cout<<k<<" "; }
    cout<<endl;
    
    //imprimir
    for (int i = 0; i < numNodos; i++) {
    	cout<<i<<"  "; //numero de fila
        for (int j = 0; j < numNodos; j++) {
        	cout << matrizAdyacencia[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
