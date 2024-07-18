#include <iostream>
using namespace std;

//Funzione che scambia due componenti del vettore.
void exchange(int alfa, int beta){
   int temp; //Variabile d'appoggio in cui conservo il primo elemento da scambiare.

   temp = alfa; //Lo metto al sicuro.
   alfa = beta; //Lo posso sovrascrivere.
   beta = temp; //Ricompare il valore iniziale.
}

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
            swap(arr[i], arr[j]); //i++ e j--
			cout << arr[i] << "   " << arr[j] << endl;
        }
    }
    return pivotIndex;
}

// Recursive QuickSort function
void quickSort(int arr[], int start, int end) {
	int p; 
	
	if (start <= end){
        p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
	}
		
/*	
    if (start >= end){
    }
	else{
        p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
	}*/
}

int main() {
    //int arr[] = {9, 3, 4, 2, 1, 8};
    //int n = 6; // Dimension array.
    int arr[] = {9, 3, 5, 4, 2, 7, 8, 0, 6, 1};
    int n = 10;
	
	cout << "Prima dello scambio." << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }	
	cout << endl;
    quickSort(arr, 0, n - 1);
	
	cout << endl << "Dopo lo scambio." << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
	
    return 0;
}