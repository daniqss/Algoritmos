/*
ASIGNATURA: ALGORITMOS
PRÁCTICA: Ordenacion por insercion y ordenacion shell
FECHA DE ENTREGA: 21/09/23
INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
		     MIGUEL CANO MENÉNDEZ (miguel.cano@udc.es)
*/

#include "prepararVector.h"

void selectorCombinacionesLeerTiempo(int n);

void seleccionarCotas(int sC, double t, int size);

void cabecera(int sC);

double tiempoPrepararVector(int size, int repeticiones, int sV);

void leerTiempo (int sV, int sC);

void cabeceraTablas(int s);

double microsegundos();

void inicializar_semilla();

double seleccionarOrdenacionRep(int sV, int v[], int size, int rep);

double seleccionarOrdenacion(int v[], int size);

void ordenar (int v[], int n);
void auxOrd (int v[], int izq, int der);