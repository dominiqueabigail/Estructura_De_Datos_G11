/**********************************************************
                UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
    Pograma para EL ANALISIS de Notacion asintotica
    Autores: MORALES B, SALAZAR D.
    /echa de creación: 07/02/2022
    F/echa de modificación:07/02/2022
    Versión: V1.0
                      Estructura de Datos 7166
**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructura.h"
/////////////////////////////////////////////
void insertSort(Numero registros[],int n){
    int i,j;
    for(i=1;i<n;i++){  //RECORRE la entra pq es el arreglo y lo hace con incrementos constantes 1 en 1 y se ejecuta n veces - BIG 0 DE n 
        j=i;            
        while(j>0 && registros[j].id<registros[j-1].id){  //En el while se ejecutara mas veces que las n que toma la anterior linea  Tiene un condicion que va determinar cuando es que se sale de este ciclo y como es big O se tardara lo mas que pueda
            intercambia(&(registros[j]),&(registros[j-1]));
            j--; //Va a recorrer la entrar dependiendo las iteraciones  utilizando la j con decrementos constantes de 1 en 1 entonces queda que en el while se ejecutara n veces por el for en veces igual   n*n o n^2
        }
    }
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
int main()
{
    int n;
    printf("BUBBLE SORT...\n");
    printf("Numero de registros a ordenar:");
    scanf("%d",&n);
    Numero numeros[n];

    genera(numeros,n);
    printf("1)Registros a ordenar...\n");
    listar(numeros,n);
    insertSort(numeros,n);
    printf("2)Registros ordenados...\n");
    listar(numeros,n);

    return 0;
}


