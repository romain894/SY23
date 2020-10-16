#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tab2ddyn.h"
//never return a pointer to a local variable!
double pRandom(void){
  return (double)rand()/(double)RAND_MAX  ;
}

dynArray_i* ones(size_t x, size_t y){
  dynArray_i* ones = malloc(sizeof(dynArray_i*));
  ones = createArray_i(ones, x, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      insertElement_i(ones, 1, i, j);
      printf("%d\t", ones->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(ones);

}

dynArray_i* zeroes(size_t x, size_t y){
  dynArray_i* zeroes = malloc(sizeof(dynArray_i*));
  zeroes = createArray_i(zeroes, x, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      insertElement_i(zeroes, 0, i, j);
      printf("%d\t", zeroes->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(zeroes);

}

dynArray_i* id(size_t size){
  dynArray_i* id = malloc(sizeof(dynArray_i*));
  id = createArray_i(id, size, size);
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      if (i == j){
        insertElement_i(id, 1, i, j);
      }
      else{
        insertElement_i(id, 0, i, j);
      }
      printf("%d\t", id->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(id);
}

dynArray* generateRandomMatrix(dynArray* ptrRdMatrix, int rows, int column){
  ptrRdMatrix = createArray(ptrRdMatrix, rows, column);
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < column; j++){
      double tmp = pRandom();
      insertElement(ptrRdMatrix, tmp, i, j);
    }
  }
  return(ptrRdMatrix);
}

dynArray* transpose(dynArray* mat){
  dynArray* transposeMat = malloc(sizeof(dynArray*));
  transposeMat = createArray(transposeMat, mat->y, mat->x);
  for (int i = 0; i < mat->x; i++){
    for (int j = 0; j < mat->y; j++){
      insertElement(transposeMat, mat->array[i][j], j, i);
    }
  }
  return(transposeMat);
}

dynArray* addMatrix(dynArray* mat1, dynArray* mat2){
  dynArray* result = malloc(sizeof(dynArray*));
  result = createArray(result, mat1->x, mat1->y);
  for (int i = 0; i < mat1->x; i++){
    for (int j = 0; j < mat1->y; j++){
      insertElement(result, mat1->array[i][j] + mat2->array[i][j], i, j);
      printf("%f\t", result->array[i][j] );
    }
    printf("\n" );
  }
  return result;
}

dynArray* subMatrix(dynArray* mat1, dynArray* mat2){
  dynArray* result = malloc(sizeof(dynArray*));
  result = createArray(result, mat1->x, mat1->y);
  for (int i = 0; i < mat1->x; i++){
    for (int j = 0; j < mat1->y; j++){
      insertElement(result, mat1->array[i][j] - mat2->array[i][j], i, j);
      printf("%f\t", result->array[i][j] );
    }
    printf("\n" );
  }
  return result;
}

dynArray* multiplyMatrix(dynArray* mat1, dynArray* mat2){
  dynArray* result = malloc(sizeof(dynArray*));
  result = createArray(result, mat1->x, mat2->y);
  double tmp = 0;
  for (int i = 0; i < mat1->x; i++){
    for (int j = 0; j < mat2->y; j++){
      for (int k = 0; k < mat2->x; k++){
        tmp += mat1->array[i][k] * mat2->array[k][j];
      }
      insertElement(result, tmp, i, j);
      tmp = 0;
      printf("%f\t", result->array[i][j]);
    }
    printf("\n");
  }
  return result;
}

int main(int argc, char const *argv[]) {
  //srand(time(NULL));
  dynArray rdMatrix;
  dynArray* ptrRdMat = generateRandomMatrix(&rdMatrix, 20, 2);
  printf("\n");
  printArray(ptrRdMat);
  // dynArray_i* mat1 = ones(8, 3);
  // printf("\n");
  // dynArray_i* mat2 = zeroes(6,9);
  // dynArray_i* mat3 = id(10);
  // printf("\n");
  dynArray* transMat = transpose(ptrRdMat);
  printArray(transMat);
  printf("\n");
  // addMatrix(transMat, ptrRdMat);
  // printf("\n" );
  multiplyMatrix(transMat, ptrRdMat);
  return 0;
}
