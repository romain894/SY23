#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tab2ddyn.h"

double pRandom(void){
  return (double)rand()/(double)RAND_MAX  ;
}

dynArray_i* ones(size_t x, size_t y){
  dynArray_i ones;
  dynArray_i* ptrOnes = createArray_i(&ones, x, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      insertElement_i(ptrOnes), 1, i, j);
      printf("%d\t", ptrOnes->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(ptrOnes);

}

dynArray_i* zeroes(size_t x, size_t y){
  dynArray_i zeroes;
  dynArray_i* ptrZeroes = createArray_i(&zeroes, x, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      insertElement_i(ptrZeroes, 1, i, j);
      printf("%d\t", ptrZeroes->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(ptrZeroes);

}

dynArray_i* id(size_t size){
  dynArray_i id;
  dynArray_i* ptrId = createArray_i(&id, size, size);
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      if (i == j){
        insertElement_i(ptrId, 1, i, j);
      }
      else{
        insertElement_i(ptrId, 0, i, j);
      }
      printf("%d\t", ptrId->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(ptrId);

}

dynArray* transpose(dynArray* ptrMat){
  dynArray transposeMat;
  dynArray* ptrTranspose = createArray(&transposeMat, ptrMat->y, ptrMat->x);
  for (int i = 0; i < ptrMat->y; i++){
    for (int j = 0; j < ptrMat->x; j++){
      insertElement(ptrTranspose, ptrMat->array[i][j], j, i);
      printf("%f\t", ptrTranspose->array[i][j]);
    }
    printf("\n");
  }
  return(ptrTranspose);
}

dynArray* generateRandomMatrix(int rows, int column){
  dynArray rdMatrix;
  dynArray* ptrRdMatrix = createArray(&rdMatrix, rows, column);

  for (int i = 0; i < rows; i++){
    for (int j = 0; j < column; j++){
      double tmp = pRandom();
      insertElement(ptrRdMatrix, tmp, i, j);
      printf("%f\t", ptrRdMatrix->array[i][j]);
    }
    printf("\n");
  }
  return(ptrRdMatrix);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  dynArray* randomMat = generateRandomMatrix(2, 5);
  //dynArray_i* mat1 = ones(3,3);
  // dynArray_i* mat2 = zeroes(2,2);
  // dynArray_i* mat3 = id(5);
  transpose(randomMat);
  return 0;
}
