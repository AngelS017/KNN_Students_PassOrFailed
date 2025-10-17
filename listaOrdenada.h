#ifndef LISTAALUMNOSORD
#define LISTAALUMNOSORD
#include <stdbool.h>

typedef struct info
{
    int clase;
    float distancia;
    int id;
}informacion;

typedef informacion tipoElementoLista;

 typedef struct celdaL{
	 tipoElementoLista elem;
	 struct celdaL *sig;
	 struct celdaL *ant;
 }celdaLista; 
 
typedef struct tipoListaOrd{
	celdaLista *ini;
	celdaLista *fin;
}tipoLista2;


/*
 * ACCION: nuevaListaOrdenada
 * ENTRADA: l -> la lista ordenada de distancias
 * MODIFICA: se inicializa la lista ordenada
 */
void nuevaListaOrdenada(tipoLista2 *l);

/*
 * ACCION: insertarListaOrdenada
 * ENTRADA: l -> la lista ordenada de distancias
 * 			e -> el nuevo elemento a introducir
 * MODIFICA: añade a la lista ordenada el nuevo elemento ordenado dependiendo
 * 			 de la distancia de e
 */
void insertarListaOrdenada(tipoLista2 *l, tipoElementoLista e);

/*
 * ACCION: eliminarMenor
 * ENTRADA: l -> la lista ordenada de distancias
 * MODIFICA: elimina el menor elemento de la lista ordenada
 */
void eliminarMenor(tipoLista2 *l);

/*
 * ACCION: eliminarMayor
 * ENTRADA: l -> la lista ordenada de distancias
 * MODIFICA: elimina el mayor elemento de la lista ordenada
 */
void eliminarMayor(tipoLista2 *l);

/*
 * FUNCION: consultarMenor
 * ENTRADA: l -> la lista ordenada de distancias
 * DEVUELVE: el menor elemento de la lista ordenada
 */
tipoElementoLista consultarMenor(tipoLista2 l);

/*
 * FUNCION: consultarMayor
 * ENTRADA: l -> la lista ordenada de distancias
 * DEVUELVE: el mayor elemento de la lista ordenada
 */
tipoElementoLista consultarMayor(tipoLista2 l);

/*
 * FUNCION: estaElemento
 * ENTRADA: l -> la lista ordenada de distancias
 * 			e -> el elemento ha comprobar si esta en la lista
 * DEVUELVE: true o false dependiendo si el elemento esta ya en la lista,
 * 			 para que un elemento este tienen que coincidir todos sus
 * 			 atributos
 */
bool estaElemento(tipoLista2 l, tipoElementoLista e);

/*
 * FUNCION: esNulaListaOrdenada
 * ENTRADA: l -> la lista ordenada de distancias
 * DEVUELVE: true si la lista esta vacia
 */
bool esNulaListaOrdenada(tipoLista2 l);

/*
 * ACCION: concatenar
 * ENTRADA: l -> la lista ordenada de distancias
 * 			g -> lista ordenada de distancias
 * MODIFICA: almacena en l los elementos de g
 */
void concatenar (tipoLista2 *l, tipoLista2 *g);

/*
 * ACCION: imprimirListaOrdenada
 * ENTRADA: l -> la lista ordenada de distancias
 * MODIFICA: imprime por pantalla tods los elemento (con todos sus atributos)
 * 			 de la lista ordenada
 */
void imprimirListaOrdenada (tipoLista2 l);

/*
 * ACCION: eliminarListaOrdenada
 * ENTRADA: l -> la lista ordenada de distancias
 * MODIFICA: elimina todos los elementos que contiene la lista ordenada
 */
void eliminarListaOrdenada(tipoLista2 *l);

#endif

