#include "Sudoku.h"


int** Sudoku::inicializar(int tamanio) {
    matriz = (int**)malloc(sizeof(int*) * tamanio);
    for (int i = 0; i < tamanio; i++) {
        *(matriz + i) = (int*)malloc(sizeof(int*) * tamanio);
    }
    return matriz;
}


void Sudoku::tablero(int** matriz) {
    cout << "-------------SUDOKU---------------\n";
    for (int i = 0; i < 9; i++) {
        printf("\n");
        if (i == 3 || i == 6) {
            cout << "----------------------------------\n";
        }
        for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6) {
                printf("   |");
            }
            cout << " " << *(*(matriz + i) + j) << " ";
        }
    }
}


int** Sudoku::hacerSolucion(int** matriz) {
    srand(time(NULL));
    do {
        contador2 = 0;
        matriz = inicializar(10);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                *(*(matriz + i) + j) = 0;
                contador1 = 0;
                do {

                    aleatorio = rand() % 9 + 1;

                    detente = controlar(aleatorio, 9, i, j, matriz);
                    contador1++;

                    if (contador1 > 15) {
                        i = 9;
                        j = 9;
                    }
                } while (detente == 1);
                *(*(matriz + i) + j) = aleatorio;

                contador2++;
            }
        }
    } while (contador2 != 81);
    return matriz;
}

int Sudoku::controlar(int numero, int tamanio, int contador1, int contador2, int** matriz) {
    detente = 0;
    for (int i = 0; (i < tamanio && detente == 0); i++) {

        if (*(*(matriz + contador1) + i) == numero || *(*(matriz + i) + contador2) == numero) {
            detente = 1;
        }
    }
    return detente;
}