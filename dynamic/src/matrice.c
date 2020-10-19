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

dynArray* eye(size_t size){
  dynArray* eye = malloc(sizeof(dynArray_i*));
  eye = createArray(eye, size, size);
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      if (i == j){
        insertElement(eye, 1, i, j);
      }
      else{
        insertElement(eye, 0, i, j);
      }
      printf("%f\t", eye->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(eye);
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
//Doesn't check for matrix regularity.
//Return a pointer to an array of pointers pointing to structs containing L and U.
dynArray** decompositionLU(dynArray* mat){
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
  dynArray** couple = malloc(2*sizeof(dynArray*));
  *couple = L;
  *(couple+1) = U;
  return couple;
}

dynArray* inverseMatrix(dynArray* mat){
  dynArray** set = decompositionLU(mat);
  // printArray(*set);
  printf("debug: %f\n", (*(set+1))->array[1][2]);
  // printArray(*(set+1));
  //Forward elimination, L*b = idMatrix:
  dynArray* idMatrix = eye(mat->x);
  dynArray* b = malloc(sizeof(dynArray*));
  b = createArray(b, mat->x, mat->y);

  for (int i = 0; i < mat->x; i++){
    b->array[1][i] = idMatrix->array[1][i] / (*set)->array[1][1];
    for (int k = 1; k < mat->x; k++){
      double sigma = 0;
      for (int j = k; j > 0; j--){
        sigma = sigma + (*set)->array[k][j] * b->array[j][i];
      }
      b->array[k][i] = (idMatrix->array[k][i] - sigma)/(*set)->array[k][k];
    }
  }
  //Backwards substitution, U*(A^-1) = b:
  dynArray* invMat = malloc(sizeof(dynArray*));
  invMat = createArray(invMat, mat->x, mat->y);
  for (int i = 0; i < mat->x; i++){
    invMat->array[mat->x-1][i] = (b->array[mat->x-1][i]) / (*(set+1))->array[mat->x-1][mat->x-1];
    printf("debug: %f\n", (*(set+1))->array[1][2]);
    for (int k = mat->x-1; k >= 0; k--){
      double sigma = 0;
      for (int j = k; j < mat->x; j++){
        sigma = sigma + (*(set+1))->array[k][j] * invMat->array[j][i];
      }
      invMat->array[k][i] = (b->array[k][i] - sigma)/(*(set+1))->array[k][k];
    }
  }
  printArray(invMat);
  return invMat;
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
  // dynArray* mat3 = eye(10);
  // printf("\n");
  dynArray* transMat = transpose(ptrRdMat);
  printArray(transMat);
  printf("\n");
  // addMatrix(transMat, ptrRdMat);
  // printf("\n" );
  multiplyMatrix(transMat, ptrRdMat);
  dynArray targetLU;
  dynArray* target = generateRandomMatrix(&targetLU, 3, 3);
  printf("Matrix to decompose: \n");
  printArray(target);
  printf("Inversion!\n");
  inverseMatrix(target);
  freeArray(transMat);
  return 0;
}
