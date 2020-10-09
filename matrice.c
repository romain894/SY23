#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tab2ddyn.h"

double pRandom(void){
  return (double)rand()/(double)RAND_MAX  ;
}

double** generateRandomMatrix(int rows, int column){
  //pointer to an array of rows elements
  double **dbMatrix = (double**)malloc(rows * sizeof(double));
  for (int i = 0; i < rows; i++){
    //each element in row is a pointer to a column(vector)
    dbMatrix[i] = (double*)malloc(column * sizeof(double));
    for (int j = 0; j < column; j++){
      double tmp = pRandom();
      dbMatrix[i][j] = tmp;
    }
  }
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < column; j++){
      printf("%f\t", dbMatrix[i][j]);
    }
    printf("\n");
  }
  return (dbMatrix);
}

// int** ones(size_t x, size_t y){
//   int **ones = (int**)malloc(x*sizeof(int));
//   for (int i = 0; i < x; i++){
//     //each element in row is a pointer to a column(vector)
//     ones[i] = (int*)malloc(y * sizeof(int));
//     for (int j = 0; j < y; j++){
//       ones[i][j] = 1;
//       printf("%d\t", ones[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");
//   return (ones);
// }

dynArray_i* ones(size_t x, size_t y){
  dynArray_i ptrArray;
  dynArray_i* ones = createArray_i(&ptrArray, x, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      insertArray_i(ones, 1, i, j);
      printf("%d\t", ones->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(ones);

}

dynArray_i* zeroes(size_t x, size_t y){
  dynArray_i ptrArray;
  dynArray_i* zeroes = createArray_i(&ptrArray, x, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      insertArray_i(zeroes, 1, i, j);
      printf("%d\t", zeroes->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(zeroes);

}

dynArray_i* id(size_t size){
  dynArray_i ptrArray;
  dynArray_i* id = createArray_i(&ptrArray, size, size);
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      if (i == j){
        insertArray_i(id, 1, i, j);
      }
      else{
        insertArray_i(id, 0, i, j);
      }
      printf("%d\t", id->array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return(id);

}

double** transpose(double** ptrArray){

  return (double**)NULL;
}
int main(int argc, char const *argv[]) {
  // int r, c;
  // printf("Number of Rows?\n");
  // scanf("%d", &r );
  // printf("Number of Columns?\n");
  // scanf("%d", &c );
  // srand(time(NULL));
  // generateRandomMatrix(r, c);

  dynArray_i* first = ones(3,3);
  dynArray_i* second = zeroes(2,2);
  dynArray_i* third = id(6);
  return 0;
}
