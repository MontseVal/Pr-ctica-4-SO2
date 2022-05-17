//
// ParallelMatrix.c
// Practica4
//
//

#include "ParallelMatrix.h"

//Definicion de funciones
void llenamat(int* mat, int r, int c)
{
	int i, j;
	for(i = 0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			*(mat + i * c + j) = rand()%255;
		}
	}
}

double sumano(int* matA, int* matB, int r, int c)
{
	struct timespec ini, fin;
	double TiempoRes;

	int i, j, *matRes=NULL;

	if(clock_gettime(CLOCK_REALTIME, &ini) != 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	
	matRes=(int*)malloc(r*c*sizeof(int));
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			*(matRes + i * c + j) = *(matA + i * c + j)+ *(matB + i *c + j);
		}
	}
	if(clock_gettime(CLOCK_REALTIME, &fin) != 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	tiempoRes = (double)(fin.tv_sec - ini.tv_sec) + ((double)(fin.tv_nsec - ini.tv_nsec)/1000000000L);
	return tiempoRes;
}

double maxno(int* mat, int r, int c)
{
	struct timespec ini, fin;
	double TiempoRes;

	int i, j, max=0;

	if(clock_gettime(CLOCK_REALTIME, &ini) != 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			if(*(mat + i * c + j)>max) max = *(mat + i * c + j));
		}
	}
	if(clock_gettime(CLOCK_REALTIME, &fin) != 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	tiempoRes = (double)(fin.tv_sec - ini.tv_sec) + (double)(fin.tv_nsec - ini.tv_nsec)/1000000000L);
	return tiempoRes;
}

double sumapar(int* matA, int* matB, int r, int c, int hilos)
{
	struct timespec ini, fin;
	double TiempoRes;

	int i, j, *matRes=NULL;
	matRes = (int*)malloc(r * c * sizeof(int));
	omp_set_num_threads(hilos);

	if(clock_gettime(CLOCK_REALTIME, &ini) != 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	
	#pragma omp parallel for private(c)
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			*(matRes + i * c + j) = *(matA + i * c + j)+ *(matB + i *c + j);
		}
	}
	if(clock_gettime(CLOCK_REALTIME, &fin) != 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	tiempoRes = (double)(fin.tv_sec - ini.tv_sec) + ((double)(fin.tv_nsec - ini.tv_nsec)/1000000000L);
	return tiempoRes;
}

double maxpar(int* mat, int r, int c, int hilos)
{
	struct timespec ini, fin;
	double TiempoRes;

	int i, j, max=0;
	omp_set_num_threads(hilos);

	if(clock_gettime(CLOCK_REALTIME, &ini) != 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	
	#pragma omp parallel for private(c)
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			if(*(mat + i * c + j)>max) max = *(matA + i * c + j));
		}
	}
	if(clock_gettime(CLOCK_REALTIME, &fin) != 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	tiempoRes = (double)(fin.tv_sec - ini.tv_sec) + ((double)(fin.tv_nsec - ini.tv_nsec)/1000000000L);
	return tiempoRes;
}
