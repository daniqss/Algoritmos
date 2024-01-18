/*
ASIGNATURA: ALGORITMOS
PRÁCTICA: Ordenacion por insercion y ordenacion shell
FECHA DE ENTREGA: 30/09/23
INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
		     MIGUEL CANO MENÉNDEZ (miguel.cano@udc.es)
*/

#include "prepararVector.h"
# include "leerTiempo.h"

void test();


int main() {
    int i = 0;

    inicializar_semilla();
    test();

    for(i = 0; i <= 2; i++){
        do{
            selectorCombinacionesLeerTiempo(i);
            i++;
        }while(i != 3);
        i = 0;;
    }

    return 0;
}

void test(){
    int n = 8, i;
    int v[n];
        
    puts("\033[1;35m""ordenar Test""\033[0m");

    for (i = 0; i <= 2; i++){
        printf("Vector original\n");
        prepararVector(v, n, i);
        printVector(v, n);

        printf("Vector ordenado\n");
        ordenar(v, n);
        printVector(v, n); 
        puts("");
    }            
}






