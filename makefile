all: normalizar kmeans listaAlumnos listaOrdenada estudiantes
estudiantes: estudiantes.c normalizar.o kmeans.o listaAlumnos.o listaOrdenada.o
	gcc estudiantes.c normalizar.o kmeans.o listaAlumnos.o listaOrdenada.o -o estudiantes -Wall -lm -g
normalizar: normalizar.c
	gcc -c normalizar.c -g
kmeans: kmeans.c
	gcc -c kmeans.c -lm -g
listaAlumnos: listaAlumnos.c
	gcc -c listaAlumnos.c -g
listaOrdenada: listaOrdenada.c
	gcc -c listaOrdenada.c -g
