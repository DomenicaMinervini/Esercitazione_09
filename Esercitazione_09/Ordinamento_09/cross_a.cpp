#include <iostream>
#include <cmath>
#include <vector>

using namespace std; 

int main(){

   int i, j, k; //Contatori.
   int dim; //Dimensione iniziale dei genitori e finale dei figli.
   int dim_fa, dim_mo, dim_so, dim_da; //Dimensioni dei vettori.       
   int cut = 4; //Dove farò il taglio per fare crossover.

   //Genitori che faranno crossover.   
   vector <int> father = {0,1,2,3,4,5,6,7,8,9};
   vector <int> mother = {0,3,6,5,2,4,1,9,7,8};  
   //Figli che nasceranno dall'unione dei genitori.
   vector <int> son;
   vector <int> daughter;  
   //Salvo le componenti dei genitori, visto che saranno cancellate.   
   vector <int> appo_father; 
   vector <int> appo_mother; 
   
   appo_father = father;   
   appo_mother = mother;   

   //Dimensioni iniziali di padre e madre.
   dim = father.size();
   dim_fa = dim;
   dim_mo = dim;
   cout << "Dimensione iniziale genitori = " << dim_fa << endl;
   cout << endl << "-------------------------" << endl;   
  
   for(i=0; i<dim_fa; i++){
      cout << father[i] << "   ";    
   }

   cout << endl << "-------------------------" << endl;   
  
   for(j=0; j<dim_mo; j++){
      cout << mother[j] << "   ";    
   }
 
   cout << endl << "-------------------------" << endl;   
 
   //------CROSSOVER: il figlio è il risultato del crossover tra padre e madre.
   //1) La parte prima del taglio è la stessa di quella del padre.
   for(k=0; k<cut+1; k++){
      son.push_back(father[k]);	   
   }
 
   //2) Cancello nella madre gli elementi che sono già presenti nel figlio. 
   for(j=0; j<cut+1; j++){ //Per tutti gli elementi presenti per ora nel figlio.
      for(i=0; i<dim; i++){ //Per tutti gli elementi presenti nella madre. Size = dim_par_one = 10.
         if(son[j] == mother[i]){ //Quando trovo l'elemento presente sia nella madre sia nel figlio
		    mother.erase(mother.begin()+i); //lo elimino dal vettore madre, altrimenti non fa nulla.
			break; //Appena trovi l'elemento da eliminare esci dal ciclo: non serve controllare anche quelli dopo.
		 }
      }		  
   }

   //Dopo le aggiunte al figlio e i tagli alla madre, le loro dimensioni sono cambiate.
   dim_so = son.size();
   dim_mo = mother.size();
   cout << "Dimensione figlio = " << dim_so << endl;
   cout << endl << "-------------------------" << endl;   
   
   for(i=0; i<dim_so; i++){
      cout << son[i] << "   ";    
   }

   cout << endl << "-------------------------" << endl;   
  
   for(j=0; j<dim_mo; j++){
      cout << mother[j] << "   ";    
   }
 
   cout << endl << "-------------------------" << endl;   
   
   //3) Gli elementi mancanti nel figlio sono quelli che ha adesso la madre, proprio in quell'ordine.
   for(k=cut+1; k<dim_fa; k++){
      son.push_back(mother[0]);     //Aggiungo in coda al figlio il primo elemento della madre.
	  mother.erase(mother.begin()); //Alla madre cancello il primo elemento, così al prossimo ciclo aggiungo in coda al figlio
	                                //sempre il primo elemento della madre, in modo che si mantenga l'ordine del vettore madre.
									
									//mother.begin(): è il primo elemento del vettore e bisogna specificarlo sempre quando si usa
									//la funzione erase() di vector, per specificare quale posizione cancellare.
									//Esempio: se vuoi cancellare la posizione i del vector v, devi dire a erase v.begin()+i.
   }   

   //Adesso il figlio ha la stessa dimensione che avevano i genitori all'inizio. Gli elementi della madre sono tutti cancellati.
   dim_so = son.size();
   dim_mo = mother.size();
   cout << "Dimensione figlio = " << dim_so << endl;
   cout << endl << "-------------------------" << endl;   
   
   for(i=0; i<dim_so; i++){
      cout << son[i] << "   ";    
   }

   cout << endl << "-------------------------" << endl;   
  
   for(j=0; j<dim_mo; j++){
      cout << mother[j] << "   ";    
   }
 
   cout << endl << "-------------------------" << endl;   
  	
   return 0;
   
}
