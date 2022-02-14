/**************************************************************
                UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
    Pograma para crear la altura de un arbol binario
    Autores: MORALES B, SALAZAR D.
    Fecha de creación: 14/02/2022
    Fecha de modificación: 14/02/2022
    Versión: V1.0
                      Estructura de Datos 7166
****************************************************************/
#pragma once
#include "Nodo.h"
#include <iostream>
class Arbol
{
private:
    Nodo* arbol = NULL;
    int a1_iz;
    int a2_der;
    Nodo Raiz;
public:
    void setArbol(Nodo*);
    Nodo* getArbol();
    Nodo* crearNodo(int);
    void insertarNodo(Nodo*&, int);
    void mostrar(Nodo*, int);
    bool buscar(Nodo*, int);
    void preOrden(Nodo*);
    void inOrden(Nodo*);
    void postOrden(Nodo*);
    int maximaAltura(int a1_iz, int a2_der);
    int alturaArbolbin(Nodo* padre);
    int nivel(Nodo);
    int contador(Nodo& aux);
    int cantidadNiveles(Nodo* aux);
    int anchura(Nodo* aux);
    int nodoN(Nodo* aux, int n);
    Nodo getRaiz();
};
Nodo Arbol::getRaiz()
{
    return Raiz;
}
int Arbol::nodoN(Nodo* aux, int n)
{
    if (aux != NULL)
    {
        if (n == 0)
        {
            return nodoN(aux->izquierda, n - 1) + nodoN(aux->derecha, n - 1) + 1;
            return nodoN(aux->izquierda, n - 1) + nodoN(aux->derecha, n - 1);
        }
        return 0;
    }
}

int Arbol::anchura(Nodo* aux)
{
    if (aux != NULL)
    {
        int izquier = anchura(aux->izquierda);
        int derec = anchura(aux->derecha);
        int medio = 1;
        return medio + derec + izquier;
    }
    return 0;
}

int Arbol::cantidadNiveles(Nodo* aux) {
    if (aux != NULL) {
        int izq = cantidadNiveles(aux->izquierda) + 1;
        int der = cantidadNiveles(aux->derecha) + 1;
        if (izq > der) {
            return izq;
        }return der;


    }return -1;
}

int Arbol::maximaAltura(int a1_iz, int a2_der)
{
    if (a1_iz > a2_der)
    {
        return a1_iz;
    }
    else {
        return a2_der;
    }
}
int Arbol::alturaArbolbin(Nodo* padre)
{
    if (padre == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + maximaAltura(alturaArbolbin(padre->izquierda), alturaArbolbin(padre->derecha)));

    }
}

void Arbol::setArbol(Nodo* _arbol) {
    arbol = _arbol;
}
Nodo* Arbol::getArbol() {
    return arbol;
}
Nodo* Arbol::crearNodo(int dato) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->setDato(dato);
    nuevoNodo->setDerecha(NULL);
    nuevoNodo->setIzquierda(NULL);
    return nuevoNodo;
}
void Arbol::insertarNodo(Nodo*& arbol, int dato) {
    if (arbol == NULL) {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
    }
    else {
        int raiz = arbol->getDato();
        if (dato < raiz) {
            insertarNodo(arbol->getIzquierda(), dato);
        }
        else {
            insertarNodo(arbol->getDerecha(), dato);
        }
    }
}
/*Comprobamos si el arbol esta vacio, si ese es el caso creamos un nuevo nodo e
igualamos el arbol al nuevo nodo. Si el arbol cuenta con algén dato entonces creamos una
variable llamanda raiz para obtener si valor y establecer si el nuevo element va a la derecha o a
la izquierda*/

void Arbol::mostrar(Nodo* arbol, int contador) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostrar(arbol->getDerecha(), contador + 1);
        for (int i = 0; i < contador; i++) {
            cout << " ";
        }
        cout << arbol->getDato() << endl;
        mostrar(arbol->getIzquierda(), contador + 1);
    }
}
/*Comprobamos si el árbol está vacío entonces retornamos el árbol
vacío, caso contrario aplicamos recursividad para ir mostrando los
datos del árbol*/
bool Arbol::buscar(Nodo* arbol, int dato) {
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->getDato() == dato) {
        return true;
    }
    else if (dato < arbol->getDato()) {
        buscar(arbol->getIzquierda(), dato);
    }
    else {
        buscar(arbol->getDerecha(), dato);
    }
}

/*Para buscar un elemento comprobamos si el arbol está vacío, caso contrario verificamos
el nodo a ver si es el dato buscado, si este es menor buscamos a la derecha y si es mayor lo
buscamos a la izquierda*/
void Arbol::preOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->getDato() << " ";
        preOrden(arbol->getIzquierda());
        preOrden(arbol->getDerecha());
    }
}
/*El recorrido en preorden es: raiz, izquierda, derecha*/
void Arbol::inOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        inOrden(arbol->getIzquierda());
        cout << arbol->getDato() << " ";
        inOrden(arbol->getDerecha());
    }
}
/*El recorrido en inorden es: izquierda, raiz, derecha*/
void Arbol::postOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        postOrden(arbol->getIzquierda());
        postOrden(arbol->getDerecha());
        cout << arbol->getDato() << " ";
    }
}
/*El recorrido en postorden es: izquierda,derecha, raiz*/