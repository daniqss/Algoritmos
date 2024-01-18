//ASIGNATURA: ALGORITMOS
//PRÁCTICA: Suma de Subsecuencia Máxima
//FECHA DE ENTREGA: 30/09/23
//INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
//             DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
               MIGUEL CANO MENÉNDEZ (miguel.cano@udc.es)


1. Introducción: explicación y características de la máquina: 


En este informe se miden los tiempos y se calcula empíricamente la complejidad de dos algoritmos que calculan la suma de la subsecuencia máxima de un vector de tamaño n igual a 500, 1000, 2000, 4000, 8000, 16000 y 32000 para el algoritmo SumaSubMax y n igual a los anteriores, más, 64000, 128000 y 256000 para SumaSubMax2. 


*Suma de Subsecuencia Máxima: Algoritmo encargado de encontrar la suma máxima de un subconjunto de elementos contiguos en una secuencia dada.
 
Para la medición de los tiempos se usarán como unidades los microsegundos y se
denotará en las tablas como t(n). Los tiempos inferiores a 500 microsegundos serán un promedio de un determinado número de repeticiones “K” realizadas sobre dicho algoritmo para reducir el error de medición, K se indicará en las tablas. 


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


Tabla tiempos SumaSubMax
 
           n             t(n)        t(n)/n^1.8        t(n)/n^2        t(n)/n^2.2
 *       500           251.325      0.003484         0.001005          0.000290
        1000           989.000      0.003937         0.000989          0.000248
        2000          3942.000      0.004507         0.000986          0.000216
        4000         15727.000      0.005163         0.000983          0.000187
        8000         62893.000      0.005930         0.000983          0.000163
       16000        251764.000      0.006817         0.000983          0.000142
       32000       1005332.000      0.007817         0.000982          0.000123
 
¡AVISO!: Las filas en rojo indican que se han realizado 10000 repeticiones
(NOTA: En este informe las filas en rojo se indican con un asterisco)


t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;;
h(n) = t(n)/n^2.2 es una cota sobrestimada
g(n) = t(n)/n^2.0  es una cota ajustada
f(n) = t(n)/n^1.8 es una cota subestimada


La constante que presenta esta tabla para la cota ajustada es aproximadamente 0.00098.
Es importante destacar que se descarta el valor de 500 ya que se desvía ligeramente de las constantes indicadas.




 
Tabla tiempos SumaSubMax2
 
           n          t(n)       t(n)/n^0.9     t(n)/n^0.95     t(n)/n^1.0
*        500         1.433       0.005337       0.003912       0.002867
*       1000         2.720       0.005428       0.003843       0.002720
*       2000         5.409       0.005784       0.003955       0.002705
*       4000        10.064       0.005767       0.003809       0.002516
*       8000        19.473       0.005979       0.003815       0.002434
*      16000        37.673       0.006199       0.003821       0.002355
*      32000        80.672       0.007114       0.004235       0.002521
*      64000       146.277       0.006912       0.003975       0.002286
*     128000       286.605       0.007258       0.004031       0.002239
      256000       564.000       0.007654       0.004106       0.002203
 
¡AVISO!: Las filas en rojo indican que se han realizado 10000 repeticiones
(NOTA: En este informe las filas en rojo se indican con un asterisco)




t(n) = ((tf - ti)/rep) - (tfr - tir)/rep;;
f(n) = t(n)/n^1.0 es una cota sobrestimada
g(n) = t(n)/n^0.95  es una cota ajustada
h(n) = t(n)/n^0.9 es una cota ligeramente subestimada







La constante que presenta esta tabla para la cota ajustada es aproximadamente entre 0.0038 y 0.0039.
Es importante destacar que se descartan los valores de 32000, 128000, 256000, ya que se desvían ligeramente de las constantes indicadas. 


======================================================================


3. Conclusión


Tras el estudio realizado sobre los tiempos de los dos algoritmos podemos observar que SumaSubMax2 es más eficiente que SumaSubMax debido a que sus cotas ajustadas son muy distintas e incluso una mayor que la otra. Aparte, la cota ajustada de Sumasubmax es “n” elevado al cuadrado mientras que la cota ajustada de SumaSubMax2 es “n” elevado a 0.95, con lo que concluimos que una tiene complejidad cuadrática (O(n²) y la otra prácticamente lineal ((O(n^0.95). Cabe recalcar también el número de repeticiones de ambos casos:mientras que en SumaSubMax2 éste soporta hasta 128000, en SumaSubMax solo se pueden producir hasta 500, por lo que deducimos que en SumaSubMax2 se necesitan 256000 objetos para superar los 500 microsegundos en una ejecución (por como funciona el código). Por otro lado, el SumaSubMax con 1000 objetos ya supera los 500.