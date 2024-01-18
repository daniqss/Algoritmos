/*
ASIGNATURA: ALGORITMOS
PRÁCTICA: Ordenacion por insercion y ordenacion shell
FECHA DE ENTREGA: 21/09/23
INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
		     MIGUEL CANO MENÉNDEZ (miguel.cano@udc.es)
*/

#include "prepararVector.h"

void ascendente(int v[], int size) {
    int i = 0;
    int j = -(size - 1)/2;

    for (; i < size; i++) {
        v[i] = j + i;
    }
}

void descendente(int v[], int size) {
    int i = 0;
    int j = (size - 1)/2;

    for (; i < size; i++) {
        v[i] = j - i;
    }
}

void aleatorio(int v[], int n) {
    int i, m = 2 * n + 1;
    for(i=0; i < n; i++){
        v[i] = (rand() % m) - n;
    }
}

void prepararVector(int v[], int size, int sV) {
    if( sV == 0) {
        aleatorio(v, size);
    } else if (sV == 1){
        descendente(v, size);
    } else {
        ascendente(v, size);
    }
}

void printVector(int v[], int n) {
    int i = 0;
    for(; i < n; i++) {
        if(i == (n - 1)) {
            printf("%3d\n", v[i]);
        } else {
            printf("%3d,", v[i]);
        }
    }  
}

void printParte (int v[], int izq, int der) {
    int i;

    for(i = izq; i < der; i++) {
        printf("%3d,", v[i]);
    }  
}

