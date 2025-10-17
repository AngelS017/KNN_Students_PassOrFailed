#ifndef KMEANS
#define KMEANS

#include "listaAlumnos.h"
#include "listaOrdenada.h"

//DECLARACION ACCIONES/FUNCIONES QUE SE EXPORTAN:

/*
 * FUNCION: distancia
 * ENTRADA: nuevoDato -> el nuevo dato que se va a procesar en k-means
 * 			ejem_lista -> un ejemplo  de un estudiante de toda la lista
 * 			tam -> tamaño del array de los atributos de 1 estudiante
 * DEVUELVE: 
 */
informacion distancia(estudiante *nuevoDato, estudiante *ejem_lista, int tam);

/*
 * FUNCION: prediccion
 * ENTRADA: nuevoDato -> el nuevo dato que se va a procesar en k-means
 * 			listaOrd -> lista ordenada de menor a mayor que contiene la estructura
 * 						de la lista ordenada(distancia, num ejemplo, clase)
 * 			vecinos -> el numero de vecinos a los que nos tenemos que fijar para clasificar
 * DEVUELVE: la clase a la que pertenece ese ejemplo
 */
int prediccion(tipoLista2 listaOrd, int vecinos);


/*
 * ACCION: wilson
 * ENTRADA: alumnos -> lista de alumnos a la que se aplicara Wilson
 * 			K -> el numero de vecinos a los que nos tenemos que fijar para clasificar
 * MODIFICA: elimina los alumnos cuya prediccion no sea de la clase de dicho
 * 			 alumno, todo para suavizar las fronteras entre clases 
 */
void wilson(tipoLista alumnos, int K);


/*
 * FUNCION: porcentaje_aciertos
 * ENTRADA: clasePredicha -> array con las clases predichas para cada alumno
 * 			alumnosTest -> la lista de alumnos de la cual hemos obtenido
 * 						   las predicciones
 * DEVUELVE: elimina los alumnos cuya prediccion no sea de la clase de dicho
 * 			 alumno, todo para suavizar las fronteras entre clases 
 */
float porcentaje_aciertos(int clasePredicha[], tipoLista alumnosTest);

#endif
