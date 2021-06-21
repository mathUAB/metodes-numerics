INSTRUCCIONES DE USO DE LOS CODIGOS

Los programas de cada problema se llaman: 
Pro#-*.c o Pro#.c
donde # es el numero del problema y * hace referencia al apartado del problema (si es que hay mas de un apartado).
Para compilar los codigos usar la instruccion (suponiendo que queremos compilar el fichero codigo.c): 
gcc -Wall -pedantic -o codigo codigo.c -lm

PROBLEMA 1:
Hay tres programas, uno para cada apartado. 
	apartado a):
		INPUT: -
		OUTPUT: valor de la solucion de la ecuacion x^3=x+40 utilizando la formula de Cardano en simple y doble precision.
	apartado b):
		INPUT: -
		OUTPUT: valor de la solucion de la ecuacion x^3=x+40 utilizando el metodo de Newton en simple y doble precision.
	apartado c):
		INPUT: -
		OUTPUT: valor de la solucion de la ecuacion x^3=x+400 utilizando la formula de Cardano, el metodo de la biseccion, el metodo de la secante y el metodo de Newton juntamente con el numero de iteraciones requeridas en cada caso. Todos ellos evaluados en doble precision.

PROBLEMA 2:
	INPUT: valor de la aproximacion inicial de la iteracion.
	OUTPUT: - solucion del limite de la iteracion juntamente con el numero de iteraciones que han sido necesarias.
			- tabla de doble entrada para estudiar el orden de convergencia del metodo. En la fila k se muestran los cocientes e_k/e_(k-1)^p y en las columnas los distintos valores de p.

PROBLEMA 3:
	INPUT: valor de la aproximacion inicial de la iteracion.
	OUTPUT: - solucion del limite de la iteracion juntamente con el numero de iteraciones que han sido necesarias.
			- tabla de doble entrada para estudiar el orden de convergencia del metodo. En la fila k se muestran los cocientes e_k/e_(k-1)^p y en las columnas los distintos valores de p.

PROBLEMA 4:
	INPUT: numero de iteraciones que se desean realizar.
	OUTPUT: - lista de los iterados hasta el numero introducido en INPUT.
			- tabla de doble entrada para estudiar el orden de convergencia del metodo. En la fila k se muestran los cocientes e_k/e_(k-1)^p y en las columnas los distintos valores de p.
	
PROBLEMA 5: 
	INPUT: -
	OUTPUT: comprovacion de la formula del apartado b) usando varios valores para k y a_0=x.
