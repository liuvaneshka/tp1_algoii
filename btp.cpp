#include <iostream>
#include <string>

using namespace std;

bool validar_cantidad_parametros(int cantidad){
	
	/*
	PRE: recibe un entero positivo
	POST: retorna un booleano verdadero si esta entre 1 y 3, falso cualquier otra numero
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
	PRE: recibe un doble puntero ( arreglo de punteros a str) que contiene el argumento 
	POST: retorna un entero que representa la cantidad de caracteres del argumento
	*/

	char c;
	int cantidad = 0;

	do{
		c = argumento[cantidad];
		//cout << argumento[cantidad] << " tipo de dato " << typeid(argumento[cantidad]).name() << endl;
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

		caracter = tolower(argumento[i]);
		cadena = cadena + caracter;
	}

	return cadena;
}


void buscar_argumento(int t_texto, int t_fragmento, string texto, string fragmento){

	int posicion = 0, coincidencias = 0;
	int posicion_final_valida = t_texto - t_fragmento;
	int* p;
	p = new int[coincidencias];

	for(int i = 0; i < t_texto; i++){

		int k = 0, coincidencia = 0;

		for(int j = 0; j < k+1; j++){

			cout << texto[i] << " " << fragmento[j] << j << endl;

			if(texto[i] == fragmento[j]){

				coincidencia++;
				i++;
				k++;
			} 

			if( (j == (t_fragmento - 1)) && (coincidencia == t_fragmento) ){

				posicion = i - coincidencia;
				coincidencias++;
				cout << "posicion " << posicion << endl;
				k=0;
				i = i - 1 ;
				p[posicion];

			}

			if((i == posicion_final_valida) && ( texto[i] != fragmento[j]) && (coincidencia == 0)){

				k = 0;
				i = t_texto;				
			}
		}
	}

	cout << "coincidencias totales " << coincidencias <<endl;
	for(int l = 0; l<=coincidencias; l++)
		cout << p[l] << "  ";
	cout << endl;
	delete[]p;
	p = 0;

}


int main(int argc, char* argv[]){

	cout << "Cantidad de argumentos: " << argc << endl;
	bool cantidad_parametros = false ;
	int cantidad_texto = 0, cantidad_busqueda = 0;
	string texto, fragmento;

	cantidad_parametros = validar_cantidad_parametros(argc);
	cantidad_texto = cantidad_caracteres(argv[1]);
	cantidad_busqueda = cantidad_caracteres(argv[2]);

	while((cantidad_parametros) && (cantidad_texto >= cantidad_busqueda)){
		
		texto = crear_cadena_del_argv(cantidad_texto, argv[1]);
		cout << "texto " << texto << endl;
		fragmento = crear_cadena_del_argv(cantidad_busqueda, argv[2]);
		cout << "buscar " << fragmento << endl;

		buscar_argumento(cantidad_texto, cantidad_busqueda, texto, fragmento);

		cantidad_parametros = false;
	};


	return 0;
}
