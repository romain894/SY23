#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/tab2ddyn.h"
#include "../include/matrice.h"

int main(int argc, char const *argv[]) {
  //Initializing random seed
  srand(time(NULL));

  //Creation of a randomly generated arrays.
  dynArray* ptrRdMat = generateRandomMatrix(4, 3);
  printf("\n");
  printArray(ptrRdMat);

  //Creation of ones, zeroes arrays and identity matrixes.
  dynArray* mat1 = ones(3,2);
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
  dynArray* addedMat = addMatrix(transMat, ptrRdMat);
  printArray(addedMat);

  //LU decomposition of the randomly generated matrix targetLU
  dynArray* target = generateRandomMatrix(5, 5);
  printf("Matrix to decompose: \n");
  printArray(target);
  dynArray** set = decompositionLU(target);

  //Making sure that the LU decomposition worked:
  printf("Verifying LU decomposition...\n");
  multiplyMatrix(*(set),*(set+1));

  //Inverting the target matrix
  dynArray* invTarget = inverseMatrix(target);
  printf("Inverted matrix:\n");
  printArray(invTarget);
  multiplyMatrix(target, invTarget);

  //Freeing all used arrays
  freeArray(ptrRdMat);
  freeArray(mat1);
  freeArray(mat2);
  freeArray(mat3);
  freeArray(transMat);
  freeArray(addedMat);
  freeArray(invTarget);
  freeCouple(set);
  return 0;
}
