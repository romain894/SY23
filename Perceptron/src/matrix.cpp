#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../include/matrix.h"

using namespace std;

/*********** CONSTRUCTOR **************/

Matrix::Matrix(size_t rowNb, size_t colNb) : nRow(rowNb), nCol(colNb)
{
	allocateMemory();
}

/*********** DESTRUCTOR ***************/

Matrix::~Matrix()
{
	#ifdef DEBUG
  	printf("Matrix : Destructor called\n");
  #endif
	freeMemory();
}

/*************** PRIVATE ***************/

void Matrix::allocateMemory()
{
	//allocation dynamique d'un tableau de pointeurs de reels
	//dynamic allocation of an array of real pointers
	array = (double **)new double*[nRow];

	//initialisation a NULL des valeurs du tableau de pointeurs
	for (size_t i = 0; i < nRow; i++) {
		array[i] = NULL;
	}
	//allocation dynamique d'un tableau de reels pour chaque
	//element du tableau de pointeurs
	for (size_t i = 0; i < nRow; i++) {
		array[i] = (double *)new double[nCol];
	}
}

void Matrix::freeMemory()
{
	if(preventMemoryFreeingState) { //check if memory must not to be freed
		preventMemoryFreeingState = 0;
		#ifdef DEBUG
	  	printf("Matrix : memory not freed (avoid)\n");
	  #endif
	}
	else { //free memory
		for (size_t i = 0; i < nRow; i++) {
			delete array[i];
		}
		delete array;
		#ifdef DEBUG
			printf("Matrix : memory freed\n");
		#endif
	}

}

double Matrix::pRandom(void)
{
  return (double)rand()/(double)RAND_MAX*randMax;
}

/**************** PUBLIC ***************/

size_t Matrix::getNRow() {
	return nRow;
}

size_t Matrix::getNCol() {
	return nCol;
}

void Matrix::preventMemoryFreeing()
{
  preventMemoryFreeingState = 1;
}

void Matrix::print()
{
  printf("Print matrix :\n");
  for (size_t i = 0; i < nRow; i++){
    for (size_t j = 0; j < nCol; j++){
      printf("%f\t", array[i][j]);
    }
    printf("\n");
  }
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

Matrix Matrix::operator + (const Matrix& array2)
{
  #ifdef DEBUG
  	printf("\nadd 2 matrix :\n");
  #endif
	Matrix MatrixM(nRow, nCol);
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
      MatrixM.array[i][j] = this->array[i][j] + array2.array[i][j];
      #ifdef DEBUG
      	printf("%f\t", MatrixM.array[i][j]);
      #endif
    }
    #ifdef DEBUG
    	printf("\n");
    #endif
  }
	return MatrixM;
}

Matrix Matrix::operator - (const Matrix& array2)
{
  #ifdef DEBUG
  	printf("\nsubstract 2 matrix :\n");
  #endif
	Matrix MatrixM(nRow, nCol);
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
      MatrixM.array[i][j] = this->array[i][j] - array2.array[i][j];
      #ifdef DEBUG
      	printf("%f\t", MatrixM.array[i][j]);
      #endif
    }
    #ifdef DEBUG
    	printf("\n");
    #endif
  }
	return MatrixM;
}


Matrix Matrix::operator * (const Matrix& array2)
{
  #ifdef DEBUG
	  printf("\nmultiply 2 matrix :\n");
		cout << "row = " << this->nRow << " col = " << array2.nCol << endl;
  #endif
	#ifdef OPTIONNAL_CHECKS
	  printf("Check matrix size...\n");
		if (this->nCol != array2.nRow)
		{
			printf("\nERROR WITH MATRIX SIZE !\n\n");
		}
		else {
			printf("Matrix size OK\n");
		}
  #endif
	Matrix MatrixM(this->nRow, array2.nCol);
  for (size_t i = 0; i < this->nRow; i++) {
    for (size_t j = 0; j < array2.nCol; j++) {
      MatrixM.array[i][j] = 0;
			for (size_t k = 0; k < this->nCol; k++) {
				MatrixM.array[i][j] += this->array[i][k] * array2.array[k][j];
			}
      #ifdef DEBUG
      	printf("%f\t", MatrixM.array[i][j]);
      #endif
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
	return MatrixM;
}

Matrix Matrix::operator + (double scalar)
{
  #ifdef DEBUG
  	printf("\nadd a scalar to a matrix :\n");
  #endif
	Matrix MatrixM(nRow, nCol);
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
      MatrixM.array[i][j] = this->array[i][j] + scalar;
      #ifdef DEBUG
      	printf("%f\t", MatrixM.array[i][j]);
      #endif
    }
    #ifdef DEBUG
    	printf("\n");
    #endif
  }
	return MatrixM;
}


Matrix Matrix::operator - (double scalar)
{
  #ifdef DEBUG
  	printf("\nsubstract a scalar to a matrix :\n");
  #endif
	Matrix MatrixM(nRow, nCol);
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
      MatrixM.array[i][j] = this->array[i][j] - scalar;
      #ifdef DEBUG
      	printf("%f\t", MatrixM.array[i][j]);
      #endif
    }
    #ifdef DEBUG
    	printf("\n");
    #endif
  }
	return MatrixM;
}


Matrix Matrix::operator * (double scalar)
{
  #ifdef DEBUG
  	printf("\nmultiply a scalar to a matrix :\n");
  #endif
	Matrix MatrixM(nRow, nCol);
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
      MatrixM.array[i][j] = this->array[i][j] * scalar;
      #ifdef DEBUG
      	printf("%f\t", MatrixM.array[i][j]);
      #endif
    }
    #ifdef DEBUG
    	printf("\n");
    #endif
  }
	return MatrixM;
}

void Matrix::operator = (Matrix array2)
{
  #ifdef DEBUG
  	printf("\nMatrix assignment...\n");
  #endif
	this->freeMemory();
	this->nRow = array2.nRow;
	this->nCol = array2.nCol;
	this->array = array2.array;
	array2.preventMemoryFreeing();
	#ifdef DEBUG
  	printf("Matrix assignment OK.\n");
  #endif
}

double * Matrix::operator [](int id) {
	return this->array[id];
}

bool Matrix::operator < (double scalar)
{
  #ifdef DEBUG
  	printf("\ntest if a matrix is less than a scalar :\n");
  #endif
	bool res = true;
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
			if (this->array[i][j] >= scalar) {
				res = false;
			}
    }
    #ifdef DEBUG
    	printf("Result : %d\n", res);
    #endif
  }
	return res;
}

bool Matrix::operator > (double scalar)
{
  #ifdef DEBUG
  	printf("\ntest if a matrix is greater than a scalar :\n");
  #endif
	bool res = true;
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
			if (this->array[i][j] <= scalar) {
				res = false;
			}
    }
    #ifdef DEBUG
    	printf("Result : %d\n", res);
    #endif
  }
	return res;
}

bool Matrix::operator == (double scalar)
{
  #ifdef DEBUG
  	printf("\ntest if a matrix is equal to a scalar :\n");
  #endif
	bool res = true;
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
			if (this->array[i][j] != scalar) {
				res = false;
			}
    }
    #ifdef DEBUG
    	printf("Result : %d\n", res);
    #endif
  }
	return res;
}

bool Matrix::operator <= (double scalar)
{
  #ifdef DEBUG
  	printf("\ntest if a matrix is less than or equal to a scalar :\n");
  #endif
	bool res = true;
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
			if (this->array[i][j] > scalar) {
				res = false;
			}
    }
    #ifdef DEBUG
    	printf("Result : %d\n", res);
    #endif
  }
	return res;
}

bool Matrix::operator >= (double scalar)
{
  #ifdef DEBUG
  	printf("\ntest if a matrix is greater than or equal to a scalar :\n");
  #endif
	bool res = true;
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
			if (this->array[i][j] < scalar) {
				res = false;
			}
    }
    #ifdef DEBUG
    	printf("Result : %d\n", res);
    #endif
  }
	return res;
}

Matrix Matrix::transpose()
{
	#ifdef DEBUG
  	printf("\ntranspose a matrix:\n");
  #endif
	Matrix MatrixM(nCol, nRow); //reverse sizes to transpose
  for (size_t i = 0; i < nRow; i++) {
    for (size_t j = 0; j < nCol; j++) {
      MatrixM.array[j][i] = this->array[i][j];
      #ifdef DEBUG
      	printf("%f\t", MatrixM.array[j][i]);
      #endif
    }
    #ifdef DEBUG
    	printf("\n");
    #endif
  }
	return MatrixM;
}

Matrix Matrix::getCol(size_t col)
{
	#ifdef DEBUG
  	printf("\nget the column of a matrix:\n");
  #endif
	Matrix MatrixM(nRow, 1);
  for (size_t i = 0; i < nRow; i++) {
    MatrixM.array[i][1] = this->array[i][col];
    #ifdef DEBUG
    	printf("%f\t", MatrixM.array[i][1]);
    #endif
  }
	return MatrixM;
}

Matrix Matrix::getRow(size_t row)
{
	#ifdef DEBUG
  	printf("\nget the row of a matrix:\n");
  #endif
	Matrix MatrixM(1, nCol);
  for (size_t i = 0; i < nCol; i++) {
    MatrixM.array[1][i] = this->array[row][i];
    #ifdef DEBUG
    	printf("%f\t", MatrixM.array[1][i]);
    #endif
  }
	return MatrixM;
}
