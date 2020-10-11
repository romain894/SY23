#ifndef MATRICE_H
#define MATRICE_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tab2ddyn.h"


void generateRandomMatrix(int Rows, int Cols);
int pRandom(void);
dynArray_i* ones(size_t x, size_t y);
dynArray_i* zeroes(size_t x, size_t y);
dynArray_i* id(size_t size);
transpose(*ptrArray);
private:
  int Rows, Cols;
#endif
