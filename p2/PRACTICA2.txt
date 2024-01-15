//ASIGNATURA: ALGORITMOS
//PRÁCTICA: Ordenación por insercion y ordenación shell
//FECHA DE ENTREGA: 21/10/23
//INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
//             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
               MIGUEL CANO MENÉNDEZ (miguel.cano@udc.es)


1. Introducción: explicación y características de la máquina: 


En este informe se indica el estudio de varias mediciones de tiempo y se calcula empíricamente la complejidad de dos algoritmos 
de ordenación. Se han tomado tres tipos de vectores para el estudio, uno inicializado aleatoriamente, otro de forma descendente
y el último de forma ascendente. Los tamaños usados, n igual a 500, 1000, 2000, 4000, 8000, 16000 y 32000 para ambos
algoritmos en los casos aleatorios y descendente, más, 64000, 128000 y 256000 para ambos algoritmos solo en los casos ascendentes. 
 
Para la medición de los tiempos se usarán como unidades los microsegundos y se denotará en las tablas como t(n).
Los tiempos inferiores a 500 microsegundos serán un promedio de un determinado número de repeticiones “K” realizadas sobre
dicho algoritmo para reducir el error de medición, K se indicará en las tablas. 


La máquina en la que se ejecutó el programa y se tomaron los tiempos es la siguiente: 
           -Tipo de máquina 
                         Portátil
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


                -Tarjetas gráficas
                        Radeon Graphics x 16
                        NVIDIA GEFORCE GTX 1650 4G (No detecta por drivers)


======================================================================


2. Tiempos y complejidad

Tabla tiempos OrdInsercion Aleatorio

           n           t(n)       t(n)/n^1.8      t(n)/n^2.0      t(n)/n^2.1
*        500       136.0450       0.001886       0.000544       0.000292
        1000       501.0000       0.001995       0.000501       0.000251
        2000      2027.0000       0.002317       0.000507       0.000237
        4000      8073.0000       0.002650       0.000505       0.000220
        8000     33300.0000       0.003140       0.000520       0.000212
       16000    127709.0000       0.003458       0.000499       0.000189
       32000    508414.0000       0.003953       0.000496       0.000176

¡AVISO!: Las filas en rojo indican que se han realizado 10000 repeticiones
(NOTA: En este informe las filas en rojo se indican con un asterisco)


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^1.8 es una cota ajustada
n^2.0 es una cota subestimada
n^2.1 es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.00050.
Es importante destacar que se descarta el valor de 500 y 8000 ya que se desvía ligeramente de las constantes indicadas.





Tabla tiempos OrdInsercion Descendente

           n           t(n)       t(n)/n^1.9     t(n)/n^2.0     t(n)/n^2.1
*        500       245.9959       0.001832       0.000984       0.000529
        1000       957.0000       0.001909       0.000957       0.000480
        2000      3808.0000       0.002036       0.000952       0.000445
        4000     15251.0000       0.002185       0.000953       0.000416
        8000     61001.0000       0.002341       0.000953       0.000388
       16000    243491.0000       0.002504       0.000951       0.000361
       32000    968890.0000       0.002670       0.000946       0.000335

¡AVISO!: Las filas en rojo indican que se han realizado 10000 repeticiones
(NOTA: En este informe las filas en rojo se indican con un asterisco)


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^1.9 es una cota ajustada
n^2.0 es una cota subestimada
n^2.1 es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.00095
Es importante destacar que se descarta el valor de 500 ya que se desvía ligeramente de las constantes indicadas.





Tabla tiempos OrdInsercion Ascendente

           n           t(n)       t(n)/n^0.9      t(n)/n^1.0      t(n)/n^1.1
*        500         1.3188       0.004910       0.002638       0.001417
*       1000         2.6703       0.005328       0.002670       0.001338
*       2000         5.3145       0.005682       0.002657       0.001243
*       4000        10.6159       0.006083       0.002654       0.001158
*       8000        21.2467       0.006524       0.002656       0.001081
*      16000        42.4062       0.006978       0.002650       0.001007
*      32000        86.0218       0.007585       0.002688       0.000953
*      64000       150.8093       0.007126       0.002356       0.000779
*     128000        98.6086       0.002497       0.000770       0.000238
      256000       678.0000       0.009201       0.002648       0.000762

¡AVISO!: Las filas en rojo indican que se han realizado 10000 repeticiones
(NOTA: En este informe las filas en rojo se indican con un asterisco)


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^0.9 es una cota ajustada
n^1.0 es una cota subestimada
n^1.1 es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.0026
Es importante destacar que se descarta el valor de 64000 y 128000 ya que se desvía ligeramente de las constantes indicadas.





Tabla tiempos OrdShell Aleatorio

           n           t(n)       t(n)/n^1.1      t(n)/n^1.17      t(n)/n^1.3
*        500        44.7483       0.048074       0.031116       0.013871
*       1000       102.7247       0.051484       0.031745       0.012932
*       2000       234.3228       0.054788       0.032182       0.011981
        4000       510.0000       0.055629       0.031129       0.010590
        8000      1150.0000       0.058519       0.031195       0.009698
       16000      2597.0000       0.061651       0.031308       0.008894
       32000      5922.0000       0.065585       0.031728       0.008237

¡AVISO!: Las filas en rojo indican que se han realizado 10000 repeticiones
(NOTA: En este informe las filas en rojo se indican con un asterisco)


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^1.1  es una cota ajustada
n^1.17 es una cota subestimada
n^1.3  es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.031
Es importante destacar que se descarta el valor de 2000 ya que se desvía ligeramente de las constantes indicadas.





Tabla tiempos OrdShell Descendente

           n           t(n)       t(n)/n^1.0      t(n)/n^1.15      t(n)/n^1.3
*        500        17.2473       0.034495       0.013580       0.005346
*       1000        38.8423       0.038842       0.013782       0.004890
*       2000        86.2784       0.043139       0.013795       0.004411
*       4000       190.5015       0.047625       0.013726       0.003956
*       8000       414.6219       0.051828       0.013462       0.003497
       16000       916.0000       0.057250       0.013402       0.003137
       32000      1999.0000       0.062469       0.013179       0.002780

¡AVISO!: Las filas en rojo indican que se han realizado 10000 repeticiones
(NOTA: En este informe las filas en rojo se indican con un asterisco)


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^1.9  es una cota ajustada
n^1.15 es una cota subestimada
n^1.3  es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.013





Tabla tiempos OrdShell Ascendente

           n           t(n)       t(n)/n^1.0      t(n)/n^1.125      t(n)/n^1.3
*        500        11.6021       0.023204       0.010671       0.003596
*       1000        26.5141       0.026514       0.011181       0.003338
*       2000        59.2372       0.029619       0.011453       0.003029
*       4000       129.2779       0.032319       0.011461       0.002684
*       8000       291.1588       0.036395       0.011835       0.002455
       16000       620.0000       0.038750       0.011555       0.002123
       32000      1379.0000       0.043094       0.011783       0.001918
       64000      2994.0000       0.046781       0.011730       0.001691
      128000      6435.0000       0.050273       0.011559       0.001476
      256000     13691.0000       0.053480       0.011276       0.001276

¡AVISO!: Las filas en rojo indican que se han realizado 10000 repeticiones
(NOTA: En este informe las filas en rojo se indican con un asterisco)


t(n) = tf - ti; 
t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;; Para repeticiones
n^1.0   es una cota ajustada
n^1.125 es una cota subestimada
n^1.3   es una cota sobrestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.011.
Es importante destacar que se descarta el valor de 500 ya que se desvía ligeramente de las constantes indicadas.

======================================================================


3. Conclusión


Tras el estudio realizado sobre los tiempos de los dos algoritmos podemos observar que Ordenación Shell es 
más eficiente que Ordenación Inserción en los casos de vectores aleatorios y descendentes
debido a que sus cotas ajustadas son muy distintas e incluso unas mayores que las otras. Por otra parte,
en los casos de ordenar vectores ordenados es decir, vectores ascendentes, Ordenación Inserción es ligeramente
mejor. 
Las cotas ajustadas para vectores aleatorios y descendentes en caso de Shell son O(n^1.17) y O(n^1.15) respectivamente, y para
Inserción son O(n^2) y O(n^2) con lo que podemos ver cotas ajustadas menores en caso de Shell, para estos dos tipos de vectores.
Por otro lado para el caso de vectores ascendentes en caso de Shell tenemos una cota superior O(n^1.125) y para Inserción, O(n), con
lo que es ligeramente mejor.
Teniendo en cuenta las repeticiones en los casos aleatorios y descendentes para Shell, este primero es capaz de soportar 10000
repeticiones hasta los 2000 elementos y el segundo 8000, mientras que en Inserción en ambos casos solo es capaz de llegar a 500.
Para el caso ascendente, Shell es capaz de soportar 8000 y Inserción 128000 elementos, con lo que vemos su mayor eficiencia en el 
caso de vectores ordenados.

Con todo esto llegamos a la conclusión de que el mejor algoritmo de ordenación para vectores ya ordenados, es decir, ascendentes, es
Inserción, y para el resto de casos, vectores aleatorios o ordenados de forma inversa (descendente) es mejor Shell.