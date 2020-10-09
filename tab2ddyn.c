#include <stdio.h>
#include <stdlib.h>
#include "tab2ddyn.h"

//1st set of functions for integer matrixes
//The pointer as a parameter needs an address.
dynArray_i* createArray_i(dynArray_i* ptrArray, size_t x, size_t y){
  ptrArray->array = (int**)malloc(x*sizeof(int));
  ptrArray->x = x;
  ptrArray->y = y;
  for (int i = 0; i < x; i++){
    ptrArray->array[i] = (int*)malloc(y*sizeof(int));
  }
  printf("Array completed, matrix %ld x %ld\n", ptrArray->x, ptrArray->y );
  return (ptrArray);
}

//Arrays start at index 0.
void insertArray_i(dynArray_i* ptrArray, int element, size_t pos_x, size_t pos_y){
  if (pos_x > ptrArray->x || pos_y > ptrArray->y){
    printf("Out of range.\n");
  }
  else{
    ptrArray->array[pos_x][pos_y] = element;
  }
}

void freeArray_i(dynArray_i* ptrArray){

  for (int i = 0; i < ptrArray->x; i++){
    printf("Freeing memory...\n");
    free(ptrArray->array[i]);
  }
  free(ptrArray->array);
  printf("Memory freed.\n");
}

void printArray_i(dynArray_i* ptrArray){
  for (int i = 0; i < ptrArray->x; i++){
    for (int j = 0; j < ptrArray->y; j++){
      printf("%d\t", ptrArray->array[i][j]);
    }
    printf("\n");
  }
}

//2nd set of functions for non defined types
//The pointer as a parameter needs an address.
dynArray* createArray(dynArray* ptrArray, size_t x, size_t y){
  ptrArray->array = (double**)malloc(x*sizeof(double));
  ptrArray->x = x;
  ptrArray->y = y;
  for (int i = 0; i < x; i++){
    ptrArray->array[i] = (double*)malloc(y*sizeof(double));
  }
  printf("Array completed, matrix %ld x %ld\n", ptrArray->x, ptrArray->y );
  return (ptrArray);
}

//Arrays start at index 0.
void insertArray(dynArray* ptrArray, double element, size_t pos_x, size_t pos_y){
  if (pos_x > ptrArray->x || pos_y > ptrArray->y){
    printf("Out of range.\n");
  }
  else{
    ptrArray->array[pos_x][pos_y] = element;
  }
}

void freeArray(dynArray* ptrArray){

  for (int i = 0; i < ptrArray->x; i++){

    free(ptrArray->array[i]);
  }
  free(ptrArray->array);
  printf("Memory freed.\n");
}

void printArray(dynArray* ptrArray){
  for (int i = 0; i < ptrArray->x; i++){
    for (int j = 0; j < ptrArray->y; j++){
      printf("%f\t", ptrArray->array[i][j]);
    }
    printf("\n");
  }
}

//
// int main(int argc, char const *argv[]) {
//   dynArray_i ptrArray;
//   createArray_i(&ptrArray,2,2);
//   insertArray_i(&ptrArray,1,0,0);
//   insertArray_i(&ptrArray,2,0,1);
//   insertArray_i(&ptrArray,3,1,0);
//   insertArray_i(&ptrArray,4,1,1);
//
//   printArray_i(&ptrArray);
//
//   freeArray_i(&ptrArray);
//
//   return 0;
// }
