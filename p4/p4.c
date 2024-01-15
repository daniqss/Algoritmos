/*
ASIGNATURA: ALGORITMOS
PRACTICA: Dijkstra
FECHA DE ENTREGA: 25/11/23
INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
		     MIGUEL CANO MENENDEZ (miguel.cano@udc.es)
*/

#include "leerTiempo.h"


void test();


int main() {
    //Descomentar en caso de querer obtener mas de una tabla
    //int i = 0; 
    inicializar_semilla();
    test();  
    //for(i = 0; i < 4; i++)
    leerTiempo();

    return 0;
}

void dijkstra( matriz M, matriz D, int size){
    int m = 0, i = 0, j = 0, v = 0, w = 0, min = 0;
    int* noVisitados = malloc(size*sizeof(int));
    
    for (m = 0; m < size; m++) {
        for(i = 0; i < size; i++){ 
            noVisitados[i] = 1;
            D[m][i] = M [m][i];
        }
        noVisitados[m] = 0;
        i = size - 2;
        while( i > 0){
            min = -1;
            v = m;
            for(j = 0; j < size; j++){
                if(noVisitados[j] && (D[m][j] < min || min == -1)){
                    min = D[m][j];
                    v = j;
                }
            }

            noVisitados[v] = 0;

            for (w = 0; w < size; w++) {
                if(noVisitados[w]){
                    if (D[m][w] > (D[m][v] + M[v][w])) {
                        D[m][w] = (D[m][v] + M[v][w]);    
                    }
                }
            }
            i--;
        }
    }
    free(noVisitados);
}

matriz crearMatriz(int n) {
    int i;
    matriz aux;
    if ((aux = malloc(n*sizeof(int *))) == NULL)
        return NULL;
    for (i=0; i<n; i++)
        if ((aux[i] = malloc(n*sizeof(int))) == NULL)
            return NULL;
    return aux;
}

void iniMatriz(matriz m, int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            m[i][j] = rand() % TAM_MAX + 1;
    for(i = 0; i < n; i++)
        for(j = 0; j <= i; j++)
        if(i == j)
            m[i][j] = 0;
        else
            m[i][j] = m[j][i];
}

void liberarMatriz(matriz m, int n) {
    int i;
    for (i = 0; i < n; i++)
        free(m[i]);
    free(m);
}

void imprimirMatriz(matriz mat, int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        printf("[");
        for(j = 0; j < n; j++){
            printf(" %2i ", mat[i][j]);
        }
        printf("]\n");
    }
    puts("");
}

void printTest(int n){
    if(!n)
        puts("\033[1;35m""Test Matriz Grafo 5 x 5\n""\033[0m");
    else 
        puts("\033[1;35m""TestMatriz Grafo 4 x 4\n""\033[0m");   
}

void test() {
    int size = 5, i = 0, j = 0, k = 0;    
    matriz M , D;
    int matrizOriginal[5][5] = {
        {0, 1, 8, 4, 7}, 
        {1, 0, 2, 6, 5}, 
        {8, 2, 0, 9, 5}, 
        {4, 6, 9, 0, 3},
        {7, 5, 5, 3, 0}
    };

    int matrizOriginal2[4][4] = {
        {0, 1, 4, 7},
        {1, 0, 2, 8},
        {4, 2, 0, 3},
        {7, 8, 3, 0}
    };

    for(i = 0; i < 2; i++) {
        printTest(i);
        if(i == 1) 
            size = 4;

        M = crearMatriz(size);
        D = crearMatriz(size);
        for(j = 0; j < size; j++){
            for(k = 0; k < size; k++){
                if(i == 0)
                    M[j][k] = matrizOriginal[j][k];
                else 
                    M[j][k] = matrizOriginal2[j][k];
            }
        }
        printf("\033[1;31m");
        imprimirMatriz(M, size);
        dijkstra(M, D, size);
        printf("\033[1;32m");
        imprimirMatriz(D, size);
        printf("\033[0m");

        liberarMatriz(M, size);
        liberarMatriz(D, size);
    }
}

