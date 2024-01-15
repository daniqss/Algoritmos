/*
ASIGNATURA: ALGORITMOS
PRÁCTICA: Ordenacion por insercion y ordenacion shell
FECHA DE ENTREGA: 21/09/23
INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
		     MIGUEL CANO MENÉNDEZ (miguel.cano@udc.es)
*/

#include "leerTiempo.h"

void leerTiempo (int s, int sV, int sC) {
    double t;
    int n[] = {500, 1000, 2000, 4000, 8000, 16000, 32000, 64000,128000, 256000};
    int v[256000];
    int l = 0, rep = 10000;
    
    
    cabeceraTablas(sC); 
    for(; l < (sV != 2 ? 7 : 10); l ++){
        printf("\033[0m");
        prepararVector(v, n[l], sV);

        t = seleccionarOrdenacion(s, v, n[l]);
        if (t < 500.0) {
            printf("\033[1;31m");
            t = seleccionarOrdenacionRep(s, sV, v, n[l], rep);
        }
        seleccionarCotas(sC, t, l[n]);
    }
    printf("\033[4;1;31m""\n¡AVISO!:""\033[0m"" Las filas en rojo indican"
        " que se han realizado %d repeticiones\n""\033[0m", rep);
}

void selectorCombinacionesLeerTiempo(int n){
    cabecera(n); 
    if(n == 0){
        leerTiempo(0,0,1); 
    } else if (n == 1){
        leerTiempo(0,1,2);
    } else if (n == 2){
        leerTiempo(0,2,3);
    } else if (n == 3){
        leerTiempo(1,0,4);
    } else if (n == 4){
        leerTiempo(1,1,5);
    } else {
        leerTiempo(1,2,6);
    }
}

void seleccionarCotas(int sC, double t, int size) {
    double x, y, z;
    
    if(sC == 1) {
        x = t / pow(size,1.8);
        y = t / pow(size,2.0);
        z = t / pow(size,2.1);
    } else if (sC == 2) {
        x = t / pow(size, 1.9);
        y = t / pow(size, 2.0);
        z = t / pow(size, 2.1);
    } else if (sC == 3) {
        x = t / pow(size,0.9);
        y = t / pow(size,1.0);
        z = t / pow(size,1.1);
    } else if (sC == 4) {
        x = t / pow(size,1.1);
        y = t / pow(size,1.17);
        z = t / pow(size,1.3);
    } else if (sC == 5) {
        x = t / pow(size,1.0);
        y = t / pow(size,1.15);
        z = t / pow(size,1.3);
    } else if (sC == 6) {
        x = t / pow(size,1.0);
        y = t / pow(size,1.125);
        z = t / pow(size,1.3);
    } else {
        puts("Error");
    }
    printf("%12d%15.4f%15.6f%15.6f%15.6f\n", size, t, x, y, z);
}

void cabecera(int sC){
    if(sC == 0){
        printf ("\033[4;1;35m""\nTabla tiempos OrdInsercion Aleatorio"
        "\n\n""\033[0m");
    } else if (sC == 1){
        printf ("\033[4;1;35m""\nTabla tiempos OrdInsercion Descendente"
        "\n\n""\033[0m");
    } else if (sC == 2){
        printf ("\033[4;1;35m""\nTabla tiempos OrdInsercion Ascendente"
        "\n\n""\033[0m");
    } else if (sC == 3){
        printf ("\033[4;1;35m""\nTabla tiempos OrdShell Aleatorio"
        "\n\n""\033[0m");
    } else if (sC == 4){
        printf ("\033[4;1;35m""\nTabla tiempos OrdShell Descendente"
        "\n\n""\033[0m");
    } else {
        printf ("\033[4;1;35m""\nTabla tiempos OrdShell Ascendente"
        "\n\n""\033[0m");
    }
}

void cabeceraTablas(int s) {   
    printf("\033[1;32m");  
    if(s == 1) {
        printf("%11sn%11st(n)%7st(n)/n^1.8%6st(n)/n^2.0%6st(n)/n^2.1\n"
        ,"","","","","");
    } else if (s == 2) {
        printf("%11sn%11st(n)%7st(n)/n^1.9%5st(n)/n^2.0%5st(n)/n^2.1\n"
        ,"","","","","");
    } else if (s == 3) {
        printf("%11sn%11st(n)%7st(n)/n^0.9%6st(n)/n^1.0%6st(n)/n^1.1\n"
        ,"","","","","");
    } else if (s == 4) {
        printf("%11sn%11st(n)%7st(n)/n^1.1%6st(n)/n^1.17%6st(n)/n^1.3\n"
        ,"","","","","");
    } else if (s == 5) {
        printf("%11sn%11st(n)%7st(n)/n^1.0%6st(n)/n^1.15%6st(n)/n^1.3\n"
        ,"","","","","");
    } else {
        printf("%11sn%11st(n)%7st(n)/n^1.0%6st(n)/n^1.125%6st(n)/n^1.3\n"
        ,"","","","","");
    }
    printf("\033[0m"); 
}

double tiempoPrepararVector(int size, int repeticiones, int sV){
    double ti, tf;
    int v[size], k;

    ti = microsegundos();
        for (k = 0; k < repeticiones; k++) {
            prepararVector(v, size, sV);
        }
    tf = microsegundos();

    return tf - ti;
}

double seleccionarOrdenacion(int s, int v[], int size) {
    double ti, tf;
    if(s == 0){
        ti = microsegundos();
        ordInsercion(v,size);
        tf = microsegundos();
    } else {
        ti = microsegundos(); 
        ordShell(v,size);
        tf = microsegundos();
    } 
    return  tf - ti;
}

double seleccionarOrdenacionRep(int s, int sV, int v[], int size, int rep) {
   double ti, tf;
   int k;
   if(s == 0){
        ti = microsegundos();
        for (k = 0; k < rep; k++) {
            prepararVector(v, size, sV);
            ordInsercion(v, size);
        }
        tf = microsegundos();
    }else{
        ti = microsegundos();
        for (k = 0; k < rep; k++) {
            prepararVector(v, size, sV);  
            ordShell(v, size);
        }
        tf = microsegundos();
    }    
    return (((tf - ti) - tiempoPrepararVector(size, rep, 1))/ rep);
}

double microsegundos() {
    struct timeval t;
    if(gettimeofday(&t, NULL) < 0) 
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0); 
}

void inicializar_semilla() {
    srand(time(NULL));
}