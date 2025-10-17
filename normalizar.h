#ifndef NORMALIZAR
#define NORMALIZAR
#include "listaAlumnos.h"

//DECLARACION ACCIONES/FUNCIONES QUE SE EXPORTAN:

/*
 * ACCION: inicializar_vector
 * ENTRADA: array -> el array a inicializar
 * 			tam -> tamaño del array
 * 			num -> a que valor se inicializa el array
 * MODIFICA: en todas las posiciones del array se iniciliza su valor al especificado
 */
void inicializar_vector(int *array, int tam, int num);

/*
 * ACCION: calcular_minimos_maximos
 * ENTRADA: lista -> una lista que contiene un solo ejemplo de alumno
 * 			minimo -> un array con los minimos de los atributos
 * 			maximo -> un array con los maximos de los atributos
 * MODIFICA: se alamcena el el array de minimos y maximos los elementos
 * 			 minimos y maximos de cada atributo de la lista de alumnos
 */
void calcular_minimos_maximos(int *lista, int *max, int *min);


/*
 * ACCION: normalizar1
 * ENTRADA: l -> la lista que se va a normalizar
 * 			minimo -> un array con los minimos de los atributos
 * 			maximo -> un array con los maximos de los atributos
 * MODIFICA: se normalizan todos los atributos de la lista de alumnos
 */
void normalizar1(tipoLista* l, int minimo[], int maximo[]);
#endif
