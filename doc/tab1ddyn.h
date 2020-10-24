#ifndef TAB1DDYN_H
#define TAB1DDYN_H

typedef struct{
  int *vector;
  size_t used;
  size_t size;
} tab_int;

typedef struct{
  double *vector;
  size_t used;
  size_t size;
} tab;

void createVector_i(tab_int *x, size_t initSize);
void insertRow_i(tab_int *x, int element);
void freeVector(tab_int *x);
#endif
