#include <stdio.h>
#include <stdlib.h>
#include "tab1ddyn.h"

void createVector_i(tab_int* x, size_t initSize){
  x->vector = (int*)calloc(initSize, sizeof(int));
  x->used = 0;
  x->size = initSize;
  printf("Created vector of %d elements, size of %d bytes.\n", x->size, x->size * sizeof(int) );
}

void insertRow_i(tab_int *x, int element){
  if (x->used == x->size){
    x->size++;
    x->vector = (int*)realloc(x->vector, x->size * sizeof(int));
  }
  x->vector[x->used++] = element;
}

void createVector(tab* x, size_t initSize){
  x->vector = (double*)calloc(initSize, sizeof(double));
  x->used = 0;
  x->size = initSize;
}

void insertRow(tab* x, double element){
  if (x->used == x->size){
    x->vector = (double*)realloc(x->vector, x->size++ * sizeof(double));
  }
  x->vector[x->used++] = element;
}

void freeVector(tab_int* x){
  free(x->vector);
  x->vector = NULL;
  x->size = x->used = 0;
  printf("Memory freed\n");
}

void printVector(tab_int* x){
  int tmp = 0;
  int i = 0;
  while (tmp <= x->size){
    printf("%d\n", x->vector[i]);
    i++;
    tmp++;
  }
}


int main(int argc, char const *argv[]) {
  tab_int x;
  createVector_i(&x, 3);
  insertRow_i(&x, rand());
  insertRow_i(&x, rand());
  insertRow_i(&x, rand());
  insertRow_i(&x, rand());
  printVector(&x);
  freeVector(&x);
  return 0;
}
