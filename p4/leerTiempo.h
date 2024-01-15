#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>

#define TAM_MAX 1000

typedef int** matriz;

void seleccionarCotas(double t, int size);

double tiempoPrepararVector(int size, int repeticiones, matriz M);

void leerTiempo ();

double microsegundos();

void inicializar_semilla();

double algoritmoRep(int size, int rep, matriz M, matriz D);

double algoritmo(int size, matriz M, matriz D);

void iniNoVisitados (int noVisitados[], int n, int m);

void dijkstra( matriz M, matriz D, int size);

matriz crearMatriz(int n);

void iniMatriz(matriz m, int n);

void liberarMatriz(matriz m, int n);

void imprimirMatriz(matriz mat, int n);;

