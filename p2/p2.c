/*
ASIGNATURA: ALGORITMOS
PRÁCTICA: Ordenacion por insercion y ordenacion shell
FECHA DE ENTREGA: 30/09/23
INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
		     MIGUEL CANO MENÉNDEZ (miguel.cano@udc.es)
*/

#include "leerTiempo.h"

void test();


int main(){
    int i = 0, j = 0;

    inicializar_semilla();
    test();
    for(; j <= 5; j++){
        do{
            selectorCombinacionesLeerTiempo(j);
            i++;
        }while(i != 3);
        i = 0;;
    }

    return 0;
}

void ordInsercion (int v[], int n) {
    int i = 1, j, x;
    
    for (; i < n; i++){
        x = v[i];
        j = i - 1;

        while(j >= 0 && v[j] > x){
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = x;
    }
}

void ordShell(int v[], int n) {
    int incremento = n;
    int tmp, i, j;
    bool seguir;
    
    do {
        incremento = incremento / 2;
        
        for (i = incremento; i < n; i++) {
            tmp = v[i];
            j = i;
            seguir = true;
            
            while (j - incremento >= 0 && seguir) {
                if (tmp < v[j - incremento]) {
                    v[j] = v[j - incremento];
                    j = j - incremento;
                } else {
                    seguir = false;
                }
            }  
            v[j] = tmp;
        }
    } while (incremento > 1);
}

void test(){
    int size = 21, i = 0, j = 0;
    int v[size];
 
    for(; j <= 1; j++){
        if(j == 0){
            puts("\033[1;35m""\t\t\t\tOrdenacionInsercion""\033[0m");
        } else {
            puts("\033[1;35m""\t\t\t\tOrdenacionShell""\033[0m");   
        }
        for (;i <= 2; i++){
            prepararVector(v, size, i);
            printf("\033[1;31m");
            printVector(v, size);
            printf("\033[0m");  
            if(j == 0){
                ordInsercion(v, size);  
            } else {
                ordShell(v, size);
            }
            printf("\033[1;32m"); 
            printVector(v, size); 
            printf("\033[1;0m");
        } 
        i = 0;
    }              
}









