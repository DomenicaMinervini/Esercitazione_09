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

void exchange(int[], int, int); //Funzione che scambia gli elementi del vettore.
int partition(int[], int, int); //Funzione che riarrangia gli elementi attorno al pivotale.
void quicksort(int[], int, int); //Funzione quicksort ricorsiva.

int main(){
   int i; //Contatore.
   int n = 10; //Dimensione vettore.
   int arr[n] = {9, 3, 5, 4, 2, 7, 8, 0, 6, 1}; //Vettore da ordinare.
   
   for (i=0; i<n; i++) {
      cout << arr[i] << "  ";
   }	
   cout << endl;
   
   quicksort(arr, 0, n-1);
   
   for (i=0; i<n; i++){
      cout << arr[i] << "  ";
   }	
   cout << endl;
   
   return 0;	
	
}

void exchange(int arr[], int alfa, int beta){
   int temp; //Variabile di appoggio.
   //Scambio le posizioni alfa e beta di arr[].
   
   temp = arr[alfa]; //Lo metto al sicuro.
   arr[alfa] = arr[beta]; //Lo posso sovrascrivere.
   arr[beta] = temp; //Ricompare il valore iniziale.

   //cout << "SCAMBIO." << endl;   
}

//Funzione di partizione per riarrangiare gli elementi attorno al pivotale.
int partition(int arr[], int begin, int end){
   int pivot = arr[begin]; //Elemento pivotale, attorno al quale avviene lo scambio.
   int count = 0; //Contatore nel vettore.
   int i, j, k; //Contatori dei cicli.
   
   for(k=begin+1; k<=end; k++) {
      if(arr[k] <= pivot){
	     //cout << arr[k] << "  " << pivot << endl;   
         count++;
      }			
   }
   //cout << "count = " << count << endl;
   
   int pivotIndex = begin + count; //Dove si trova il pivotale nel vettore.
   exchange(arr, pivotIndex, begin); //Assegno il pivotale all'elemento iniziale dell'intervallo.
   
   i = begin; //Assegno ai contatori i ruoli di inizio e fine
   j = end; //del sottointervallo (partizione) da invertire.
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
         exchange(arr, i, j); 
	     //cout << arr[i] << "   " << arr[j] << endl;
		 //cout << "----------------------." << endl;
      }
   }
   
   return pivotIndex;	
}

//Funzione quicksort ricorsiva.
void quicksort(int arr[], int begin, int end){
   int p; 
   //Fai lo scambio e metti in ordine crescente se il primo elemento 
   //dell'intervallo è più piccolo dell'ultimo, altrimenti non fare nulla.   
   if(begin <= end){ 
      p = partition(arr, begin, end);
      quicksort(arr, begin, p - 1);
      quicksort(arr, p + 1, end);
   }
}