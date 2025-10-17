#ifndef LISTAALUMNOS
#define LISTAALUMNOS
#include <stdbool.h>
#define NUM_ATRIBUTOS 29


//DECLARACION TIPOS DE DATOS:
typedef struct tipoElementoLista{
    int id;
	float atributos[NUM_ATRIBUTOS];
	struct tipoElementoLista *sig;
}estudiante;

typedef struct tipoL{
	estudiante *ini;
	estudiante *fin;
}tipoLista;

//DECLARACION ACCIONES/FUNCIONES QUE SE EXPORTAN:

/*
 * ACCION: nuevaLista
 * ENTRADA: la lista que se va ha generar
 * MODIFICA: se genera una lista desde cero 
 */
void nuevaLista(tipoLista *);


/*
 * ACCION: generarEstudiante
 * ENTRADA: id -> un entero que es el indentificador unico del estudiante
 * 			atributos[] -> un array con todos los atributos del estudiantes
 * 			e -> puntero a la estructura que se creara
 * MODIFICA: se almacena el id y le array de los atributos en la estructura 
 * 			 del estudiante
 */
void generarEstudiante(int id, int atributos[], estudiante *e);


/*
 * ACCION: insertar
 * ENTRADA: la lista que se va ha generar
 * MODIFICA: se añade al final de la lista el nuevo estudiante
 */
void insertar(tipoLista *l, estudiante e);


/*
 * ACCION: eliminar
 * ENTRADA: l -> la lista de estudiantes
 * 			idEliminar -> el id del estudiante 
 * MODIFICA: se elimina el estudiante de la lista
 */
void eliminar(tipoLista *l, int idEliminar);


/*
 * FUNCION: esNulaLista
 * ENTRADA: l -> la lista de estudiantes
 * DEVUELVE: un booleano si esta la lista esta vacia o no
 */
bool esNulaLista(tipoLista l);


/*
 * FUNCION: imprimirLista
 * ENTRADA: l -> la lista de estudiantes
 * DEVUELVE: imprime los estudiantes de la lista con todos sus estudiantes
 */
void imprimirLista (tipoLista l);
#endif
