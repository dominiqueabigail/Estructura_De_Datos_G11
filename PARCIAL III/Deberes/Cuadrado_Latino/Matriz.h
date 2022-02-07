
#pragma once
class Matriz
{
private:
	int** matriz;
	int dim;
public:
	Matriz() = default;
	Matriz(int);
	int** segmentar();
	void encerar();
	void generar();
	void imprimir();
	int** getMatriz();
	int getDim();
	void setMatriz(int**);
	void setDim(int);
};

