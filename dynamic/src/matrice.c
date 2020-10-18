#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/tab2ddyn.h"
#include "../include/matrice.h"

//never return a pointer to a local variable!
double pRandom(void){
  return (double)rand()/(double)RAND_MAX  ;
}

dynArray* ones(size_t x, size_t y){
  dynArray* ones = malloc(sizeof(dynArray_i*));
  ones = createArray(ones, x, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      insertElement(ones, 1, i, j);
      printf("%f\t", ones->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(ones);

}

dynArray* zeroes(size_t x, size_t y){
  dynArray* zeroes = malloc(sizeof(dynArray_i*));
  zeroes = createArray(zeroes, x, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      insertElement(zeroes, 0, i, j);
    }
  }
  return(zeroes);

}

dynArray* id(size_t size){
  dynArray* id = malloc(sizeof(dynArray_i*));
  id = createArray(id, size, size);
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      if (i == j){
        insertElement(id, 1, i, j);
      }
      else{
        insertElement(id, 0, i, j);
      }
      printf("%f\t", id->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(id);
}

//Returns a pointer to the struct containing the randomly generated array
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

//Returns the pointer to the struct containing the transposed array
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

//Add 2 matrixes, returns the pointer to the struct containing the result
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

//Takes the matrix in 1st argument, substract to the matrix
//in the 2nd argument if same dimensions.
//Returns the pointer to the struct containing the result 
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

//Multiply 2 matrixes. Must be of correct dimensions or segfaults will happen.
//Takes 2 pointers to structs and return a pointer to struct.
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

//Decompose a squared matrix in two matrixes L and U that will need to be freed.
void decompositionLU(dynArray* mat){
  printf("Creating L...\n");
  dynArray* L = zeroes(mat->x, mat->x);
  printf("Creating U...\n");
  dynArray* U = zeroes(mat->x, mat->x);

  for (int i = 0; i < mat->x; i++){
    //Finding L
    for (int k = 0; k < i ; k++){
      L->array[i][k] = mat->array[i][k];
      for (int j = 0; j < k; j++){
        L->array[i][k] = L->array[i][k] - L->array[i][j]*U->array[j][k];
      }
      L->array[i][k] = L->array[i][k]/U->array[k][k];
    }
    //Finding U
    for (int k = i; k < mat->x; k++ ){
      U->array[i][k] = mat->array[i][k];
      for (int j = 0; j < i; j++){
        U->array[i][k] = U->array[i][k] - L->array[i][j] * U->array[j][k];
      }
    }
    for (int c = 0; c < mat->x; c++){
      L->array[i][i] = 1;
    }
  }
  printf("Matrix L\n");
  printArray(L);
  printf("Matrix U:\n");
  printArray(U);
  printf("Verification:\n");
  multiplyMatrix(L,U);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  dynArray rdMatrix;
  dynArray* ptrRdMat = generateRandomMatrix(&rdMatrix, 11, 7);
  printf("\n");
  printArray(ptrRdMat);
  // dynArray* mat1 = ones(8, 3);
  // printf("\n");
  // dynArray* mat2 = zeroes(6,9);
  // dynArray* mat3 = id(10);
  // printf("\n");
  dynArray* transMat = transpose(ptrRdMat);
  printArray(transMat);
  printf("\n");
  // addMatrix(transMat, ptrRdMat);
  // printf("\n" );
  multiplyMatrix(transMat, ptrRdMat);
  dynArray targetLU;
  dynArray* target = generateRandomMatrix(&targetLU, 16, 16);
  printf("Matrix to decompose: \n");
  printArray(target);
  decompositionLU(target);
  freeArray(transMat);
  return 0;
}
