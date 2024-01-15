#include "leerTiempo.h"

void leerTiempo () {
    double t = 0;
    int n[] = {8, 16, 32, 64, 128, 256, 512};
    int l = 0, rep = 10000;
    matriz M, D;

    printf ("\033[4;1;35m""\nTabla tiempos Dijkstra"
        "\n\n""\033[0m");
    printf("\033[1;32m""%11sn%11st(n)%7st(n)/n^2.7%5st(n)/n^2.8%5s"
        "t(n)/n^2.9%5st(n)/n^2.0\n""\033[0m","","","","","",""); 
    for(l = 0; l < 7; l ++){
        printf("\033[0m");
        
        M = crearMatriz (n[l]);
        D = crearMatriz (n[l]);
        iniMatriz( M, n[l]);

        t = algoritmo(n[l], M, D);
        if (t < 500.0) {
            printf("\033[1;31m");
            t = algoritmoRep(n[l], rep, M, D);
        }
        seleccionarCotas(t, l[n]);
        liberarMatriz(M, n[l]);
        liberarMatriz(D, n[l]);
    }
    printf("\033[4;1;31m""\n¡AVISO!:""\033[0m"" Las filas en rojo indican"
    " que se han realizado %d repeticiones\n""\033[0m", rep);
}

void seleccionarCotas(double t, int size){
    double x = 0, y = 0, z = 0, w = 0;

    x = t / pow(size, 2.7);
    y = t / pow(size, 2.8);
    z = t / pow(size, 2.9);
    w = t / pow(size, 2.0);

    printf("%12d%15.4f%15.6f%15.6f%15.6f%15.6f\n", size, t, x, y, z, w);
}

double tiempoPrepararVector(int size, int repeticiones, matriz M){
    double ti = 0, tf = 0;
    int k = 0;

    ti = microsegundos();
        for (k = 0; k < repeticiones; k++) {
            iniMatriz( M, size);
        }
    tf = microsegundos();

    return tf - ti;
}

double algoritmo(int size, matriz M, matriz D){
    double ti = 0, tf = 0;
    ti = microsegundos();
        dijkstra(M, D, size);
    tf = microsegundos();
    return  tf - ti;
}

double algoritmoRep(int size, int rep, matriz M, matriz D) {
   double ti = 0, tf = 0;
   int k = 0;
    ti = microsegundos();
    for (k = 0; k < rep; k++) {
        iniMatriz(M , size);
        dijkstra(M, D, size);
    }
    tf = microsegundos(); 
    return (((tf - ti) - tiempoPrepararVector(size, rep, M))/ rep);
}

double microsegundos(){
    struct timeval t;
    if(gettimeofday(&t, NULL) < 0) 
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0); 
}

void inicializar_semilla(){
    srand(time(NULL));
}