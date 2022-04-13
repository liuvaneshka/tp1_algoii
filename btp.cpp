#include <iostream>

using namespace std;

bool validar_cantidad_parametros(int cantidad){
	
	/*
	PRE: recibe un entero positivo
	POST: retorna un booleano verdadero si esta entre 1 y 3, 
		falso cualquier otro numero
	*/

	bool cantidad_validada = true;

	if( (cantidad > 1) && (cantidad <= 3)){
		cantidad_validada = true;
	}

	else{
		cantidad_validada = false;
	}

	return cantidad_validada;
}


int cantidad_caracteres(char argumento[]){

	/*
	PRE: recibe un doble puntero (arreglo de punteros a str) que contiene el
	    argumento 
	POST: retorna un entero que representa la cantidad de caracteres del 
		argumento
	*/

	char c;
	int cantidad = 0;

	do{
		c = argumento[cantidad];
		//cout << c << " tipo " << typeid(argumento[cantidad]).name() << endl;
		cantidad++;

	}while(c != 0);

	cantidad = cantidad - 1; // el / del /0

	return cantidad;

}


string crear_cadena_del_argv(int tamanio,char argumento[]){

	/*
	PRE: recibe entero positivo que es la cantidad de caracateres del argumento
	POST: retorna una cadena de caracteres en minusculas
	*/

	string cadena;
	char caracter;

	for(int i = 0; i<= tamanio; i++ ){

		caracter = (char)tolower(argumento[i]);
		cadena = cadena + caracter;
	}

	return cadena;
}


void imprimir_resultado(int *posiciones, int coincidencias){
	
	/*
	PRE: recibe un puntero de enteros represetando la direccion de las posiciones
		donde hubo coincidencia, y un entero que representa el numero de 
		coincidencias que totales en la historia
	POST:
	*/

	if( coincidencias == 0 ){

		cout << "No se encuentra esa frase en la historia indicada." << endl;

	}

	else{

		for(int i = 0; i < coincidencias; i++)
			cout << posiciones[i] << "-";
		cout << endl;
	}

}


void buscar_argumento(int t_historia, int t_frase, string historia, string frase){
	/*
	PRE: recibe dos enteros, uno representa el tamanio de la historia
		otro representando el tamanio de la frase
		recibe dos cadenas, una es las historia, el segundo la frase a buscar
	POST: recorre la historia comparandola con el primer caracter de la frase 
		llama a la funcion imprimir resultado

	*/

	int posicion = 0, coincidencias = 0;
	int posicion_final_valida = t_historia - t_frase;
	int* p;
	p = new int[coincidencias];

	for(int i = 0; i < t_historia; i++){

		int k = 0, coincidencia = 0;

		for(int j = 0; j < k+1; j++){

			// imprime los valores q se comparan
			// cout << historia[i] << " " << frase[j] << j << endl;

			if(historia[i] == frase[j]){

				coincidencia++;
				i++;
				k++;
			} 

			if( (j == (t_frase - 1)) && (coincidencia == t_frase) ){

				posicion = i - coincidencia;
				p[coincidencias] = posicion;
				coincidencias++;
				k=0;
				i = i - 1 ;

			}

			if((i == posicion_final_valida) && (historia[i] != frase[j]) && (coincidencia == 0)){

				k = 0;
				i = t_historia;				
			}
		}
	}

	imprimir_resultado(p, coincidencias);

	delete[]p;
	p = NULL;

}


int main(int argc, char* argv[]){

	//cout << "Cantidad de argumentos: " << argc << endl;
	bool cantidad_parametros = false ;
	int cantidad_historia = 0, cantidad_busqueda = 0;
	string historia, frase;

	cantidad_parametros = validar_cantidad_parametros(argc);
	cantidad_historia = cantidad_caracteres(argv[1]);
	cantidad_busqueda = cantidad_caracteres(argv[2]);

	while((cantidad_parametros) && (cantidad_historia >= cantidad_busqueda)){
		
		historia = crear_cadena_del_argv(cantidad_historia, argv[1]);
		frase = crear_cadena_del_argv(cantidad_busqueda, argv[2]);

		buscar_argumento(cantidad_historia, cantidad_busqueda, historia, frase);

		cantidad_parametros = false;
	};


	return 0;
}
