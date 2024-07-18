#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int partition(vector <int>, int, int); //Funzione che riarrangia gli elementi attorno al pivotale.
void quicksort(vector <int>, int, int); //Funzione quicksort ricorsiva.

int main(int argc, char * argv[]){

   /*int a, b; //Posizioni da scambiare passate da terminale.
   a = atoi(argv[1]);
   b = atoi(argv[2]);*/

   int i, j; //Contatori.
   int dim; //Dimensione del vector.
   vector <int> vett; //Vettore da ordinare.
   
   //{9, 3, 5, 4, 2, 7, 8, 0, 6, 1}; 

   vett.push_back(9);
   vett.push_back(3);
   vett.push_back(5);
   vett.push_back(4);
   vett.push_back(2);
   vett.push_back(7);
   vett.push_back(8);
   vett.push_back(0);
   vett.push_back(6);
   vett.push_back(1);
   
   dim = vett.size();
   
   for(i=0; i<dim; i++){
      cout << vett[i] << "  "; 	   
   }   
   cout << endl; 

   //Per vector il metodo dello scambio delle tre carte non funziona:
   //bisogna usare la funzione swap della classe vector.
   //swap(vett[a], vett[b]);
   
   quicksort(vett, 0, dim-1);
   
   for(j=0; j<dim; j++){
      cout << vett[j] << "  "; 	   
   }   
   cout << endl; 
     
   return 0;
   
}

//Funzione di partizione per riarrangiare gli elementi attorno al pivotale.
int partition(vector <int> arr, int alfa, int omega){
   int pivot = arr[alfa]; //Elemento pivotale, attorno al quale avviene lo scambio.
   int count = 0; //Contatore nel vettore.
   int i, j, k; //Contatori dei cicli.
   
   for(k=alfa+1; k<=omega; k++) {
      if(arr[k] <= pivot){
	     //cout << arr[k] << "  " << pivot << endl;   
         count++;
      }			
   }
   //cout << "count = " << count << endl;
   
   int pivotIndex = alfa + count; //Dove si trova il pivotale nel vettore.
   //cout << arr[pivotIndex] << "  " << arr[alfa] << endl; 
   
   swap(arr[pivotIndex], arr[alfa]); //Assegno il pivotale all'elemento iniziale dell'intervallo.
   //cout << arr[pivotIndex] << "  " << arr[alfa] << endl; 

   i = alfa; //Assegno ai contatori i ruoli di inizio e fine
   j = omega; //del sottointervallo (partizione) da invertire.
   //cout << i << "  " << pivotIndex << "  " << j << endl;
   
   //ALGORITMO DI ORDINAMENTO QUICKSORT. 
   //Prendi un sottointervallo all'interno del vettore e passa in rassegna gli elementi dell'intervallo. 
   //Metti a sinistra quelli più piccoli del pivotale e a destra quelli più grandi, in ordine crescente. 
   //Ripeti il ciclo spostando il sottointervallo all'interno del vettore, fino ad ordinarlo tutto.
   
   while(i < pivotIndex && j > pivotIndex){	
      //cout << "Sono entrato nel ciclo while." << endl;  
	  
      while(arr[i] <= pivot){
         i++;
      }
      while(arr[j] > pivot){
         j--;
      }	  
      if(i < pivotIndex && j > pivotIndex){
         swap(arr[i], arr[j]);
	     //cout << arr[i] << "   " << arr[j] << endl;
		 //cout << "----------------------." << endl;
      }
   }
   
   return pivotIndex;	
}

//Funzione quicksort ricorsiva.
void quicksort(vector <int> arr, int alfa, int omega){
   int p; 
   //Fai lo scambio e metti in ordine crescente se il primo elemento 
   //dell'intervallo è più piccolo dell'ultimo, altrimenti non fare nulla.   
   if(alfa <= omega){ 
      p = partition(arr, alfa, omega);
      quicksort(arr, alfa, p - 1);
      quicksort(arr, p + 1, omega);
   }
}