#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/tab2ddyn.h"
#include "../include/matrice.h"

int main(int argc, char const *argv[]) {
  //srand(time(NULL));
  dynArray rdMatrix;
  dynArray* ptrRdMat = generateRandomMatrix(&rdMatrix, 11, 7);
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
  freeArray(transMat);
  return 0;
}
