/*Abbiamo visto l'algoritmo di ordinamento QuickSort nel corso di Informatica della laurea Triennale in Fisica. 
Il codice che segue ordina gli elementi di un vettore di numeri interi positivi dal più piccolo al più grande.
Di questo codice, ai fini dell'Esercitazione 9, è importante la logica. Per svolgere l'esercitazione lo dovrò 
modificare in modo da adeguarlo al contesto: l'algortmo dovrà ordinare gli elementi del vector <Trip> population. 
Di tutti gli elementi Trip dovrò calcolare la distanza del percorso e ordinare il vector <Trip> in modo che 
all'inizio ci siano quelli con distanza più corta e alla fine quelli con distanza più lunga. Le distanze sono 
dei valori double ordinate dalla più piccola alla più grande. Nel codice ci sarà scritto anche un algoritmo 
roulette truccata che selezionerà con una probabilità più alta gli elementi all'inizio del vettore, ossia quelli 
con una distanza più breve. Loro sono gli elementi migliori della popolazione, quelli che vorrei fare riprodurre. 
L'algoritmo roulette truccata può selezionare anche gli elementi peggiori, ma con una probabilità più piccola.*/ 

#include <iostream>
using namespace std;

// Partition function to rearrange elements around the pivot
int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

// Recursive QuickSort function
void quickSort(int arr[], int start, int end) {
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main() {
    //int arr[] = {9, 3, 4, 2, 1, 8};
    //int n = 6; // Dimension array.
    int arr[] = {9, 3, 5, 4, 2, 7, 8, 0, 6, 1};
    int n = 10;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}