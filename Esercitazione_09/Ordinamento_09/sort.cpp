#include <iostream>
#include <vector>
#include <algorithm> // necessario per utilizzare la funzione sort

using namespace std;

int main() {
	int i, j, k; //Contatori.
	int dim; //Dimensione vettore.
    vector <int> vettore = {9, 3, 5, 4, 2, 7, 8, 0, 6, 1}; //Vettore da ordinare.

    dim = vettore.size();
	
    cout << "Vettore originale: \n";
    for(i=0; i<dim; i++){
        cout << vettore[i] << " ";
	}
    cout << endl;

    // Utilizziamo la funzione sort per ordinare il vettore
    sort(vettore.begin(), vettore.end());

    cout << "Vettore ordinato: \n";
    for(j=0; j<dim; j++){
        cout << vettore[j] << " ";
	}
    cout << endl;

    // Utilizziamo la funzione sort per ordinare il vettore in ordine inverso
    sort(vettore.begin(), vettore.end(), greater<int>());

    cout << "Vettore ordinato in ordine dal piu' grande: \n";
    for(k=0; k<dim; k++){
        cout << vettore[k] << " ";
	}
    cout << endl;

    return 0;
}

/*int main() {
    vector <int> vettore = {10, 7, 8, 9, 1, 5};

    cout << "Vettore originale: \n";
    for (int i : vettore)
        cout << i << " ";
    cout << endl;

    // Utilizziamo la funzione sort per ordinare il vettore
    sort(vettore.begin(), vettore.end());

    cout << "Vettore ordinato: \n";
    for (int i : vettore)
        cout << i << " ";
    cout << endl;

    // Utilizziamo la funzione sort per ordinare il vettore in ordine inverso
    sort(vettore.begin(), vettore.end(), greater<int>());

    cout << "Vettore ordinato in ordine dal più grande: \n";
    for (int i : vettore)
        cout << i << " ";
    cout << endl;

    return 0;
}*/