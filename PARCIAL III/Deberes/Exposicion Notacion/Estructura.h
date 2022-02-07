#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

typedef struct{
    int id;
}Numero;

void intercambia(Numero* x, Numero* y);
void listar(Numero registros[],int n);
void ordenar(Numero registros[],int n);

void intercambia(Numero* x, Numero* y){
    Numero temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void listar(Numero registros[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\t%d\n",registros[i]);
    }
}

#endif
