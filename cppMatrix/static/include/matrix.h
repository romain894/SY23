#ifndef MATRIX_H
#define MATRIX_H

#define DEBUG

class Matrix
{
private:
  void createCol(size_t rowNb);
  void createRow(size_t rowNb, size_t ColNb);
  double pRandom(void);
  double randMax = 1;
  size_t nRow;
  size_t nCol;

public:
  Matrix(size_t rowNb, size_t colNb);
  double **array = NULL;
  size_t getNRow();
  size_t getNCol();
  void generateRandomMatrix();
  void add(Matrix *array1, Matrix *array2);
  void sub(Matrix *array1, Matrix *array2);
  void mul(Matrix *array1, Matrix *array2);
};

#endif //MATRIX_H
