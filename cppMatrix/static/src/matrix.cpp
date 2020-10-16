#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../include/matrix.h"

using namespace std;

/*********** CONSTRUCTOR **************/

Matrix::Matrix(size_t rowNb, size_t colNb)
{
	createCol(colNb);
	createRow(rowNb, colNb);
  nRow = rowNb;
  nCol = colNb;
}

/*************** PRIVATE ***************/

void Matrix::createCol(size_t colNb)
{
	//allocation dynamique d'un tableau de pointeurs de reels
	array = (double **)new double*[colNb];

	//initialisation a NULL des valeurs du tableau de pointeur
	for (size_t i = 0; i < colNb; i++) {
		array[i] = NULL;
	}
}

void Matrix::createRow(size_t rowNb, size_t colNb)
{
	//allocation dynamique d'un tableau de reels pour chaque
	//element du tableau de pointeur *tab
	for (uint i = 0; i < rowNb; i++) {
		array[i] = (double *)new double[rowNb];
	}
}


double Matrix::pRandom(void)
{
  return (double)rand()/(double)RAND_MAX*randMax;
}

/**************** PUBLIC ***************/

size_t Matrix::getNRow()
{
	return nRow;
}

size_t Matrix::getNCol()
{
	return nCol;
}

void Matrix::generateRandomMatrix()
{
  #ifdef DEBUG
  printf("generate random matrix :\n");
  #endif
  for (size_t i = 0; i < nRow; i++){
    for (size_t j = 0; j < nCol; j++){
      array[i][j] = pRandom();
      #ifdef DEBUG
      printf("%f\t", array[i][j]);
      #endif
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
}

void Matrix::add(Matrix *array1, Matrix *array2)
{
  #ifdef DEBUG
  printf("\nadd 2 matrix :\n");
  #endif
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
      array[i][j] = array1->array[i][j] + array2->array[i][j];
      #ifdef DEBUG
      printf("%f\t", array[i][j]);
      #endif
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
}

void Matrix::sub(Matrix *array1, Matrix *array2)
{
  #ifdef DEBUG
  printf("\nsubtract 2 matrix :\n");
  #endif
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
      array[i][j] = array1->array[i][j] - array2->array[i][j];
      #ifdef DEBUG
      printf("%f\t", array[i][j]);
      #endif
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
}

void Matrix::mul(Matrix *array1, Matrix *array2)
{
  #ifdef DEBUG
  printf("\nmultiply 2 matrix :\n");
  #endif
	#ifdef OPTIONNAL_CHECKS
  printf("Check matrix sizes...\n");
	if ((array1->getNCol() != array2->getNRow()) || (array->getNCol() != array2->getNCol()) || (array->getNRow() != array1->getNRow()))
	{
		printf("\nCheck matrix sizes...\n");
	}
  #endif
	size_t tmpArray1NCol = array1->getNCol();
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
      array[i][j] = 0;
			for (size_t k = 0; k < tmpArray1NCol; k++) {
				array[i][j] += array1->array[i][k] * array2->array[k][j];
			}
      #ifdef DEBUG
      printf("%f\t", array[i][j]);
      #endif
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
}
