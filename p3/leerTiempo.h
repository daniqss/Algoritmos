#include "prepararVector.h"

#define TAM 256000

struct monticulo {
    int ultimo;
    int vector[TAM];
};

typedef struct monticulo* pmonticulo;

void selectorCombinacionesLeerTiempo(int n);

void seleccionarCotas(int sC, double t, int size);

void cabecera(int sC);

double tiempoPrepararVector(int size, int repeticiones, int sV);

void leerTiempo (int s, int sV, int sC);

void cabeceraTablas(int s);

double microsegundos();

void inicializar_semilla();

double seleccionarOrdenacionRep(int s, int sV, int v[], int size, int rep,
pmonticulo* m);

double seleccionarOrdenacion(int s, int v[], int size, pmonticulo* m);

void crearMonticulo(int v [], int size, pmonticulo* m);

bool vacioMonticulo(pmonticulo m);

int quitarMenor(pmonticulo* m);

void copiarVector(const int v1[], int v2[], int size);

void hundir(pmonticulo* m, int i);

void flotar(pmonticulo* m, int i);

void OrdenarPorMonticulos(int v[], int size, pmonticulo* m);

void intercambiar(int* i, int* j);

void inicializarMonticulo(pmonticulo* m);
