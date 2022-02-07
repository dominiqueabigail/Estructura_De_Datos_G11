#include "Matriz.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::Matriz(int _d)
// Purpose:    Implementation de Matriz::Matriz()
// Parametros:
// - _d
// Return:   
////////////////////////////////////////////////////////////////////////
Matriz::Matriz(int _d)
{
	this->dim = _d;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::segmentar()
// Purpose:    Implementation de Matriz::segmentar()
// Parametros:
// Return:    matriz
////////////////////////////////////////////////////////////////////////
int** Matriz::segmentar()
{
	this->matriz = (int**)malloc(dim * sizeof(int*));
	for (int i = 0; i < dim; i++) {
		*(this->matriz + i) = (int*)malloc(dim * sizeof(int));
	}
	return matriz;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::encerar()
// Purpose:    Implementation de Matriz::encerar()
// Parametros:
// Return:   
////////////////////////////////////////////////////////////////////////
void Matriz::encerar() {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			*(*(matriz + i) + j) = 0;
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::generar()
// Purpose:    Implementation de Matriz::generar()
// Parametros:
// Return:    
////////////////////////////////////////////////////////////////////////
void Matriz::generar() {
	int contador = 0, aux = 0;
	int fila = 0, columna = 0;
	for (int i = 1; i <= dim; i++) {
		for (int j = 1; j <= dim; j++)
		{
			aux = j + contador;
			if (aux <= dim) {
				*(*(matriz + fila) + columna) = aux;
			}
			else {
				*(*(matriz + fila) + columna) = aux - dim;
			}
			columna += 1;
		}
		columna = 0;
		contador += 1;
		fila += 1;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::imprimir()
// Purpose:    Implementation de Matriz::imprimir()
// Parametros:
// Return:    
////////////////////////////////////////////////////////////////////////
void Matriz::imprimir() {
	std::cout << "\n";
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			std::cout << "\t" << *(*(matriz + i) + j);
		}
		std::cout << "\n";
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::getMatriz()
// Purpose:    Implementation de Matriz::getMatriz()
// Parametros:
// Return:    matriz
////////////////////////////////////////////////////////////////////////
int** Matriz::getMatriz()
{
	return  matriz;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::getDim()
// Purpose:    Implementation de Matriz::getDim()
// Parametros:
// Return:    dim
////////////////////////////////////////////////////////////////////////
int Matriz::getDim()
{
	return dim;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::setMatriz(int** _matriz)
// Purpose:    Implementation de Matriz::setMatriz()
// Parametros:
// - _matriz
// Return:   
////////////////////////////////////////////////////////////////////////
void Matriz::setMatriz(int** _matriz) {
	this->matriz = _matriz;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matriz::setDim(int _d)
// Purpose:    Implementation de Matriz::setDim()
// Parametros:
// - _d
// Return:    
////////////////////////////////////////////////////////////////////////
void Matriz::setDim(int _d)
{
	this->dim = _d;
}