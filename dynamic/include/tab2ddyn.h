#ifndef TAB2DDYN_H
#define TAB2DDYN_H
#include <stdio.h>
#include <stdlib.h>

//Structure for integer type arrays
typedef struct{
  int** array;
  size_t x;
  size_t y;
} dynArray_i;

//Structure for double type arrays
typedef struct{
  double** array;
  size_t x;
  size_t y;
} dynArray;


//1st set of functions for integer arrays

//Allocate memory for an array of size (x,y) inside a struct pointed to by ptrArray
dynArray_i* createArray_i(dynArray_i* ptrArray, size_t x, size_t y);
//Insert an element in an previously created array at (x,y) position pointed to by ptrArray
void insertElement_i(dynArray_i* ptrArray, int element, size_t pos_x, size_t pos_y);
//Free the array of of pointers pointed to by ptrArray. Also frees the ptrArray
void freeArray_i(dynArray_i* ptrArray);
//Print the contents of the array of int pointed to by ptrArray
void printArray_i(dynArray_i* ptrArray);

//2nd set of functions for double type arrays. Most common set used.

//Allocate memory for an array of size (x,y) inside a struct pointed to by ptrArray
dynArray* createArray(dynArray* ptrArray, size_t x, size_t y);
//Insert an element in an previously created array at (x,y) position pointed to by ptrArray
void insertElement(dynArray* ptrArray, double element, size_t pos_x, size_t pos_y);
//Free the array of of pointers pointed to by ptrArray. Also frees the ptrArray
void freeArray(dynArray* ptrArray);
//Print the contents of the array of double pointed to by ptrArray
void printArray(dynArray* ptrArray);
//Free the couple of pointers contained inside set.
//Exclusively used for freeing LU matrixes.
void freeCouple(dynArray** set);
#endif
