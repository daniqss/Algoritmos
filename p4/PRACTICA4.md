//ASIGNATURA: ALGORITMOS
//PRACTICA: Dijkstra
//FECHA DE ENTREGA: 25/11/23
//INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
//             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
               MIGUEL CANO MENENDEZ (miguel.cano@udc.es)


1. Introduccion: explicacion y caracteristicas de la maquina: 


En este informe se indica el estudio de varias mediciones de tiempo y se calcula empiricamente la complejidad del algoritmo de
Dijkstra de matrices de n x n elementos (Representan grafos completos no dirigidos). Se han tomado para cada matriz unos valores inicializados de forma aleatoria.
Las matrices (n x n) han sido inicializadas con una cantidad de elementos n igual a 8, 16, 32, 64, 128, 256, 512. 
 
Para la medicion de los tiempos se usaran como unidades los microsegundos y se denotara en las tablas como t(n).
Los tiempos inferiores a 500 microsegundos seran un promedio de un determinado numero de repeticiones “K” realizadas sobre
dicho algoritmo para reducir el error de medicion, K se indicara en las tablas. 


La maquina en la que se ejecuto el programa y se tomaron los tiempos es la siguiente: 
           -Tipo de maquina 
                         Portatil
                -Modelo 
                         ASUS ROG Strix G513IH - G513IH
 
                -Nombre del SO
                        Ubuntu 22.04.1 LTS


                -Tipo SO
                        64 bits


                -Memoria RAM 
                        16,00 GB 3200Mhz
                 
                -Procesador 
                        AMD Ryzen 7 4800H 


                -Frecuencia del procesador 
                        4.20GHz 


                -Placa base 
                        MS-16JF 


                -Tarjetas graficas
                        Radeon Graphics x 16
                        NVIDIA GEFORCE GTX 1650 4G (No detecta por drivers)


======================================================================


2. Tiempos y complejidad

Tabla tiempos Dijkstra

    n           t(n)       t(n)/n^2.7     t(n)/n^2.8     t(n)/n^2.9     t(n)/n^2.0
*   8         5.0090       0.018256       0.014829       0.012045       0.078266
*  16        38.0742       0.021355       0.016184       0.012265       0.148727
*  32       278.1595       0.024010       0.016978       0.012005       0.271640
   64      1937.0000       0.025730       0.016976       0.011200       0.472900
  128     12819.0000       0.026205       0.016131       0.009930       0.782410
  256     89179.0000       0.028055       0.016114       0.009255       1.360764
  512    635229.0000       0.030754       0.016481       0.008832       2.423206



"*" -> Se han realizado 10000 repeticiones.



t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^2.7 es una cota ajustada
n^2.8 es una cota subestimada
n^2.9 es una cota sobrestimada
n^2.0 es una cota teorica


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.016
Es importante destacar que se descarta el valor de 8, porque se desvia de la cota ajustada.


======================================================================


3. Conclusion

Despues de la realizacion del estudio y de la medicion de tiempos llegamos a la conclusion de
que la implementacion realizada se aleja bastante de la cota teorica. Esto se puede ver en que la 
cota ajustada es n^2.8 y la teorica es n^2, siendo mucho peor la obtenida llegando casi a ser n^3.
Podemos ver que consigue repeticiones hasta matrices de 32 x 32 elementos y que para el caso
de 8 x 8 en la mayoria de tablas obtenidas el valor de tiempo es ligeramente menor que el resto. 
