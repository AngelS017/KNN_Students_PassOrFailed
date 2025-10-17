#include <stdio.h>
#include <stdbool.h>
#include "normalizar.h"

//IMPLEMENTACION ACCIONES/FUNCIONES IMPLICITAS:

void dif_max_minimo(int dif[], int minimo[], int maximo[])
{
    for(int i = 0; i < NUM_ATRIBUTOS-1; i++)
        dif[i] = maximo[i] - minimo[i];
}

//IMPLEMENTACION ACCIONES/FUNCIONES EXPORTADAS:

void inicializar_vector(int *array, int tam, int num){
	for(int i = 0; i < tam; i++){
		array[i] = num;
	}
}


void calcular_minimos_maximos(int *tar, int *max, int *min){
    for(int i = 0; i < NUM_ATRIBUTOS-1; i++){
        if(tar[i] > max[i]){
			max[i] = tar[i];
		} 
        if(tar[i] < min[i]){
			min[i] = tar[i];
		} 
    }
}


void normalizar1(tipoLista* l, int minimo[], int maximo[])
{
    int dif[NUM_ATRIBUTOS-1];
    dif_max_minimo(dif, minimo, maximo);
    estudiante* buscar;
    buscar = l->ini;
    
    while(buscar != NULL){
		for(int i = 0; i < NUM_ATRIBUTOS-1; i++){
			buscar -> atributos[i] = (buscar -> atributos[i] - minimo[i]) / dif[i];
		}
		buscar = buscar -> sig;
	}
	
}

