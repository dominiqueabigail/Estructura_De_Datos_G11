/**********************************************************
                UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
    Pograma para EL ANALISIS de Notacion asintotica
    Autores: MORALES B, SALAZAR D, CUEVA F, ANDRANGO C.
    Fecha de creación: 07/02/2022
    F/echa de modificación:07/02/2022
    Versión: V1.0
                      Estructura de Datos 7166
**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Procesos.h"


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


