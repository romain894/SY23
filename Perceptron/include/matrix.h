#ifndef MATRIX_H
#define MATRIX_H

//Romain THOMAS 2021
//V 1.6.1

//#define DEBUG
//#define OPTIONNAL_CHECKS

class Matrix
{
private:
  double pRandom(void); //return a random number between 0 and randMax (double)
  void allocateMemory(); //allocate memory to create a new array
  void freeMemory(); //free the memory taking care of previous
  //preventMemoryFreeing() call
  double randMax = 1; //max random number which will be returned with pRandom()
  bool preventMemoryFreeingState = 0; //do not use in your code
  //preventMemoryFreeingState = 0 the memory will be freed when the destructor
  //will be called
  //preventMemoryFreeingState = 1 the memory won't be freed when the destructor
  //will be called

public:
  Matrix()=default; //default constructor
  Matrix(size_t rowNb, size_t colNb); //constructor, create a new array with
  //rowNb rows and colNb columns, the values of the matrix are not set
  ~Matrix(); //destructor
  double **array = NULL; //pointer to the dynamic array containing the matrix
  //values
  size_t nRow; //do not use in your code
  size_t nCol; //do not use in your code
  size_t getNRow(); //return the rows number of this matrix
  size_t getNCol(); //return the columns number of this matrix
  void preventMemoryFreeing(); //do not use in your code
  //when the destructor will be called, its prevent from freeing the memory of
  //the array, for example when another object use the same memory
  void print(); //print the array
  void generateRandomMatrix(); //generate random values for each cells of the
  //array
  Matrix operator + (const Matrix& array2); //add two matrix
  Matrix operator - (const Matrix& array2); //substract two matrix
  Matrix operator * (const Matrix& array2); //multiply two matrix
  Matrix operator + (double scalar); //add a matrix and a scalar (double)
  Matrix operator - (double scalar); //substract a matrix and a scalar (double)
  Matrix operator * (double scalar); //multiply a matrix and a scalar (double)
  void operator = (Matrix array2); //assign a matrix to another, when affecting
  //an existing array to another one, it keeps the same memory location for
  //storing the array. Its result in performance and memory managment
  //improvement but can create error if you delete the object and free the
  //memory without taking care to the other objects using the same memory.
  //See preventMemoryFreeing() function to avoid to freeing memory when the
  //destructor of the object is called. Be carreful, it can result in memory
  //leak ! Prefer using preventMemoryFreeing() in functions you checked
  //instead of in the main code.
  double * operator [](int id); //operator to allow acces with [][] to the
  //matrix values
  bool operator < (double var); // return if each the values of a matrix are
  //less than a scalar (double)
  bool operator > (double var); // return if each the values of a matrix are
  //greater than a scalar (double)
  bool operator == (double var); // return if a matrix is equal to another one
  bool operator != (double var); // return if each value of a matrix are not
  //equal to a scalar (double)
  bool operator >= (double var); // return if each the values of a matrix are
  //less than or equal to a scalar (double)
  bool operator <= (double var); // return if each the values of a matrix are
  //greater than or equal to a scalar (double)
  Matrix transpose(); //return the transpose of a matrix
  Matrix sign(); // return a matrix with each element equal to -1 or 1
  //corresponding to the sign of each element
  Matrix getCol(size_t col); //return a matrix corresponding to the column col
  //of this matrix
  Matrix getRow(size_t row);//return a matrix corresponding to the row row of
  //this matrix
  void resize(size_t rowNb, size_t colNb); //resize a matrix, the new one can be
  // smaller or larger than the previous one. When it is possible, the value of
  //the element is equal to the value of the element in the previous matrix else
  //else its value is set to 0
};

#endif //MATRIX_H
