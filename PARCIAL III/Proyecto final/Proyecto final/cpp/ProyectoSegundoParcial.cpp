#define _HAS_STD_BYTE 0
#include <iostream>
#include "HilosPrincipales.h"
#include <Engine.h>
#pragma comment (lib,"libmat.lib")
#pragma comment (lib,"libmx.lib")
#pragma comment (lib, "libmex.lib ")
#pragma comment(lib,"libeng.lib")
#define BUFSIZE 256
#pragma warning(disable : 4996)
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

int main(int argc, char** argv){
	
    mainMenu();
   

    int tiempo = 1.25;
    Engine* ep;
    mxArray* T = NULL, * result = NULL, * R = NULL;
    char buffer[BUFSIZE + 1];
    double time[10] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };

   
    if (!(ep = engOpen(""))) {
        fprintf(stderr, "\nCan't start MATLAB engine\n");
        return EXIT_FAILURE;
    }

  
    T = mxCreateDoubleMatrix(1, 10, mxREAL);
    memcpy((void*)mxGetPr(T), (void*)time, sizeof(time));
    R = mxCreateDoubleMatrix(1, tiempo, mxREAL);
    memcpy((void*)mxGetPr(R), (void*)time, sizeof(1));
    /*
     * Place the variable T into the MATLAB workspace
     */
    engPutVariable(ep, "T", T);
    engPutVariable(ep, "R", R);
    /*
     * Evaluate a function of time, distance = (1/2)g.*t.^2
     * (g is the acceleration due to gravity)
     */
    engEvalString(ep, "D = T.^2;");
    engEvalString(ep, "P = R;");
    engEvalString(ep, "F = P.^(0.5);");

    /*
     * Plot the result
     */
    engEvalString(ep, "plot(T,D,F,P,'or');");
    engEvalString(ep, "title('EL TIEMPO  vs  NUMERO DE ELEMENTOS');");
    engEvalString(ep, "xlabel('Porción (unid)');");
    engEvalString(ep, "ylabel('Tiempo (seg)');");


    system("pause");
    printf("Grafica hecha!\n");
    mxDestroyArray(result);
    engClose(ep);
    
    return EXIT_SUCCESS;

   
    
	return 0;
    
}

