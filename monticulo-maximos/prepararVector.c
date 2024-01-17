#include "prepararVector.h"

void ascendente(int v[], int size){
    int i = 0;
    int j = -(size - 1)/2;

    for (i = 0; i < size; i++) {
        v[i] = j + i;
    }
}

void descendente(int v[], int size){
    int i = 0;
    int j = (size - 1)/2;

    for (i = 0; i < size; i++) {
        v[i] = j - i;
    }
}

void aleatorio(int v[], int n){
    int i, m = 2 * n + 1;
    for(i = 0; i < n; i++){
        v[i] = (rand() % m) - n;
    }
}

void prepararVector(int v[], int size, int sV){
    if( sV == 0){
        aleatorio(v, size);
    } else if (sV == 1){
        descendente(v, size);
    } else {
        ascendente(v, size);
    }
}

void printVector(int v[], int n){
    int i = 0;
    for(i = 0; i < n; i++){
        if(i == (n - 1)){
            printf("%3d\n", v[i]);
        } else {
            printf("%3d,", v[i]);
        }
    }  
}

