#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaAlumnos.h"

//IMPLEMENTACION ACCIONES/FUNCIONES IMPLICITAS:

void error(char s[]){
    printf("\n\nError en el modulo lista ordenada: %s\n\n",s);
}

void nuevaLista(tipoLista *l){
    l->ini = NULL;
    l->fin = NULL;
}

//IMPLEMENTACION ACCIONES/FUNCIONES EXPORTADAS:

void generarEstudiante(int id, int atributos[], estudiante *e){
    (*e).id = id;
    for (int i = 0; i< NUM_ATRIBUTOS; i++){
		(*e).atributos[i] = atributos[i];
    }
    (*e).sig = NULL;
}


/**
se inserta al final de la lista el nuevo elemento estudiante
*/
void insertar(tipoLista *l, estudiante e){
    estudiante *aux;
    aux = (estudiante*)malloc(sizeof(estudiante));
    aux->id = e.id;
    memcpy(aux->atributos, e.atributos, NUM_ATRIBUTOS * sizeof(int));
    aux->sig = NULL;
    
    if(esNulaLista(*l)){
        l->ini = aux;
        l->fin = aux;
    }
    else{
		l->fin->sig = aux;
		l->fin = aux;
    }
}


void eliminar(tipoLista *l, int idEliminar){
    if(esNulaLista(*l))
        error("no se puede eliminar de una lista vacia");
    else{
        estudiante *aux, *auxAnt;
        aux =  (*l).ini;
        if((*l).ini == (*l).fin && aux->id == idEliminar){
                (*l).ini = NULL;
                (*l).fin = NULL;
                free(aux);
        }
        else if(aux->id == idEliminar){
            (*l).ini = aux->sig;
            free(aux);
        }
        else{
            while(aux->sig != NULL && aux->id != idEliminar){
                auxAnt = aux;
                aux = aux->sig;
            }
            if(aux == (*l).fin && aux->id == idEliminar){
                (*l).fin = auxAnt;
                auxAnt->sig = NULL;
                auxAnt = NULL;
                free(aux);
            }
            else if(aux->id == idEliminar){
                auxAnt->sig = aux->sig;
                free(aux);
            }
        }
    }
}

bool esNulaLista(tipoLista l){
    return l.ini == NULL;
}

void imprimirLista (tipoLista l){
    if(esNulaLista(l))
        error("no se puede imprimir en una lista vacia");
    else{
        estudiante *aux;
        aux = l.ini;
        while(aux != NULL){
            printf("Estudiante: %d \t", aux->id);
            for (int i = 0; i< NUM_ATRIBUTOS; i++){
                printf(" %f ", aux->atributos[i]);
            }
            puts("");
            aux = aux->sig;
        }
    }
}
