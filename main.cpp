#include <iostream>
#include "historia.h"

using namespace std;

int main(int argc, char* argv[]){

	int cantidad_argumentos = argc;

	if(cantidad_argumentos == 3){ 
		char* historia = argv[1];
		char* frase = argv[2];

		int* vector_resultante = nullptr;
		vector_resultante = buscar_frase(historia, frase);
		imprimir_resultado(vector_resultante);
		delete[]vector_resultante;
		vector_resultante = nullptr;
	}

	else 
		cout << "Debe ingresar tres argumentos" << endl;

	return 0;
}