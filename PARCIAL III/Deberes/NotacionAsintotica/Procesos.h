#include "Estructura.h"
/////////////////////////////////////////////
void insertSort(Numero registros[],int n){
    int i,j;
    for(i=1;i<n;i++){                                           //n
        j=i;                                                    //n
        while(j>0 && registros[j].id<registros[j-1].id){        //n*n
            intercambia(&(registros[j]),&(registros[j-1]));     //n*n
            j--;                                                //n*n
        }
    }
    // 3n^2+4n+1=  O(n^2)
    printf("Terminado.\n");
    //sumando los registro de los ciclos for y while nos quedaria como Big 0 (n^2)
}
///////////////////////////////////////////////////
void genera(Numero numeros[],int n){
    int i,j;
    for(i=0,j=n;i<n;i++,j--){       //GENERA DE MAYOR A MENOR
        numeros[i].id=j;
    }
}
/////////////////////////////////////////////////////

