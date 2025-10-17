#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "kmeans.h"
#include <stdlib.h>
//#include "listaOrdenada.h"

//IMPLEMENTACION ACCIONES/FUNCIONES EXPORTADAS:

informacion distancia(estudiante *nuevoDato, estudiante *ejem_lista, int tam){
	float dist_atributos = 0;
	//Datos que iran en la estructura
	float distancia;
	int ejemplo;
	int clase;
	
	for(int i = 0; i < tam; i++){
		dist_atributos += pow(((*ejem_lista).atributos[i] - (*nuevoDato).atributos[i]), 2);
	}
	distancia = sqrt(dist_atributos);
	ejemplo = (*ejem_lista).id;
	clase = (*ejem_lista).atributos[NUM_ATRIBUTOS-1];
	informacion *nuevaInfo = (informacion*) malloc(sizeof(informacion));
	nuevaInfo->distancia = distancia;
	nuevaInfo->id = ejemplo;
	nuevaInfo->clase = clase;
	return *nuevaInfo;
}


int prediccion(tipoLista2 listaOrd, int vecinos){
	int clase_resultado;
	int suma_clases = 0;
	celdaLista *aux;
	
	aux = listaOrd.ini;
	
	for(int i = 0; i < vecinos; i++){
			suma_clases += aux->elem.clase;
			aux = aux->sig;
	}
	//printf("\t\tLa suma de las clases de los %d vecinos:  %d \n", vecinos, suma_clases);
	//Si la suma es mayor que la mitad de los vecino, es clase 1
	if(suma_clases > (int)(vecinos/2)){
		clase_resultado = 1;
	}
	//Si es menor a igual es clase 0
	else if(suma_clases < (int)(vecinos/2)){
		clase_resultado = 0;
	}
	//Si hay empate, nos quedamos con la clase de la minima distancia
	else{
		clase_resultado = listaOrd.ini->elem.clase;
	}
	return clase_resultado;
}


void wilson(tipoLista alumnos, int K){
    estudiante *aux, *aux2;
    aux = alumnos.ini;
    aux2 = alumnos.ini;
    tipoLista2 listaOrd;
    int cont = 0;
				
    while(aux != NULL){
		nuevaListaOrdenada(&listaOrd);
		while(aux2 != NULL){
			if(aux->id!=aux2->id){
				informacion inf = distancia(aux,aux2,NUM_ATRIBUTOS-1);
				insertarListaOrdenada(&listaOrd, inf);			
			
			}
			aux2 = aux2->sig;
			
		}
		int pred = prediccion(listaOrd, K);
		eliminarListaOrdenada(&listaOrd);
		if(pred != aux->atributos[NUM_ATRIBUTOS-1]){
			eliminar(&alumnos, aux->id);
			cont++;
			}
		aux = aux->sig;
		aux2 = alumnos.ini;
      /*  if(aux->atributos[NUM_ATRIBUTOS-1] != prediccion[aux->id])
            eliminar(&alumnos,aux->id);
        aux = aux->sig;*/
    }
    printf("contador: %d\n",cont);
}

float porcentaje_aciertos(int clasePredicha[], tipoLista alumnosTest){
	estudiante *aux = alumnosTest.ini;
	int i = 0;
	float aciertos = 0;
	
	while(aux != NULL){
		if(clasePredicha[i] == aux->atributos[NUM_ATRIBUTOS-1]){
			aciertos += 1;
		}
		aux = aux->sig;
		i += 1;
	}
	aciertos = aciertos/i;
	return aciertos;
}
