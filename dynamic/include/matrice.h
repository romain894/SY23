#ifndef MATRICE_H
#define MATRICE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tab2ddyn.h"
#include "matrice.h"

dynArray* generateRandomMatrix(dynArray* ptrRdMatrix, int rows, int column);
double pRandom(void);
dynArray* ones(size_t x, size_t y);
dynArray* zeroes(size_t x, size_t y);
dynArray* id(size_t size);
dynArray* addMatrix(dynArray* mat1, dynArray* mat2);
dynArray* transpose(dynArray* mat);
dynArray* multiplyMatrix(dynArray* mat1, dynArray* mat2);
dynArray* subMatrix(dynArray* mat1, dynArray* mat2);
dynArray** decompositionLU(dynArray* mat);
#endif
