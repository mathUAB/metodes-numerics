INSTRUCCIONES DE USO DE LOS CODIGOS

Los programas de cada problema se llaman: 
Pro#.c
donde # es el numero del problema.
Para compilar los codigos usar la instruccion (suponiendo que queremos compilar el fichero codigo.c): 
gcc -Wall -pedantic -o codigo codigo.c -lm

PROBLEMA 1:
	INPUT: -
	OUTPUT: - por pantalla imprime los errores maximos que se producen interpolando con n+1 nodos equidistantes o de Chebyshev para n=4,8,16,32.
			- genera ficheros llamados "interpolacio#.txt" donde #=0,1,2,3,4,5,6,7. Propiedades de los ficheros:
				-) Todos los ficheros tienen 3 columnas.
				-) Todos los ficheros tienen los valores x_k en la primera columna i los valores de f(x_k) en la segunda.
				-) Los ficheros "interpolacio#.txt", #=0,1,2,3 contienen en la tercera columna los valores del polinomio interpolador evaluado en los puntos x_k creado con nodos equidistantes y de grado 4, 8, 16 i 32, respectivamente.
				-) Los ficheros "interpolacio#.txt", #=4,5,6,7 contienen en la tercera columna los valores del polinomio interpolador evaluado en los puntos x_k creado con nodos de Chebyshev y de grado 4, 8, 16 i 32, respectivamente.
	Si se quieren crear graficos se puede hacer ejecutando el siguiente comando, por ejemplo:

	gnuplot -p -e "plot 'interpolacio0.txt' using 1:2 with lines title 'f(x)','interpolacio4.txt' using 1:3 with lines title 'n=4','interpolacio5.txt' using 1:3 with lines title 'n=8','interpolacio6.txt' using 1:3 with lines title 'n=16'"

	En este caso se grafica la funcin f(x) juntamente con los polinomios interpoladores creados con n+1 nodos de Chebyshev para n=4,8,16. Analogamente se hace el caso con nodos equidistantes utilizando sus respectivos ficheros.

	Alternativamente se ha añadido un script "plot.sh" que compila el fichero "pro1.c" y devuelve por pantalla automaticamente dos graficos (uno con los polinomios interpoladores creados con nodos equidistantes y el otro con los polinomios interpoladores creados con nodos de Chebyshev). Debe ser ejecutado como "./plot.sh".  				 

PROBLEMA 2:
	INPUT: -
	OUTPUT: - aproximaciones de la raiz de la funcion J0(x) utilizando interpolacion inversa de valores positivos, negativos y mixtos y grados 1, 3 y 5.

PROBLEMA 4:
	INPUT: -
	OUTPUT: aproximacion de la integral mediante el metodo de los trapecios y de Simpson.

PROBLEMA 5:
	INPUT: -
	OUTPUT: aproximacion de la integral mediante el metodo de los trapecios partiendo el intervalo en n partes iguales, n=4,8,16,32,64.
	
PROBLEMA 6: 
	INPUT: -
	OUTPUT: aproximacion de la integral mediante el metodo de Simpson.

PROBLEMA 7: 
	INPUT: -
	OUTPUT: longitud de la pista.
