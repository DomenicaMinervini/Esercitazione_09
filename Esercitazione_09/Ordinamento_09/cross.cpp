#include <iostream>
#include <cmath>
#include <vector>

using namespace std; 

vector <int> Crossover(vector <int>, vector <int>, vector <int>);

int main(){

   int i, j; //Contatori.
   int dim; //Dimensione iniziale dei genitori e finale dei figli.

   //Genitori che faranno crossover.   
   vector <int> father = {0,1,2,3,4,5,6,7,8,9};
   vector <int> mother = {0,3,6,5,2,4,1,9,7,8};  
   //Figli che nasceranno dall'unione dei genitori.
   vector <int> firstborn;
   vector <int> secondborn;  
   //Salvo le componenti della madre, visto che saranno cancellate e che serviranno.   
   vector <int> appo_mother; 
   appo_mother = mother;   

   //Dimensioni iniziali di padre e madre.
   dim = father.size();
   cout << "Dimensione iniziale genitori = " << dim << endl;
   cout << endl << "-------------------------" << endl; 
  
   for(i=0; i<dim; i++){
      cout << father[i] << "   ";    
   }

   cout << endl << "-------------------------" << endl;   
  
   for(j=0; j<dim; j++){
      cout << mother[j] << "   ";    
   }
 
   cout << endl << "-------------------------" << endl;   
 
   //------CROSSOVER: i figli sono il risultato del crossover tra padre e madre.
   //Eseguo due volte il crossover con gli stessi genitori ma nell'ordine invertito.
   //Così si ottengono due figli diversi.
   cout << "------CROSSOVER ONE.------" << endl;
   firstborn = Crossover(father, mother, firstborn);  
   cout << "------CROSSOVER TWO.------" << endl;
   secondborn = Crossover(appo_mother, father, secondborn);
   
   //Ora che sono nati i figli, li posso sostituire ai genitori, passando il testimone alla nuova generazione.
   father = firstborn;
   mother = secondborn;
   
   cout << "La nuova generazione." << endl;
   
   for(i=0; i<dim; i++){
      cout << father[i] << "   ";    
   }

   cout << endl << "-------------------------" << endl;   
  
   for(j=0; j<dim; j++){
      cout << mother[j] << "   ";    
   }
 
   cout << endl << "-------------------------" << endl;  
   
   appo_mother.clear(); //Posso liberare i vettori di appoggio e dei due figli.
   firstborn.clear();   //Saranno riempiti dalla prossima generazione.
   secondborn.clear();  //I genitori sono stati cancellati e rimpiazzati dai figli.
   	
   return 0;
   
}

/*Funzione che fa il crossover tra due genitori. All'inizio son è un guscio vuoto.
Compiuto il crossover tra i cromosomi/genitori, la funzione restituisce un figlio. 
L'ordine in cui vengono passati i genitori alla funzione, determina i ruoli che 
hanno i genitori nel crossover e quindi come sarà il figlio.
parent_one: passa al figlio la parte prima del taglio, nell'ordine in cui si trova nel genitore.
parent_two: passa al figlio tutte le altre componenti, che non sono presenti nella parte prima 
del taglio, nell'ordine in cui si trovano nel genitore.*/

vector <int> Crossover(vector <int> parent_one, vector <int> parent_two, vector <int> son){
   int i, j, k; //Contatori.
   int dim_par_one, dim_par_two, dim_son; //Dimensioni dei vettori.       
   int cut = 4; //Dove farò il taglio per fare crossover.
   
   dim_par_one = parent_one.size();
   
   //1) La parte prima del taglio è la stessa di quella del primo genitore.
   for(k=0; k<cut+1; k++){
      son.push_back(parent_one[k]);	   
   }
 
   //2) Cancello nel secondo genitore gli elementi che sono già presenti nel figlio. 
   for(j=0; j<cut+1; j++){ //Per tutti gli elementi presenti per ora nel figlio.
      for(i=0; i<dim_par_one; i++){ //Per tutti gli elementi presenti nel secondo genitore. Size = dim_par_one = 10.
         if(son[j] == parent_two[i]){ //Quando trovo l'elemento presente sia nel secondo genitore sia nel figlio
		    parent_two.erase(parent_two.begin()+i); //lo elimino dal vettore secondo genitore, altrimenti non fa nulla.
			break; //Appena trovi l'elemento da eliminare esci dal ciclo: non serve controllare anche quelli dopo.
		 }
      }		  
   }

   //Dopo le aggiunte al figlio e i tagli al secondo genitore, le loro dimensioni sono cambiate.
   dim_son = son.size();
   dim_par_two = parent_two.size();
   cout << "Dimensione figlio = " << dim_son << endl;
   cout << endl << "-------------------------" << endl;   
   
   for(i=0; i<dim_son; i++){
      cout << son[i] << "   ";    
   }

   cout << endl << "-------------------------" << endl;   
  
   for(j=0; j<dim_par_two; j++){
      cout << parent_two[j] << "   ";    
   }
 
   cout << endl << "-------------------------" << endl;   
   
   //3) Gli elementi mancanti nel figlio sono quelli che ha adesso il secondo genitore, proprio in quell'ordine.
   for(k=cut+1; k<dim_par_one; k++){
      son.push_back(parent_two[0]);     //Aggiungo in coda al figlio il primo elemento del secondo genitore.
	  parent_two.erase(parent_two.begin()); //Alla secondo genitore cancello il primo elemento, così al prossimo ciclo aggiungo in coda al figlio 
	                                //sempre il primo elemento del secondo genitore, in modo che si mantenga l'ordine del vettore secondo genitore.
									
									//parent_two.begin(): è il primo elemento del vettore e bisogna specificarlo sempre quando si usa
									//la funzione erase() di vector, per specificare quale posizione cancellare.
									//Esempio: se vuoi cancellare la posizione i del vector v, devi dire a erase v.begin()+i.
   }   

   //Adesso il figlio ha la stessa dimensione che avevano i genitori all'inizio. Gli elementi del secondo genitore sono tutti cancellati.
   dim_son = son.size();
   dim_par_two = parent_two.size();
   cout << "Dimensione figlio = " << dim_son << endl;
   cout << endl << "-------------------------" << endl;   
   
   for(i=0; i<dim_son; i++){
      cout << son[i] << "   ";    
   }

   cout << endl << "-------------------------" << endl;   
  
   for(j=0; j<dim_par_two; j++){
      cout << parent_two[j] << "   ";    
   }
 
   cout << endl << "-------------------------" << endl;   
	
   return son;
   
}
