//
// ParallelMatrix.h
// Practica4
//
//

#pragma once

#ifndef ParallelMatrix_h
#define ParallelMatrix_h

#include <unistd.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void llenamat(int*, int, int);
double sumapar(int*, int*, int, int, int);
double maxpar(int*, int, int, int);
double sumano(int*, int*, int, int);
double maxno(int*, int, int);

//Prototipos de funciones





#endif
