/*
ASIGNATURA: ALGORITMOS
PRÁCTICA: Suma de Subsecuencia Máxima
FECHA DE ENTREGA: 30/09/23
INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
		     MIGUEL CANO MENÉNDEZ (miguel.cano@udc.es)
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdbool.h>


int sumaSubMax1 (int v[], int n);
int sumaSubMax2 (int v[], int n);
void test();
void testRandom();
void printVector(int v[], int n, int x, int y);
void inicializar_semilla();
void aleatorio(int v[], int n);
double microsegundos();
void cabeceraTablas(bool seletor);
double tiempoPrepararVector(int size, int repeticiones);
void leerTiempoSumSubMax (bool selector);
void guardarTiempos(int size, double t, double x, double y, double z);
void cabecera(bool selector);
double selecionarSubMax(bool selector, int v[], int size);
void selecionarCotas(bool selector, double t, int size);
double selecionarSubMaxRep(bool selector, int v[], int size, int rep);

int main(){
    int i = 0;

    inicializar_semilla();
    test();
    testRandom();
    do{
        leerTiempoSumSubMax (true);
        i++;
    }while(i != 3);
    i = 0;
    do{
        leerTiempoSumSubMax (false);
        i++;
    }while(i != 3);
    
    return 0;
}

int sumaSubMax1 (int v[], int n){
    int sumaMax = 0, i = 0, estaSuma = 0, j;
    for(; i < n; i++){
        estaSuma = 0;
        for(j = i; j < n; j++){
            estaSuma = estaSuma + v[j];
            if(estaSuma > sumaMax){
                sumaMax = estaSuma;
            }
        }
    }
    return sumaMax;
}

int sumaSubMax2 (int v[], int n){
    int estaSuma = 0, sumaMax = 0, j = 0;
    for(; j < n; j++){
        estaSuma = estaSuma + v[j];
        if(estaSuma > sumaMax){
            sumaMax = estaSuma;
        } else if (estaSuma < 0){
            estaSuma = 0;
        }
    }
    return sumaMax;
}

void test(){
    int a[] = {-9,2,-5,-4,6};    
    int b[] = {4,0,9,2,5};       
    int c[] = {-2,-1,-9,-7,-1};
    int d[] = {9,-2,1,-7,-8};
    int e[] = {15,-2,-5,-4,16};
    int f[] = {7,-5,6,7,-7};
    int size = 5;

    puts("\033[1;35m""\nsecuencia\t\tsumSubMax1\tresultado""\033[0m");
    printVector(a, size, sumaSubMax1(a,size), -1024);
    printVector(b, size, sumaSubMax1(b,size), -1024); 
    printVector(c, size, sumaSubMax1(c,size), -1024); 
    printVector(d, size, sumaSubMax1(d,size), -1024); 
    printVector(e, size, sumaSubMax1(e,size), -1024); 
    printVector(f, size, sumaSubMax1(f,size), -1024);                     

    puts("\033[1;35m""\nsecuencia\t\tsumSubMax2\tresultado""\033[0m");
    printVector(a, size, sumaSubMax2(a,size), -1024);
    printVector(b, size, sumaSubMax2(b,size), -1024); 
    printVector(c, size, sumaSubMax2(c,size), -1024); 
    printVector(d, size, sumaSubMax2(d,size), -1024); 
    printVector(e, size, sumaSubMax2(e,size), -1024); 
    printVector(f, size, sumaSubMax2(f,size), -1024);   
}

void testRandom(){
    int size = 7;
    int a[size];  
    int b[size];       
    int c[size];
    int d[size];
    int e[size]; 
    int f[size]; 

    aleatorio(a, size);
    aleatorio(b, size);
    aleatorio(c, size);
    aleatorio(d, size);
    aleatorio(e, size);
    aleatorio(f, size);

    printf("\033[1;35m""\nsecuencia\t\t\t\tsumSubMax1  sumSubMax2\n""\033[0m");
    printVector(a, size, sumaSubMax1(a,size), sumaSubMax2(a,size));
    printVector(b, size, sumaSubMax1(b,size), sumaSubMax2(b,size)); 
    printVector(c, size, sumaSubMax1(c,size), sumaSubMax2(c,size)); 
    printVector(d, size, sumaSubMax1(d,size), sumaSubMax2(d,size)); 
    printVector(e, size, sumaSubMax1(e,size), sumaSubMax2(e,size)); 
    printVector(f, size, sumaSubMax1(f,size), sumaSubMax2(f,size));                       
}

void printVector(int v[], int n, int x, int y){
    int i = 0;
    for(; i < n; i++){
        printf("\033[1;36m");
        if(i == (n - 1)){
            printf("%3d", v[i]);
        } else {
            printf("%3d,", v[i]);
        }
        printf("\033[0m");
    }
    printf("\t\t\t%d", x);
    if(y != -1024){
        printf("\t%2d", y);
    }
    printf("\n");
    
}

void inicializar_semilla(){
    srand(time(NULL));
}

void aleatorio(int v[], int n){
    int i, m = 2 * n + 1;
    for(i=0; i < n; i++){
        v[i] = (rand() % m) - n;
    }
}

double microsegundos(){
    struct timeval t;
    if(gettimeofday(&t, NULL) < 0) 
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0); 
}

void cabeceraTablas(bool selector){   
    printf("\033[1;32m");  
    if(selector == true){
        printf("%11sn%11st(n)%7st(n)/n^1.8%6st(n)/n^2%6st(n)/n^2.2\n"
        ,"","","","","");
    } else{
        
        printf("%11sn%11st(n)%7st(n)/n^0.9%5st(n)/n^0.95%5st(n)/n^1.0\n"
        ,"","","","","");
    }
    
    printf("\033[0m"); 
}

void leerTiempoSumSubMax (bool selector) {
    double t;
    int n[] = {500, 1000, 2000, 4000, 8000, 16000, 32000,64000,128000, 256000};
    int v[256000];
    int l = 0, rep = 10000;
    cabecera(selector);
    cabeceraTablas(selector); 
    for(; l < (selector ? 7 : 10); l ++){
        printf("\033[0m");
        aleatorio(v, l[n]);

        t = selecionarSubMax(selector, v, n[l]);
        if (t < 500.0) {
            printf("\033[1;31m");
            t = selecionarSubMaxRep(selector, v, n[l], rep);
        }
        selecionarCotas(selector, t, l[n]);
    }
    printf("\033[4;1;31m""\n¡AVISO!:""\033[0m"" Las filas en rojo indican"
        " que se han realizado %d repeticiones\n""\033[0m", rep);
}


double tiempoPrepararVector(int size, int repeticiones){
    double ti, tf;
    int v[size], k;

    ti = microsegundos();
            for (k = 0; k < repeticiones; k++) {
                aleatorio(v, size);
            }
    tf = microsegundos();

    return tf - ti;
}

void cabecera(bool selector){
    if(selector == true){
        printf ("\033[4;1;35m""\nTabla tiempos SumaSubMax\n\n""\033[0m");
    } else {
        printf ("\033[4;1;35m""\nTabla tiempos SumaSubMax2\n\n""\033[0m");
    }
}

double selecionarSubMax(bool selector, int v[], int size){
   double ti, tf;
   if(selector == true){
        ti = microsegundos();
        sumaSubMax1(v, size);
        tf = microsegundos();
    }else{
        ti = microsegundos(); 
        sumaSubMax2(v, size);
        tf = microsegundos();
    } 
    return  tf - ti;
}

double selecionarSubMaxRep(bool selector, int v[], int size, int rep){
   double ti, tf;
   int k;
   if(selector == true){
        ti = microsegundos();
        for (k = 0; k < rep; k++) {
            aleatorio(v,size);
            sumaSubMax1(v, size);
        }
        tf = microsegundos();
    }else{
        ti = microsegundos();
        for (k = 0; k < rep; k++) {
            aleatorio(v, size);  
            sumaSubMax2(v, size);
        }
        tf = microsegundos();
    }    
    return (((tf - ti) - tiempoPrepararVector(size, rep))/ rep);
}

void selecionarCotas(bool selector, double t, int size){
    double x, y, z;
    
    if(selector == true){
        x = t / pow(size,1.8);
        y = t / pow(size,2.0);
        z = t / pow(size,2.2);
    } else{
        x = t / pow(size,0.9);
        y = t / pow(size,0.95);
        z = t / pow(size,1.0);
    }
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", size, t, x, y, z);
}
