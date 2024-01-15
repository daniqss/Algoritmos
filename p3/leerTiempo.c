#include "leerTiempo.h"

void leerTiempo (int s, int sV, int sC) {
    double t = 0;
    int n[] = {500, 1000, 2000, 4000, 8000, 16000, 32000, 64000,128000, 256000};
    int v[256000];
    int l = 0, rep = 10000;
    pmonticulo m = (pmonticulo)malloc(sizeof(struct monticulo));
    inicializarMonticulo(&m);
    
    cabeceraTablas(sC); 
    for(l = 0; l < 10; l ++){
        printf("\033[0m");
        prepararVector(v, n[l], sV);

        t = seleccionarOrdenacion(s, v, n[l], &m);
        if (t < 500.0) {
            printf("\033[1;31m");
            t = seleccionarOrdenacionRep(s, sV, v, n[l], rep, &m);
        }
        seleccionarCotas(sC, t, l[n]);
    }
    printf("\033[4;1;31m""\n¡AVISO!:""\033[0m"" Las filas en rojo indican"
        " que se han realizado %d repeticiones\n""\033[0m", rep);
    free(m);
}

void selectorCombinacionesLeerTiempo(int n){
    cabecera(n); 
    if(n == 0){
        leerTiempo(0,0,1); 
    } else if (n == 1) {
        leerTiempo(0,1,2);
    } else if (n == 2) {
        leerTiempo(0,2,3);
    } else if (n == 3) {
        leerTiempo(1,0,4);
    } else if (n == 4) {
        leerTiempo(1,1,5);
    } else {
        leerTiempo(1,2,6);
    }
}

void seleccionarCotas(int sC, double t, int size){
    double x = 0, y = 0, z = 0;
    
    if(sC == 1){
        x = t / pow(size,0.9);
        y = t / pow(size,1.0);
        z = t / pow(size,1.1);
    } else if (sC == 2){
        x = t / pow(size, 0.9);
        y = t / pow(size, 1.0);
        z = t / pow(size, 1.1);
    } else if (sC == 3) {
        x = t / pow(size,0.9);
        y = t / pow(size,1.0);
        z = t / pow(size,1.1);
    } else if (sC == 4) {
        x = t / pow(size,1.0);
        y = t / pow(size, 1.228) * log(pow(size,1.228));//pow(size,1.128);    // 1.105
        z = t / pow(size,1.2);

    } else if (sC == 5) {
        x = t / pow(size,1.0);
        y = t / pow(size, 1.22) * log(pow(size,1.22)); // 1.08
        z = t / pow(size,1.2);
    } else if (sC == 6) {
        x = t / pow(size,1.0);
        y = t / pow(size, 1.22) * log(pow(size,1.22)); // 1.07
        z = t / pow(size,1.2);
    } else {
        puts("Error");
    }
    printf("%12d%15.4f%15.6f%15.6f%15.6f\n", size, t, x, y, z);
}

void cabecera(int sC){
    if(sC == 0){
        printf ("\033[4;1;35m""\nTabla tiempos CrearMonticulo Aleatorio"
        "\n\n""\033[0m");
    } else if (sC == 1){
        printf ("\033[4;1;35m""\nTabla tiempos CrearMonticulo Descendente"
        "\n\n""\033[0m");
    } else if (sC == 2){
        printf ("\033[4;1;35m""\nTabla tiempos CrearMonticulo Ascendente"
        "\n\n""\033[0m");
    } else if (sC == 3){
        printf ("\033[4;1;35m""\nTabla tiempos OrdenacionPorMonticulo Aleatorio"
        "\n\n""\033[0m");
    } else if (sC == 4){
        printf ("\033[4;1;35m""\nTabla tiempos OrdenacionPorMonticulo"
        " Descendente\n\n""\033[0m");
    } else {
        printf ("\033[4;1;35m""\nTabla tiempos OrdenacionPorMonticulo "
        "Ascendente\n\n""\033[0m");
    }
}

void cabeceraTablas(int s) {   
    printf("\033[1;32m");  
    if(s == 1){
        printf("%11sn%11st(n)%7st(n)/n^0.9%6st(n)/n^1.0%6st(n)/n^1.1\n"
        ,"","","","","");
    } else if (s == 2){
        printf("%11sn%11st(n)%7st(n)/n^0.9%5st(n)/n^1.0%5st(n)/n^1.1\n"
        ,"","","","","");
    } else if (s == 3){
        printf("%11sn%11st(n)%7st(n)/n^0.9%6st(n)/n^1.0%6st(n)/n^1.1\n"
        ,"","","","","");
    } else if (s == 4){
        printf("%11sn%11st(n)%7st(n)/n^1.0%6st(n)/n^1.105%6st(n)/n^1.2\n"
        ,"","","","","");
    } else if (s == 5){
        printf("%11sn%11st(n)%7st(n)/n^1.0%6st(n)/n^1.08%6st(n)/n^1.2\n"
        ,"","","","","");
    } else {
        printf("%11sn%11st(n)%7st(n)/n^1.0%6st(n)/n^1.07%6st(n)/n^1.2\n"
        ,"","","","","");
    }
    printf("\033[0m"); 
}

double tiempoPrepararVector(int size, int repeticiones, int sV){
    double ti = 0, tf = 0;
    int v[size], k = 0;

    ti = microsegundos();
        for (k = 0; k < repeticiones; k++) {
            prepararVector(v, size, sV);
        }
    tf = microsegundos();

    return tf - ti;
}

double seleccionarOrdenacion(int s, int v[], int size, pmonticulo* m){
    double ti = 0, tf = 0;
    if(s == 0){
        ti = microsegundos();
            crearMonticulo(v, size, m);
        tf = microsegundos();
    } else {
        ti = microsegundos(); 
            OrdenarPorMonticulos(v, size, m);
        tf = microsegundos();
    } 
    return  tf - ti;
}

double seleccionarOrdenacionRep(int s, int sV, int v[], int size, int rep, 
pmonticulo* m) {
   double ti = 0, tf = 0;
   int k = 0;
   if(s == 0){
        ti = microsegundos();
        for (k = 0; k < rep; k++) {
            prepararVector(v, size, sV);
            crearMonticulo(v, size, m);
        }
        tf = microsegundos();
    }else{
        ti = microsegundos();
        for (k = 0; k < rep; k++) {
            prepararVector(v, size, sV);  
            OrdenarPorMonticulos(v, size, m);
        }
        tf = microsegundos();
    }    
    return (((tf - ti) - tiempoPrepararVector(size, rep, sV))/ rep);
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