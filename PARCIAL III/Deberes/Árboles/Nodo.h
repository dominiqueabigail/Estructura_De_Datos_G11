/**************************************************************
                UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
    Pograma para crear la altura de un arbol binario
    Autores: MORALES B, SALAZAR D.
    Fecha de creación: 14/02/2022
    Fecha de modificación: 14/02/2022
    Versión: V1.0
                      Estructura de Datos 7166
****************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
class Nodo
{
private:

public:
    void setDato(int);
    void setIzquierda(Nodo*);
    void setDerecha(Nodo*);
    int getDato();
    Nodo*& getIzquierda();
    Nodo*& getDerecha();
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    int altura;
    /*devuelve la informacion del nodo*/
};
Nodo* raiz = NULL;

void Nodo::setDato(int _dato) {
    dato = _dato;
}
void Nodo::setIzquierda(Nodo* _izquierda) {
    izquierda = _izquierda;
}
void Nodo::setDerecha(Nodo* _derecha) {
    derecha = _derecha;
}
int Nodo::getDato() {
    return dato;
}
Nodo*& Nodo::getIzquierda() {
    return izquierda;
}
Nodo*& Nodo::getDerecha() {
    return derecha;
}