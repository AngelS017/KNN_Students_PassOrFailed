#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "normalizar.h"
#include "kmeans.h"
#include "listaOrdenada.h"

//Declaracion constantes:
#define FILETRAIN "Train.csv"
#define FILETEST "Test.csv"
#define MAXREAD 1000

int main(void){
	char input[MAXREAD];
	char *linea, *fragmento;
	int arrayAux[NUM_ATRIBUTOS];
	int posAux;

	tipoLista listaAlumnos;
	tipoLista listaAlumnos_test;
	int id = 0;
	int id_test = 0;

	int minimos[NUM_ATRIBUTOS-1];
	int maximos[NUM_ATRIBUTOS-1];

	estudiante estudianteAux_Test;

	int K = 1;
	//Abrimos el archivo .csv
	FILE *fConstruir = fopen(FILETRAIN, "r");
	FILE *fTest = fopen(FILETEST, "r");

	//Recorremos el fichero Train.csv:
	if(fConstruir != NULL){
		//Inicilizamos la lista de alumnos
		nuevaLista(&listaAlumnos);
		nuevaLista(&listaAlumnos_test);

		//Inicilizamos el vector de minimos y maximos:
		inicializar_vector(minimos, NUM_ATRIBUTOS-1, 1000);
		inicializar_vector(maximos, NUM_ATRIBUTOS-1, 0);

		//Leemos la 1ª linea que es la cabecera del fichero:
		fgets(input, MAXREAD, fConstruir);

		while((linea = fgets(input, MAXREAD, fConstruir)) != NULL){
			//Dividimos la linea que hemos leido por ; que separan cada
			//atributo del .csv:
			fragmento = strtok(linea, ",");

			//Inicializamos variable estudiante
			estudiante estudianteAux;
			posAux = 0;

			while(fragmento != NULL){
				//Metemos cada atributo en el array auxiliar
				arrayAux[posAux] = atoi(fragmento);
				//Separamos por NULL para "reiniciar" la var fragmento:
				fragmento = strtok(NULL, ",");
				//Aumentamos el valor de la posicion del atributo:
				posAux += 1;
			}
			//Almacenamos el nuevo estudiante en la lista de alumnos
			generarEstudiante(id, arrayAux, &estudianteAux);
			insertar(&listaAlumnos, estudianteAux);
			//Calculamos posibles minimos y maximos para el estudiante
			calcular_minimos_maximos(arrayAux, maximos, minimos);
			id += 1;
		}

		//Normalizar:
		normalizar1(&listaAlumnos, minimos, maximos);

		
		//TEST
		if(fTest != NULL){
			fgets(input, MAXREAD, fTest);

			while((linea = fgets(input, MAXREAD, fTest)) != NULL){
				//Dividimos la linea que hemos leido por ; que separan cada
				//atributo del .csv:
				fragmento = strtok(linea, ",");
				//Inicializamos variable estudiante

				posAux = 0;
				while(fragmento != NULL){
					//Metemos cada atributo en el array auxiliar
					arrayAux[posAux] = atoi(fragmento);
					//Separamos por NULL para "reiniciar" la var fragmento:
					fragmento = strtok(NULL, ",");
					//Aumentamos el valor de la posicion del atributo:
					posAux += 1;
				}

				//Almacenamos el nuevo estudiante en la lista de alumnos
				generarEstudiante(id_test, arrayAux, &estudianteAux_Test);
				insertar(&listaAlumnos_test, estudianteAux_Test);
				id_test += 1;
			}
			normalizar1(&listaAlumnos_test, minimos, maximos);
			
			//imprimirLista(listaAlumnos_test);
			
			int predicciones[100];
			estudiante *estTest = listaAlumnos_test.ini;
			int i = 0;
	        while(estTest != NULL){
				tipoLista2 listaOrd;
				nuevaListaOrdenada(&listaOrd);
				estudiante *auxTrain = listaAlumnos.ini;
				while(auxTrain !=NULL){
					informacion inf = distancia(estTest,auxTrain,NUM_ATRIBUTOS-1);
					insertarListaOrdenada(&listaOrd, inf);
					auxTrain = auxTrain->sig;
				}
				estTest = estTest->sig;
				
				predicciones[i] = prediccion(listaOrd, K);
				printf("La prediccion del ejemplo %d del test es: %d\n", i, predicciones[i]);
				
				eliminarListaOrdenada(&listaOrd);
				i++;

			}
			//comparar predicciones[i] con la ultima posicion de los estudiantes y hacer el conteo de cuantos hemos acertado
			//con eso sacar la prediccion
			float acietos = porcentaje_aciertos(predicciones, listaAlumnos_test);
			printf("\nHemos acertado %f%% ejemplos\n", acietos*100);
			//imprimirLista(listaAlumnos);
			wilson(listaAlumnos, K);
			puts("\tDESPUES DE WILSON");
			//imprimirLista(listaAlumnos);
			
			
			int predicciones2[100];
			estudiante *estTest2 = listaAlumnos_test.ini;
			int x = 0;
	        while(estTest2 != NULL){
				tipoLista2 listaOrd2;
				nuevaListaOrdenada(&listaOrd2);
				estudiante *auxTrain2 = listaAlumnos.ini;
				while(auxTrain2 !=NULL){
					informacion inf = distancia(estTest2,auxTrain2,NUM_ATRIBUTOS-1);
					insertarListaOrdenada(&listaOrd2, inf);
					auxTrain2 = auxTrain2->sig;
				}
				estTest2 = estTest2->sig;
				
				predicciones2[x] = prediccion(listaOrd2, K);
				printf("La prediccion del ejemplo %d del test es: %d\n", x, predicciones2[x]);
				
				eliminarListaOrdenada(&listaOrd2);
				x++;

			}
			float acietos2 = porcentaje_aciertos(predicciones2, listaAlumnos_test);
			printf("\nHemos acertado %f%% ejemplos\n", acietos2*100);
			
		}
		else{
			printf("Error al abrir el archivo de los datos TEST\n");
		}

		//Se cierran los ficheros
		fclose(fConstruir);
		fclose(fTest);
	}
	else{
		printf("Error al abrir el archivo de los datos TRAIN\n");
	}
}
