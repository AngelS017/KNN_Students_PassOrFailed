#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"

void errorOrdenada(char s[]){
    printf("\n\nError en el modulo lista ordenada: %s\n\n",s);
}

void nuevaListaOrdenada(tipoLista2 *l){
    l->ini = NULL;
    l->fin = NULL;
}

void insertarListaOrdenada(tipoLista2 *l, tipoElementoLista e){
    celdaLista *aux;
    aux = (celdaLista*)malloc(sizeof(celdaLista));
    aux->elem = e;
    if(esNulaListaOrdenada(*l)){
        aux->ant = NULL;
        aux->sig = NULL;
        l->ini = aux;
        l->fin = aux;
    }
    else{
        if(e.distancia <= l->ini->elem.distancia){
            l->ini->ant = aux;
            aux->sig = l->ini;
            aux->ant = NULL;
            l->ini = aux;
        }
        else if(e.distancia >= l->fin->elem.distancia){//estan ordenados de menor a mayor 
            l->fin->sig = aux;
            aux->sig = NULL;
            aux->ant = l->fin;
            l->fin = aux;
        }
        else{
            celdaLista *recorre;
            recorre = l->ini;
            while(e.distancia > recorre->elem.distancia) //cuando sale es menor al que "recorre" apunta, y mayor al anterior
                recorre = recorre->sig;
            aux->sig = recorre;
            aux->ant = recorre->ant;
            recorre->ant->sig = aux;
            recorre->ant = aux;
        }
    }
}

void eliminarMenor(tipoLista2 *l){
    if(esNulaListaOrdenada(*l))
        errorOrdenada("no se puede eliminar de una lista vacia");
    else{
        celdaLista *aux;
        aux = l->ini;
        if(l->ini->sig == NULL){
            l->ini = NULL;
            l->fin = NULL;
            free(aux);
        }
        else{
            l->ini = l->ini->sig;
            l->ini->ant = NULL;
            free(aux);
        }
    }
}

void eliminarMayor(tipoLista2 *l){
    if(esNulaListaOrdenada(*l))
        errorOrdenada("no se puede eliminar de una lista vacia");
    else{
        celdaLista *aux;
        aux = l->fin;
        if(l->fin->ant == NULL){
            l->ini = NULL;
            l->fin = NULL;
            free(aux);
        }
        else{
            l->fin = l->fin->ant;
            l->fin->sig = NULL;
            free(aux);
        }
    }
}

tipoElementoLista consultarMenor(tipoLista2 l){
    return l.ini->elem;
}

tipoElementoLista consultarMayor(tipoLista2 l){
    return l.fin->elem;
}

bool estaElemento(tipoLista2 l, tipoElementoLista e){
    celdaLista *aux;
    aux = l.ini;
    while(aux->elem.distancia != e.distancia && aux->sig != NULL)
        aux = aux->sig;
    if(aux->elem.distancia == e.distancia)
        return 1;
    else
        return 0;
}

bool esNulaListaOrdenada(tipoLista2 l){
    return l.ini == NULL;
}

void concatenar (tipoLista2 *l, tipoLista2 *g){
    if(esNulaListaOrdenada(*l)){
        l->ini = g->ini;
        l->fin = g->fin;
    }
    else{
        celdaLista *aux;
        aux = g->ini;
        if(!esNulaListaOrdenada(*g)){
            while(aux->sig != NULL){
                insertarListaOrdenada(l,aux->elem);
                aux = aux->sig;
            }
            insertarListaOrdenada(l,aux->elem);
        }
    }
}

void imprimirListaOrdenada (tipoLista2 l){
    if(esNulaListaOrdenada(l))
        errorOrdenada("no se puede imprimir en una lista vacia");
    else{
        celdaLista *aux;
        aux = l.ini;
        printf("ID\tDIST\tCLASE\n");
        while(aux != NULL){
            printf("%d\t",aux->elem.id);
            printf("%.2f\t",aux->elem.distancia);
            printf("%d\t",aux->elem.clase);
            puts("");
            aux = aux->sig;
        }
    }
    
}


void eliminarListaOrdenada(tipoLista2 *l){
	if(esNulaListaOrdenada(*l))
        errorOrdenada("No se puede eliminar una lista vacia");
    else{
        celdaLista *aux;
        aux = l->ini;
        while(aux != NULL){
			/*
			free(aux->elem.id);
			free(aux->elem.distancia);
			free(aux->elem.clase);
			*/
			free(aux);
            aux = aux->sig;
        }
    }
}
