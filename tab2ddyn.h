#ifndef TAB2DDYN_H
#define TAB2DDYN_H
#include <stdio.h>
#include <stdlib.h>
#include "tab2ddyn.h"

typedef struct{
  int** array;
  size_t x;
  size_t y;
} dynArray_i;


typedef struct{
  double** array;
  size_t x;
  size_t y;
} dynArray;



dynArray_i* createArray_i(dynArray_i* ptrArray, size_t x, size_t y);
void insertArray_i(dynArray_i* ptrArray, int element, size_t pos_x, size_t pos_y);
void freeArray_i(dynArray_i* ptrArray);
void printArray_i(dynArray_i* ptrArray);

dynArray* createArray(dynArray* ptrArray, size_t x, size_t y);
void insertArray(dynArray* ptrArray, double element, size_t pos_x, size_t pos_y);
void freeArray(dynArray* ptrArray);
void printArray(dynArray* ptrArray);

#endif
