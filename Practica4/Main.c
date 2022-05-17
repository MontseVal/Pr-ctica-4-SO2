//
// Main.c
// Practica4
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ParallelMatrix.h"

int main(int argc, char** argv)
{
	srand(time(NULL));
	//Variables a utilizar
	int i, j, r, c;
	int *matA = NULL;
	int *matB = NULL;
	int numP, maxHilos, nunHilos;
	
	double no, pa;
	numP = omp_get_num_procs();
	maxThreads = omp_get_max_threads();
	
	
	printf("Num procesadores disponibles \t %d\n Num hilos paralelo disponibles \t %d\n\n", numP, maxHilos);
	
	for(i=1; i<5;i++)
	{
		printf("\n -----Num Hilos %d -------\n);
		
		for(j=0;j<6;j++)
		{
			switch(j)
			{
				case 0:
					printf("mat 10 x 20\n");
					r = 10;
					c = 20;
					matA = (int)malloc(ren*col*sizeof(int));
					matB = (int)malloc(ren*col*sizeof(int));
					break;
				case 1:
					printf("mat 50 x 50\n");
					r = 50;
					c = 50;
					matA = (int)malloc(ren*col*sizeof(int));
					matB = (int)malloc(ren*col*sizeof(int));
					break;
				case 2:
					printf("mat 100 x 200\n");
					r = 100;
					c = 200;
					matA = (int)malloc(ren*col*sizeof(int));
					matB = (int)malloc(ren*col*sizeof(int));
					break;
				case 3:
					printf("mat 100 x 200\n");
					r = 100;
					c = 200;
					matA = (int)malloc(ren*col*sizeof(int));
					matB = (int)malloc(ren*col*sizeof(int));
					break;
				case 4:
					printf("mat 100 x 200\n");
					r = 1200;
					c = 1200;
					matA = (int)malloc(ren*col*sizeof(int));
					matB = (int)malloc(ren*col*sizeof(int));
					break;
	}
	
	
	/*Instrucciones para realizar la simulacion con 1, 2, 3 y 4 hilos disponibles para 4 nucleos.
	

	//Instrucciones para utilizar una cantidad de hilos.	


	//Instruccion para imprimir la cantidad de nucleos disponibles en la computadora
	
	
	//y la cantidad maxima de hilos que se solicitaron.
	
	

	/*Instrucciones para realizar la simulacion con matrices de
	10 x 20
	50 x 50
	200 x 100
	1000 x 1000
	1200 x 1200
	1920 x 1080.
	*/

	//Funcion para inicializar las matrices.

	
	//Funcion para sumar las matrices de forma no paralela y toma de tiempo.


	//Funcion para sumar las matrices de forma paralela y toma de tiempo.


	//Funcion para obtener el valor maximo de forma no paralela y toma de tiempo.


	//Funcion para obtener el valor maximo de forma paralela y toma de tiempo.


	//Impresion de tabla de tiempos de TODA la simulacion.

	return EXIT_SUCCESS;
}
