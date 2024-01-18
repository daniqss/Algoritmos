#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#define TAM_MAX 1000

typedef int ** matriz;


//Firma das funcións
matriz crearMatriz(int n);
void iniMatriz(matriz m, int n);
void liberarMatriz(matriz m, int n);
void dijkstra(matriz grafo, matriz distancias, int tam);

void mostrarMatriz(matriz m,int n);
void mostrarParMatriz(matriz m, matriz d, int n);
void copiarMatriz(matriz m, int v[5][5], int n);

void test();
void test2();

void mostrarCotas();
void mostrarResultado(int n,double t);

void inicializar_semilla();
void aleatorio(int v [], int n);
double microsegundos();

//Main
int main() {
	inicializar_semilla();

	test();
	test2();

	return 0;
}

//Definición das funcións
void dijkstra(matriz grafo, matriz distancias, int tam) {	//Implementación Algoritmo dijkstra
	int n, i, j, min, v=0;
	int *noVisitados = malloc(tam*sizeof(int));
	
	for (n=0; n<tam; n++) {	
		for (i=0; i<tam; i++){	 
			noVisitados[i] = 1;	//Marcamos todos os nodos como non visitados
			distancias[n][i] = grafo[n][i];
		}

		noVisitados[n] = 0;	//Marcamos o nodo actual como visitado
		j=0;
		
		while(j<(tam-2)){  

			min= TAM_MAX+1;

			for(i=0;i<tam;i++){	//Buscamos o nodo de noVisitados que minimiza Distancias 
				if(noVisitados[i]==1 && distancias[n][i]<min ){
					v=i;
					min=distancias[n][i];
				}
			}
			
			noVisitados[v]=0;

			for (i=0; i<tam; i++){	//para cada w de noVisitados comprobamos
				if( (noVisitados[i]==1) && (distancias[n][i]> distancias[n][v] + grafo[v][i]) )
					distancias[n][i]=distancias[n][v]+grafo[v][i];
			}
			j++;
		}
	}
	
	free(noVisitados);
}

matriz crearMatriz(int n) {		//Función para crear unha matriz nxn
	int i;
	matriz aux;
	if ((aux = malloc(n*sizeof(int *))) == NULL)
		return NULL;
	for (i=0; i<n; i++)
		if ((aux[i] = malloc(n*sizeof(int))) == NULL)
			return NULL;
	return aux;
}

void iniMatriz(matriz m, int n) {	//Función para inicializar unha matriz pseudoaleatoriamente
	int i, j;
	for (i=0; i<n; i++)
		for (j=i+1; j<n; j++)
			m[i][j] = rand() % TAM_MAX + 1;	//asignamos valores pseudoaleatorios hasta TAM_MAX
	for (i=0; i<n; i++)
		for (j=0; j<=i; j++)
			if (i==j)
				m[i][j] = 0;	//Asignamos na diagonal ceros
			else
				m[i][j] = m[j][i];	//Ao ser simetrica a matriz de adyacencia, copiamos os valores no outro lado da diagonal
}
void liberarMatriz(matriz m, int n) {	//Función para liberar a asignación de memoria dunha matriz
	int i;
	for (i=0; i<n; i++)
		free(m[i]);
	free(m);
}
void mostrarMatriz(matriz m,int n){		//Función para mostrar o contido dunha matriz
	int i, j;
	for (i=0; i<n; i++) {
		printf(" ");;
		for (j = 0; j < n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
    }
}

void mostrarParMatriz(matriz m, matriz d, int n){	//Función para mostrar o par matriz de adyacencia e distancias

	puts(" Matriz adyacencia:");
	mostrarMatriz(m,n);
	puts(" Distancias:");
	mostrarMatriz(d,n);

}

void copiarMatriz(matriz m, int v[5][5], int n){	//Función para asignar os valores dun array bidimensional 5x5 a unha matriz
	int i, j;
	for (i=0; i<n; i++)
		for (j = 0; j < n; j++)
			m[i][j]=v[i][j];	//Pasamos os valores do array bidmensional á matriz

}

void inicializar_semilla(){		//Función que iniciará unha semilla para xerar os valores aleatorios.

	srand(time(NULL));

}

double microsegundos() { //Obten a hora do sistema en microsegundos

	struct timeval t;
	if (gettimeofday(&t, NULL) < 0 )
		return 0.0;
	return (t.tv_usec + t.tv_sec * 1000000.0);

}

void test(){	//Función Test para verificar o correcto funcionamento da implementación

	matriz m,d;
	int m2[5][5] = {{0,1,8,4,7},{1,0,2,6,5},{8,2,0,9,5},{4,6,9,0,3},{7,5,5,3,0}};
	int m3[5][5] = {{0,1,4,7,0},{1,0,2,8,0},{4,2,0,3,0},{7,8,3,0,0},{0,0,0,0,0}};	//Añadimos unha columna de 0 e unha fila de 0 para poder pasala como unha matrix 5x5

	puts("\n[TEST IMPLEMENTACIÓN]");
	
	//Creamos as matrices que empregaremos
	m=crearMatriz(5);
	d=crearMatriz(5);

	//Primeiro exemplo
	copiarMatriz(m, m2,5);
	dijkstra(m,d,5);
	mostrarParMatriz(m,d,5);
	puts("");

	//Segundo exemplo
	copiarMatriz(m, m3,4);
	dijkstra(m,d,4);
	mostrarParMatriz(m,d,4);
	puts("");

	//Liberamos as matrices empregadas
	liberarMatriz(m,5);
	liberarMatriz(d,5);

}
void test2(){		//Test para calcular a complexidade do algoritmo empíricamente

	matriz m,d;
	int i,j,a, K=1000,n;
	double antes,despues,t,t1,t2;
	m=crearMatriz(960);
	d=crearMatriz(960);

	printf("\n[CÁLCULO COMPLEXIDADE]");
	printf("\nAlgoritmo Dijkstra:");

	for(j=0; j<3; j++){		//Bucle no que realizaremos as mediciones 3 veces para evitar erros ao inicio da medición.

		n=15;	

		mostrarCotas();

		for(i=0;i<=6;i++){		//Bucle para aumentar n


			iniMatriz(m,n);

			antes=microsegundos();
			dijkstra(m,d,n);		//Chamamos ao algoritmo
			despues=microsegundos();

            t=despues-antes;

			if(t<500){				//Calculamos o promedio de tempo nos casos que non supere o umbral
				antes=microsegundos();

				for(a=0; a<K ;a++){
					iniMatriz(m,n);
					dijkstra(m,d,n);
				}

				despues=microsegundos();
				t1=despues-antes;
				antes= microsegundos();

				for(a=0; a<K ;a++){
					iniMatriz(m,n);
				}
				despues=microsegundos();
				t2= despues-antes;
				t=(t1-t2)/K;

			}
			mostrarResultado(n,t);
			n=n*2;


		}
    }
    
	liberarMatriz(m,960);
	liberarMatriz(d,960);
}

void mostrarCotas() {	//Función para mostrar as cotas empregada

	printf("\n%6s\t\t%11s\t\t\tt(n)/n^2.65\t\t","n","t(n)");
	printf("t(n)/n^2.755\t\tt(n)/n^2.95\t\tt(n)/n^3\n");
}

void mostrarResultado(int n,double t){	//Función para mostrar os resultados do algoritmo

	printf("%6.d\t\t%11.3lf\t\t\t%lf\t\t",n, t, (t)/pow(n, 2.65));
	printf("%lf\t\t%lf\t\t%lf\n", (t)/pow(n, 2.755), (t)/pow(n,2.95), (t)/pow(n,3.0));
    
}
