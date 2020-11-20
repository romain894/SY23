#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/tab2ddyn.h"
#include "../include/matrice.h"

int main(int argc, char const *argv[]) {
  //Initializing random seed
  srand(time(NULL));

  // //Creation of a randomly generated arrays.
  dynArray* ptrRdMat = generateRandomMatrix(4, 3);
  printf("\n");
  printArray(ptrRdMat);

  //Creation of ones, zeroes arrays and identity matrixes.
  dynArray* mat1 = ones(4,3);
  printArray(mat1);
  printf("\n");
  dynArray* mat2 = zeroes(4,6);
  printf("\n");
  printArray(mat2);
  dynArray* mat3 = eye(5);
  printf("\n");
  printArray(mat3);

  //Transposition with the randomly generated array beforehand.
  dynArray* transMat = transpose(ptrRdMat);
  printArray(transMat);
  printf("\n");

  //Add the transposed random array to the original array.
  dynArray* addedMat = addMatrix(ptrRdMat, mat1);
  printArray(addedMat);

  //Substract the transposed random array to the original.
  dynArray* subMat = subMatrix(ptrRdMat, mat1);
  printArray(subMat);

  //LU decomposition of the randomly generated matrix targetLU
  dynArray* target = generateRandomMatrix(5, 5);
  printf("Matrix to decompose: \n");
  printArray(target);
  dynArray** set = decompositionLU(target);

  //Making sure that the LU decomposition worked:
  printf("Verifying LU decomposition...\n");
  dynArray* multiplyResult1 = multiplyMatrix(*(set),*(set+1));
  printArray(multiplyResult1);

  //Inverting the target matrix
  dynArray* invTarget = inverseMatrix(target);
  printf("Inverted matrix:\n");
  printArray(invTarget);
  dynArray* multiplyResult2 = multiplyMatrix(target, invTarget);
  printArray(multiplyResult2);

  //Freeing all used arrays
  freeArray(ptrRdMat);
  freeArray(mat1);
  freeArray(mat2);
  freeArray(mat3);
  freeArray(transMat);
  freeArray(addedMat);
  freeArray(target);
  freeCouple(set);
  freeArray(multiplyResult1);
  freeArray(invTarget);
  freeArray(multiplyResult2);

  return 0;
}
