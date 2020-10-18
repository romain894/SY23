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

//Free the array
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
  printf("\n" );
}

//2nd set of functions for double type
//The pointer as a parameter needs an address. Create and allocate memory for an array inside a struct
dynArray* createArray(dynArray* ptrArray, size_t x, size_t y){
  ptrArray->array = (double**)malloc(x*sizeof(double*));
  ptrArray->x = x;
  ptrArray->y = y;
  for (int i = 0; i < x; i++){
    ptrArray->array[i] = (double*)malloc(y*sizeof(double));
  }
  printf("Array completed, matrix %ld x %ld\n", ptrArray->x, ptrArray->y );
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

  for (int i = 0; i < ptrArray->x; i++){
    free(ptrArray->array[i]);
  }
  free(ptrArray->array);
  printf("Array freed.\n");
  free(ptrArray); 
  printf("Pointer freed.\n");
}

void printArray(dynArray* ptrArray){

  for (int i = 0; i < (int)ptrArray->x; i++){
    for (int j = 0; j < (int)ptrArray->y; j++){
      printf("%f\t", ptrArray->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


// int main(int argc, char const *argv[]) {
//   dynArray_i Array;
//   dynArray_i* ptrArray = createArray_i(&Array,50,9);
//   for (int i = 0; i < 5; i++){
//     for (int j = 0; j < 9; j++){
//       insertElement_i(&Array,1,i,j);
//     }
//   }
//   dynArray_i transpose;
//   dynArray_i* ptrTranspose = createArray_i(&transpose, ptrArray->y, ptrArray->x);
//   for (int i = 0; i < ptrArray->x; i++){
//     for (int j = 0; j < ptrArray->y; j++){
//       insertElement_i(ptrTranspose, ptrArray->array[i][j], j ,i);
//     }
//   }
//   printArray_i(&Array);
//   printArray_i(&transpose);
//   freeArray_i(&Array);
//
//   return 0;
// }
