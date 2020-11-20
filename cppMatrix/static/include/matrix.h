#ifndef MATRIX_H
#define MATRIX_H

#define DEBUG
#define OPTIONNAL_CHECKS

class Matrix
{
private:
  double pRandom(void);
  double randMax = 1;

public:
  Matrix(size_t rowNb, size_t colNb);
  ~Matrix();
  double **array = NULL;
  const size_t nRow;
  const size_t nCol;
  void print();
  void generateRandomMatrix();
  Matrix operator + (const Matrix& array2);
  Matrix operator - (const Matrix& array2);
  Matrix operator * (const Matrix& array2);
  Matrix operator + (double scalar);
  Matrix operator - (double scalar);
  Matrix operator * (double scalar);
};

#endif //MATRIX_H
