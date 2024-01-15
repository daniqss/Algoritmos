//ASIGNATURA: ALGORITMOS
//PRACTICA: Ordenacion por Monticulos
//FECHA DE ENTREGA: 11/11/23
//INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
//             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
               MIGUEL CANO MENENDEZ (miguel.cano@udc.es)


1. Introduccion: explicacion y caracteristicas de la maquina: 


En este informe se indica el estudio de varias mediciones de tiempo y se calcula empiricamente la complejidad de crear un
monticulo a partir de un vector de n elementos y de la ordenacion por monticulo. Se han tomado tres tipos de 
vectores para el estudio, uno inicializado aleatoriamente, otro de forma descendente y el ultimo de forma ascendente.
Los vectores usados tanto para crear monticulos como para ordenarlos por monticulos son de tamaño n igual a 500, 1000,
2000, 4000, 8000, 16000, 32000 64000, 128000 y 256000. 
 
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

Tabla tiempos CrearMonticulo Aleatorio

           n           t(n)       t(n)/n^0.9      t(n)/n^1.0      t(n)/n^1.1
*        500        12.5683       0.046795       0.025137       0.013502
*       1000        25.9775       0.051832       0.025978       0.013020
*       2000        51.3897       0.054948       0.025695       0.012016
*       4000        99.1783       0.056828       0.024795       0.010818
*       8000       197.9410       0.060779       0.024743       0.010072
*      16000       406.4914       0.066887       0.025406       0.009650
       32000       521.0000       0.045941       0.016281       0.005770
       64000      1061.0000       0.050136       0.016578       0.005482
      128000      2111.0000       0.053456       0.016492       0.005088
      256000      4190.0000       0.056859       0.016367       0.004711


"*" -> Se han realizado 10000 repeticiones.



t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^0.9 es una cota ajustada
n^1.0 es una cota subestimada
n^1.1 es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.025 para las repeticiones y 0.016 sin repeticiones.
Es importante destacar que se descarta el valor de 4000 y 8000 ya que se desvia ligeramente de las constantes indicadas.





Tabla tiempos CrearMonticulo Descendente

           n           t(n)       t(n)/n^0.9     t(n)/n^1.0     t(n)/n^1.1
*        500         5.8159       0.021654       0.011632       0.006248
*       1000        11.6830       0.023311       0.011683       0.005855
*       2000        23.3187       0.024933       0.011659       0.005452
*       4000        49.9106       0.028598       0.012478       0.005444
*       8000        92.4280       0.028381       0.011553       0.004703
*      16000       194.1874       0.031953       0.012137       0.004610
*      32000       376.2478       0.033177       0.011758       0.004167
       64000       738.0000       0.034873       0.011531       0.003813
      128000      1501.0000       0.038009       0.011727       0.003618
      256000      3015.0000       0.040914       0.011777       0.003390


"*" -> Se han realizado 10000 repeticiones.


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^0.9 es una cota ajustada
n^1.0 es una cota subestimada
n^1.1 es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.011
Es importante destacar que se descarta el valor de 4000 y 16000 ya que se desvia ligeramente de las constantes indicadas.





Tabla tiempos CrearMonticulo Ascendente

           n           t(n)       t(n)/n^0.9      t(n)/n^1.0      t(n)/n^1.1
*        500         3.2152       0.011971       0.006430       0.003454
*       1000         6.3200       0.012610       0.006320       0.003168
*       2000        12.5733       0.013444       0.006287       0.002940
*       4000        25.2148       0.014448       0.006304       0.002750
*       8000        49.8697       0.015313       0.006234       0.002538
*      16000        97.9024       0.016110       0.006119       0.002324
*      32000       198.0994       0.017468       0.006191       0.002194
*      64000       396.9440       0.018757       0.006202       0.002051
      128000       791.0000       0.020030       0.006180       0.001907
      256000      1591.0000       0.021590       0.006215       0.001789


"*" -> Se han realizado 10000 repeticiones.


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^0.9 es una cota ajustada
n^1.0 es una cota subestimada
n^1.1 es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente un valor comprendido entre 0.0061 y 0.0063. 
Es importante destacar que se descarta el valor de 500 ya que se desvia ligeramente de las constantes indicadas.





Tabla tiempos OrdenacionPorMonticulo Aleatorio

           n           t(n)       t(n)/n^1.0      t(n)/n^1.105      t(n)/n^1.2
*        500        56.3677       0.112735       0.058704       0.032529
*       1000       120.7098       0.120710       0.058444       0.030321
*       2000       261.2464       0.130623       0.058805       0.028564
        4000       530.0000       0.132500       0.055463       0.025223
        8000      1140.0000       0.142500       0.055461       0.023615
       16000      2433.0000       0.152062       0.055029       0.021938
       32000      5233.0000       0.163531       0.055025       0.020539
       64000     11427.0000       0.178547       0.055860       0.019522
      128000     24341.0000       0.190164       0.055319       0.018100
      256000     52225.0000       0.204004       0.055179       0.016904


"*" -> Se han realizado 10000 repeticiones.


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^1.0  es una cota ajustada
n^1.105 es una cota subestimada
n^1.2  es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.055 sin repeticiones y 0.058 con repeticiones.
Es importante destacar que se descarta el valor de 2000 ya que se desvia ligeramente de las constantes indicadas.





Tabla tiempos OrdenacionPorMonticulo Descendente

           n           t(n)       t(n)/n^1.0      t(n)/n^1.08      t(n)/n^1.2
*        500        36.9448       0.073890       0.044943       0.021320
*       1000        93.2297       0.093230       0.053648       0.023418
*       2000       212.5539       0.106277       0.057857       0.023240
*       4000       457.6738       0.114418       0.058929       0.021781
        8000       964.0000       0.120500       0.058714       0.019970
       16000      2003.0000       0.125188       0.057707       0.018061
       32000      4213.0000       0.131656       0.057416       0.016535
       64000      8905.0000       0.139141       0.057406       0.015213
      128000     18647.0000       0.145680       0.056862       0.013866
      256000     39776.0000       0.155375       0.057375       0.012875


"*" -> Se han realizado 10000 repeticiones.


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^1.0  es una cota ajustada
n^1.08 es una cota subestimada
n^1.2  es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente entre 0.057 y 0.058.
Es importante destacar que se descarta el valor de 500, 1000 y 128000 ya que se desvia ligeramente de las constantes indicadas.





Tabla tiempos OrdenacionPorMonticulo Ascendente

           n           t(n)       t(n)/n^1.0      t(n)/n^1.07      t(n)/n^1.2
*        500        31.9976       0.063995       0.041421       0.018465
*       1000        84.4752       0.084475       0.052087       0.021219
*       2000       200.1870       0.100094       0.058794       0.021888
*       4000       441.0631       0.110266       0.061702       0.020991
        8000       940.0000       0.117500       0.062636       0.019472
       16000      1968.0000       0.123000       0.062462       0.017745
       32000      4127.0000       0.128969       0.062391       0.016198
       64000      8744.0000       0.136625       0.062965       0.014938
      128000     18236.0000       0.142469       0.062548       0.013561
      256000     38247.0000       0.149402       0.062486       0.012380


"*" -> Se han realizado 10000 repeticiones.


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^1.0   es una cota ajustada
n^1.07 es una cota subestimada
n^1.2   es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.062.
Es importante destacar que se descarta el valor de 500, 1000 y 2000 ya que se desvia ligeramente de las constantes indicadas.

======================================================================


3. Conclusion


Tras el estudio realizado sobre los tiempos de los dos algoritmos podemos observar que Ordenacion Shell es 
mas eficiente que Ordenacion Insercion en los casos de vectores aleatorios y descendentes
debido a que sus cotas ajustadas son muy distintas e incluso unas mayores que las otras. Por otra parte,
en los casos de ordenar vectores ordenados es decir, vectores ascendentes, Ordenacion Insercion es ligeramente
mejor. 
Las cotas ajustadas para vectores aleatorios y descendentes en caso de Shell son O(n^1.17) y O(n^1.15) respectivamente, y para
Insercion son O(n^2) y O(n^2) con lo que podemos ver cotas ajustadas menores en caso de Shell, para estos dos tipos de vectores.
Por otro lado para el caso de vectores ascendentes en caso de Shell tenemos una cota superior O(n^1.125) y para Insercion, O(n), con
lo que es ligeramente mejor.
Teniendo en cuenta las repeticiones en los casos aleatorios y descendentes para Shell, este primero es capaz de soportar 10000
repeticiones hasta los 2000 elementos y el segundo 8000, mientras que en Insercion en ambos casos solo es capaz de llegar a 500.
Para el caso ascendente, Shell es capaz de soportar 8000 y Insercion 128000 elementos, con lo que vemos su mayor eficiencia en el 
caso de vectores ordenados.

Con todo esto llegamos a la conclusion de que el mejor algoritmo de ordenacion para vectores ya ordenados, es decir, ascendentes, es
Insercion, y para el resto de casos, vectores aleatorios o ordenados de forma inversa (descendente) es mejor Shell.