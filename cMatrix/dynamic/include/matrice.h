#ifndef MATRICE_H
#define MATRICE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tab2ddyn.h"
#include "matrice.h"

//Returns a pointer to the struct containing the randomly generated array
dynArray* generateRandomMatrix(int rows, int column);
//Return a random double between 0 and 1
double pRandom(void);
//Return an array filled with 1 of the precised (x,y) parameters
dynArray* ones(size_t x, size_t y);
//Return an array of zeroes with the (x,y) parameters
dynArray* zeroes(size_t x, size_t y);
//Return the identity matrix of the "size" parameter
dynArray* eye(size_t size);
//Add 2 matrixes, returns the pointer to the struct containing the result
//If they are of the same dimension.
dynArray* addMatrix(dynArray* mat1, dynArray* mat2);
//Returns the pointer to the struct containing the transposed array
dynArray* transpose(dynArray* mat);
//Multiply 2 matrixes. Must be of correct dimensions or segfaults will happen.
//Takes 2 pointers to structs and return a pointer to struct.
dynArray* multiplyMatrix(dynArray* mat1, dynArray* mat2);
//Takes the matrix in 1st argument, substract to the matrix
//in the 2nd argument if same dimensions.
//Returns the pointer to the struct containing the result
dynArray* subMatrix(dynArray* mat1, dynArray* mat2);
//Decompose a squared matrix in two matrixes L and U that will need to be freed.
//Doesn't check for matrix regularity.
//Return a pointer to an array of pointers pointing to structs containing L and U.
dynArray** decompositionLU(dynArray* mat);
//Inverse the matrix following the LU decomposition.
//Matrix has to be square AND invertible.
//This method doesn't check of inversibility.
dynArray* inverseMatrix(dynArray* mat);

#endif
