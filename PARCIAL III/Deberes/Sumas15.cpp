/* *******************************************************
                UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
    Pograma para
    Autores: MORALES B, SALAZAR D.
    Fecha de creación:
    Fecha de modificación:
    Versión: V1.0
                      Estructura de Datos 7166
************************************************************/
using namespace std;
#include <iostream>
int main()
{
    char opc=0;
    do {
        cout << "*******************************\t";
        cout << "SUMA DE 15 ";
        cout << "*******************************";

        const int constMagica = 15;
        int matriz[3][3];
        int num = 3;
        
        cout << "\nLLenar la matriz 3x3 del 1 al 9 para que su sumas solo den 15\n";
        cout << "*******************************\t";
        cout << "MATRIZ ";
        cout << "*******************************\n";
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num; j++) {
                cout << "[" << i << "][" << j << "]: ";
                cin >> matriz[i][j];
            }
        cout << "*******************************\t";
        cout << "CUADRADO RESULTANTE ";
        cout << "*******************************\n";
        for (int i = 0; i < num; i++) {
            cout << " | ";
            for (int j = 0; j < num; j++)
                cout << matriz[i][j] << " ";

            cout << "| " << endl;
        }
        bool cuadradoMagico = true;
        int i = 0;
        while (i < num && cuadradoMagico == true) {
            int suma = 0;
            for (int j = 0; j < num; j++) {
                suma += matriz[i][j];
            }
            if (suma != constMagica) cuadradoMagico = false;
            i++;
        }
        if (!cuadradoMagico) {
            cout << "\nNO ES UN CUDRADO MAGICO DE 15!" << endl;
            return 0;
        }
        int j = 0;
        while (j < num && cuadradoMagico == true) {
            int suma = 0;
            for (int i = 0; i < num; i++) {
                suma += matriz[i][j];
            }
            if (suma != constMagica) cuadradoMagico = false;
            j++;
        }
        if (!cuadradoMagico) {
            cout << "\nNO ES UN CUDRADO MAGICO DE 15!" << endl;
        }
        else {
            cout << "\nLOS VALORES SI SUMAN 15 POR LO TANTO ES UN CUDRADO MAGICO" << endl;
        }
        
        

        cout << "\n\n\nDesea ingresar nuevos valores en el cuadrado magico" << endl;
        cin >> opc;
    } while (opc == 's' || opc == 'S');
    return 0;
}