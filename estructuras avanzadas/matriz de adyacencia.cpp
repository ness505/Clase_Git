#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numNodos, numAristas, type;
    
    cout << "El grafo es dirigido (1) o no dirigido (0): ";
    cin >> type;
	
    cout << "Ingrese el número de nodos: ";
    cin >> numNodos;

    cout << "Ingrese el número de aristas o arcos: ";
    cin >> numAristas;

    // Crear una matriz de adyacencia como un vector de vectores
    vector<vector<int>> matrizAdyacencia(numNodos, vector<int>(numNodos, 0));

    // Leer las aristas y actualizar la matriz de adyacencia
    for (int i = 0; i < numAristas; i++) {
        int nodoA, nodoB;
        cout << "Ingrese la arista " << i + 1 << " (nodoA nodoB): ";
        cin >> nodoA >> nodoB;

        // Asegurarse de que los nodos estén en el rango válido
        if (nodoA >= 0 && nodoA < numNodos && nodoB >= 0 && nodoB < numNodos) {
        	
            matrizAdyacencia[nodoA][nodoB] = 1;
            if(type==0) // Si el grafo es no dirigido
            {
            	matrizAdyacencia[nodoB][nodoA] = 1; 
			}
            
        } else {
            cout << "Nodo(s) fuera de rango. Ignorando la arista." << endl;
        }
    }

    // Imprimir la matriz de adyacencia
    cout << "Matriz de adyacencia:" << endl<<endl;
    
	//num columna
    cout<<"   ";
    for(int k = 0; k< numNodos; k++){ cout<<k<<" "; }
    cout<<endl;
    
    for (int i = 0; i < numNodos; i++) {
    	cout<<i<<"  "; //numero de fila
        for (int j = 0; j < numNodos; j++) {
            cout << matrizAdyacencia[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
