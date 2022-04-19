#include <iostream>
#include "historia.h"

using namespace std;

void copiar_vector(int coincidencias, int * aux, int* &arreglo){

	for(int i =0; i < coincidencias; i++){
		aux[i] = arreglo[i];
		cout << aux[i] << " " << arreglo[i] << endl;
	}

	delete[]arreglo;
	arreglo = aux;
}

void almacenar_coincidencia(int &coincidencias, int* &arreglo, int posicion){

	if(coincidencias == 0){
		coincidencias++;
		arreglo = new int[coincidencias];
		arreglo[0] = posicion;
	}

	else{
		int* aux = nullptr;
		aux = new int[coincidencias + 1];
		copiar_vector(coincidencias, aux, arreglo);
		aux[coincidencias] = posicion;
		coincidencias++;
	}
}

int* buscar_frase(char historia[], char frase[]){

	int tamanio_historia = (int)((string) historia).size();
	int tamanio_frase = (int)((string) frase).size();
	int ultima_frase = tamanio_historia - tamanio_frase;
	int* arreglo = nullptr;

	if(tamanio_historia < tamanio_frase){
		cout << "Frase mayor que la historia, por lo tanto" << endl;
		return nullptr;
	}

	int j = 0, i = 0;
	int caracter_validado = 0, posicion = 0, coincidencias = 0;

	while(historia[i] != '\0'){
		//cout << historia[i] << frase[j] << endl;
		if(((char)tolower(historia[i])) == ((char)tolower(frase[j]))){ 
			caracter_validado++;
			j++;

            if(tamanio_frase == caracter_validado){
				posicion = (i - j) + 1;
				almacenar_coincidencia(coincidencias, arreglo, posicion);
				j = 0;
				caracter_validado = 0;
			}
		}
		else{
			j=0;
			caracter_validado = 0;
		}
		i++;
		if( (i >= ultima_frase) && (caracter_validado == 0) && ((char)tolower(historia[i])) != ((char)tolower(frase[j]))){
			historia[i] = '\0';
		}
	}

    if(coincidencias > 0){
        posicion = -1;
        almacenar_coincidencia(coincidencias, arreglo, posicion);
    }
	
	return arreglo;
}

void imprimir_resultado(int *posiciones){

    if(posiciones == nullptr){

        cout << "No se encuentra esa frase en la historia indicada." << endl;
    }

    else{

        int i = 0;
        int ultimo_elemento = -1;

        while(posiciones[i] != ultimo_elemento){
            cout << posiciones[i] << "-";
            i++;
        }
        cout << endl;
    }
}
