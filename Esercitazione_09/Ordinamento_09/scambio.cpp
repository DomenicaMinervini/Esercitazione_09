#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
   const int dim=10;
   int i,j,k;
   int vett[dim];
   int temp;

   for(i=0;i<dim;i++){
      vett[i]=i;
   }

   cout << "Configurazione iniziale:  " << endl;
   for(j=0;j<dim;j++){
      cout<< vett[j] << endl;
   }
   cout << "Scambio 3 con 7." << endl;

   temp = vett[3]; //lo metto al sicuro
   vett[3] = vett[7]; //lo posso sovrascrivere
   vett[7] = temp; //ricompare il valore iniziale

   cout << "Configurazione scambiata:  " << endl;
   for(k=0;k<dim;k++){
      cout<< vett[k] << endl;
   }

   return 0;

}
