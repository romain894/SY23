#ifndef MATRIX_H
#define MATRIX_H

//Romain THOMAS 2021
//V 1.1

#define DEBUG
#define OPTIONNAL_CHECKS

class Matrix
{
private:
  double pRandom(void);
  void allocateMemory();
  void freeMemory();
  double randMax = 1;
  bool preventMemoryFreeingState = 0; //do not use in your code

public:
  Matrix()=default; //default constructor
  Matrix(size_t rowNb, size_t colNb);
  ~Matrix();
  double **array = NULL;
  size_t nRow; //do not use in your code
  size_t nCol; //do not use in your code
  void preventMemoryFreeing(); //do not use in your code
  void print();
  void generateRandomMatrix();
  Matrix operator + (const Matrix& array2);
  Matrix operator - (const Matrix& array2);
  Matrix operator * (const Matrix& array2);
  Matrix operator + (double scalar);
  Matrix operator - (double scalar);
  Matrix operator * (double scalar);
  void operator = (Matrix array2);
  double * operator [](int id);
};

#endif //MATRIX_H
