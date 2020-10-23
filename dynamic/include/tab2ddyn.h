#ifndef TAB2DDYN_H
#define TAB2DDYN_H
#include <stdio.h>
#include <stdlib.h>

//Struc for integer type
typedef struct{
  int** array;
  size_t x;
  size_t y;
} dynArray_i;

//struct for double type
typedef struct{
  double** array;
  size_t x;
  size_t y;
} dynArray;



dynArray_i* createArray_i(dynArray_i* ptrArray, size_t x, size_t y);
void insertElement_i(dynArray_i* ptrArray, int element, size_t pos_x, size_t pos_y);
void freeArray_i(dynArray_i* ptrArray);
void printArray_i(dynArray_i* ptrArray);

dynArray* createArray(dynArray* ptrArray, size_t x, size_t y);
void insertElement(dynArray* ptrArray, double element, size_t pos_x, size_t pos_y);
void freeArray(dynArray* ptrArray);
void printArray(dynArray* ptrArray);

void freeCouple(dynArray** set);
#endif
