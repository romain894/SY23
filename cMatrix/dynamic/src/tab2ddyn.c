#include <stdio.h>
#include <stdlib.h>
#include "../include/tab2ddyn.h"

//1st set of functions for integer matrixes
//The pointer as a parameter needs an address.
dynArray_i* createArray_i(dynArray_i* ptrArray, size_t x, size_t y){
  ptrArray->array = (int**)malloc(x*sizeof(int*));
  ptrArray->x = x;
  ptrArray->y = y;
  for (int i = 0; i < x; i++){
    ptrArray->array[i] = (int*)malloc(y*sizeof(int));
  }
  printf("Array completed, matrix %ld x %ld\n", ptrArray->x, ptrArray->y );
  return (ptrArray);
}

//Arrays start at index 0. Insert an element in an previously created array at x,y position
void insertElement_i(dynArray_i* ptrArray, int element, size_t pos_x, size_t pos_y){
  if (pos_x >= ptrArray->x || pos_y >= ptrArray->y){
    printf("Out of range.\n");
  }
  else{
    ptrArray->array[pos_x][pos_y] = element;
  }
}

//Free the array of of pointers pointed to by ptrArray. Also frees the ptrArray
void freeArray_i(dynArray_i* ptrArray){

  for (int i = 0; i < ptrArray->x; i++){
    printf("Freeing memory...\n");
    free(ptrArray->array[i]);
  }
  free(ptrArray->array);
  printf("Memory freed.\n");
}

//Print the contents of the array of int pointed to by ptrArray
void printArray_i(dynArray_i* ptrArray){
  for (int i = 0; i < ptrArray->x; i++){
    for (int j = 0; j < ptrArray->y; j++){
      printf("%d\t", ptrArray->array[i][j]);
    }
    printf("\n");
  }
  printf("\n" );
}

//2nd set of functions for double type
//Allocate memory for an array of size (x,y) inside a struct pointed to by ptrArray
dynArray* createArray(dynArray* ptrArray, size_t x, size_t y){
  ptrArray->array = (double**)malloc(x * sizeof(double*));
  ptrArray->x = x;
  ptrArray->y = y;
  for (int i = 0; i < x; i++){
    ptrArray->array[i] = (double*)malloc(y * sizeof(double));
  }
  //printf("Array completed, matrix %ld x %ld\n", ptrArray->x, ptrArray->y );
  return (ptrArray);
}

//Arrays start at index 0. Insert an element in an previously created array at x,y position
void insertElement(dynArray* ptrArray, double element, size_t pos_x, size_t pos_y){
  if (pos_x >= ptrArray->x || pos_y >= ptrArray->y){
    printf("Out of range.\n");
  }
  else{
    ptrArray->array[pos_x][pos_y] = element;
  }
}

//Free the array inside the struct, then frees the pointer to the struct
void freeArray(dynArray* ptrArray){
  //Free the pointer to the vector of doubles
  for (int i = 0; i < ptrArray->x; i++){
    free(ptrArray->array[i]);
  }
  //free the double pointer
  free(ptrArray->array);
  printf("Array freed.\n");
  //Free the pointer to the struct
  free(ptrArray);
  printf("Pointer freed.\n");
}

//Free the couple of pointers, specifically used for LU sets.
void freeCouple(dynArray** set){
  freeArray(*set);
  freeArray(*(set+1));
  free(set);
}

//Print the contents of the array of doubles pointed to by ptrArray
void printArray(dynArray* ptrArray){
  for (int i = 0; i < (int)ptrArray->x; i++){
    for (int j = 0; j < (int)ptrArray->y; j++){
      printf("%f\t", ptrArray->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
