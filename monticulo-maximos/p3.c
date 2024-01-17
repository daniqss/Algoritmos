/*
ASIGNATURA: ALGORITMOS
PRACTICA: Monticulos
FECHA DE ENTREGA: 11/11/23
INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
		     MIGUEL CANO MENENDEZ (miguel.cano@udc.es)
*/
#include "leerTiempo.h"

void test();


int main() {
    int i = 0, j = 0;
    
    inicializar_semilla();
    test();
    for(j = 3; j <= 5; j++){
        do{
            selectorCombinacionesLeerTiempo(j);
            i++;
        } while(i != 3);
        i = 0;
    }

    return 0;
}

void copiarVector(const int v1[], int v2[], int size) {
    int i;
    
    for(i = 0; i < size; i++){
        v2[i] = v1[i];
    }
}

void intercambiar(int* i, int* j) {
    int aux = *i;
    *i = *j;
    *j = aux;
}

void crearMonticulo(int v[], int size, pmonticulo* m) {
    int i = 0;
    copiarVector(v, (*m)->vector, size);
    (*m)->ultimo = size - 1;
    for(i = (*m)->ultimo / 2; i >= 0; i--){
        hundir(m, i);
    }
}

void hundir(pmonticulo* m, int i) {
    int hijoIzquierdo = 0;
    int hijoDerecho = 0;
    int j = 0;

    do{
        j = i;
        hijoIzquierdo = 2*i + 1;
        hijoDerecho = 2*i + 2;

        if (hijoDerecho <= (*m)->ultimo && (*m)->vector[hijoDerecho] > (*m)->vector[i]) {
            i = hijoDerecho;
        }
        if (hijoIzquierdo <= (*m)->ultimo && (*m)->vector[hijoIzquierdo] > (*m)->vector[i]) {
            i = hijoIzquierdo;
        }

        intercambiar(&(*m)->vector[i], &(*m)->vector[j]);
    } while (j != i);
}

bool vacioMonticulo(pmonticulo m) {
    return (*m).ultimo + 1 == 0;
}

void OrdenarPorMonticulos(int v[], int size, pmonticulo* m) {
    int i = 0;

    crearMonticulo(v, size, m);
    for (i = (*m)->ultimo; i >= 0; i--) {
        v[i] = quitarMayor(m);
    }
}

int quitarMayor(pmonticulo* m) {
    int x = 0;

    if (vacioMonticulo(*m)){
        fprintf(stderr,"Error");
    } else {
        x = (*m)->vector[0]; 
        (*m)->vector[0] = (*m)->vector[(*m)->ultimo];
        (*m)->ultimo = (*m)->ultimo - 1;
        if((*m)->ultimo > 0) {
            hundir(m, 0);
        }
    }
    return x;
}

void inicializarMonticulo(pmonticulo* m) {
   (*m)->ultimo = 0;
}


void test() {
    int size = 21, i = 0, j = 0;
    int v[size];
    pmonticulo m = (pmonticulo)malloc(sizeof(struct monticulo));
    inicializarMonticulo(&m);

    for(j = 0; j <= 1; j++) {
        if(j == 0) {
            puts("\033[1;35m""\t\t\t\tCrearMonticulo""\033[0m");
        } else {
            puts("\033[1;35m""\n\t\t\t\tOrdenacionPorMonticulo""\033[0m");   
        }
        for (i = 0;i <= 2; i++) {
            prepararVector(v, size, i);
            printf("\033[1;31m");
            printVector(v, size);
            printf("\033[0m"); 
            if(j == 0) {
                crearMonticulo(v, size, &m);  
            } else {
                OrdenarPorMonticulos(v, size, &m);
            }
            printf("\033[1;32m"); 
            j == 0 ? printVector(m->vector, size) : printVector(v, size); 
            printf("\033[1;0m");
        } 
        i = 0;
    }
    free(m);    
}

