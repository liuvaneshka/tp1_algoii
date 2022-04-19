#ifndef HISTORIA_H_INCLUDED
#define HISTORIA_H_INCLUDED

/*
	PRE: Recibe un entero positivo, que seria la cantidad de coincidencias.
		Recibe a un puntero del arreglo auxiliar de enteros positivos representando
		al vector de posiciones.
		Recibe por referencia un puntero al arreglo de enteros representando el arreglo original
	POST: llena el vector auxiliar con los elementos del arreglo original libero la memoria del
		arreglo original, asigno la direccion del arreglo auxiliar al original.
*/
void copiar_vector(int coincidencias, int * aux, int * &arreglo);

/*
	PRE:Recibe un entero que representa el numero de coincidencias totales en la historia.
		Recibe por referencia un puntero de enteros represetando la direccion de las posiciones
		donde hubo coincidencia.
		Recibe un entero positivo representado la posicion de la coincidencia.
	POST:Si coincidencias es igual cero, incrementa las coincidencias, al arreglo le asigno memoria
		para la coincidencia, y le agrego e lelemento al arreglo.
		Cualquier otro caso, creo un puntero al arreglo auxiliar de tamanio coincidencias + 1,
		llamo a la funcion copiar vector, al auxliar le asigno la ultima posicion, e incremento
		las coincidencias.
*/
void almacenar_coincidencia(int &coincidencias, int * &arreglo, int posicion);

/*
	PRE: recibe dos enteros, uno representa el tamanio de la historia
		otro representando el tamanio de la frase
		recibe dos cadenas, una es las historia, el segundo la frase a buscar
	POST: Si coincidencias es mayor a cero,
		crea un elemento en el arreglo (posicion = -1) que es lo que va delimitar
		el final de mi vector. retorna la direccion de mi arreglo de enteros
		(posiciones de coinciencias)
*/
int* buscar_frase(char historia[], char frase[]);

/*
	PRE: Recibe un puntero de enteros represetando la direccion de las posiciones
		donde hubo coincidencia.
	POST: si recibe un puntero a nulo, imprime no se encuentran resultados,
		de lo contrario recorre el vector hasta que consiga el ultimo elemento que
		se que es -1 y los imprimo.
*/
void imprimir_resultado(int *posiciones);

#endif