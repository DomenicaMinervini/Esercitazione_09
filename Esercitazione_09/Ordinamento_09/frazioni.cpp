#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char * argv[]){

   int figure; //Seleziona il problema del cerchio o nel quadrato.
   int num; //Numero di elementi della popolazione.
   int generations; //Numero di generazioni. 
   
   int dim = 34; //Numero di elementi del vector Trip = numero di citta'.
   int ter_dim; //Un terzo di dim.

   int half_num; //Meta' del numero di elementi della popolazione.
   int ten_num; //Numero di elementi della popolazione che viene mutato dopo crossover.
   
   int elite; //Numero di elementi della popolazioni che fanno elitarismo.
   int half_elite; //Meta' degli elementi che fanno elitarismo. 
   
   if(argc != 4){
	  cout << "Per eseguire il codice bisogna passare i seguenti parametri da terminale: " << endl;
      cout << "argv[0] = nome eseguibile = ./TSP.exe." << endl;
	  cout << "argv[1] = numero intero per scegliere tra circonferenza o quadrato = 0 o altro." << endl;
	  cout << "argv[2] = numero intero per gli elementi della popolazione." << endl;
	  cout << "argv[3] = numero intero per le generazioni della popolazione." << endl;
	  return 1;
   }
   
   //Assegno i valori passati da terminale.
   figure = atoi(argv[1]); 
   num = atoi(argv[2]);   
   generations = atoi(argv[3]);

   if(figure == 0){ //Comunica che problema hai scelto.
      cout << "Hai scelto il problema sulla circonerenza." << endl;    
   }
   else{
      cout << "Hai scelto il problema nel quadrato." << endl;
      cout << "Se vuoi scegliere il problema sulla circonferenza digita 0." << endl;	  
   }   
   
   cout << "Numero di generazioni = " << generations << endl;
   
   ter_dim = int(0.333333*dim); //Le mutazioni all'inizio sono un terzo del numero delle citta'.  
   cout << "Mutazioni all'inizio per ogni percorso = " << ter_dim << endl;
      
   if(num % 2 == 1){ //Il numero degli elementi della popolazione deve essere pari.
      num = num-1; //Se non lo e' ci pensa il codice a modificarlo.
   }   
   cout << "Hai inserito numero elementi della popolazione = " << num << endl;
   
   half_num = int(0.5*num); //Calcolo la meta' migliore degli elementi della popolazione.
   cout << "Meta' degli elementi della popolazione = " << half_num << endl;
   
   elite = 2.0*int(0.5*(0.01*num)); //L'1% della popolazione fa elitarismo.  
   //Deve essere un numero pari e deve si applica ad una popolazione di almeno 200 elementi.  
   cout << "Numero di elementi della popolazione che fa elitarismo = " << elite << endl;   

   half_elite = int(0.5*elite); //Serve per assegnare i posti nella nuova popolazione dopo crossover.
   cout << "Meta' degli elementi della popolazione che fa elitarismo = " << half_elite << endl;   
   
   ten_num = int(0.1*num); //Vengono mutati un decimo della popolazione finale.
   cout << "Numero di elementi della popolazione che viene mutato = " << ten_num << endl;

   return 0;   
		
}