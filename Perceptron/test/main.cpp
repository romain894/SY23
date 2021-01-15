#include <iostream>
#include <stdio.h>
#include <perceptron.h>
//#define DEBUG


using namespace std;

int main()
{
  printf("Hello world !\n");

  /*size_t nRow = 2;
  size_t nCol = 3;
  printf("A  =\n");
  Matrix MatrixA(nRow, nCol);
  MatrixA.generateRandomMatrix();

  printf("%f\n", MatrixA[0][1]);

  MatrixA[0][1] = 2.56;
  printf("%f\n", MatrixA[0][1]);*/

  size_t nRow = 2;
  size_t nCol = 4;

  e = 0.01;

  Matrix p(nRow, nCol);
  Matrix Za(nRow, nCol);

  p[0][0] = -1;
  p[0][1] = -1;
  p[0][2] =  1;
  p[0][3] =  1;

  p[1][0] = -1;
  p[1][1] =  1;
  p[1][2] = -1;
  p[1][3] =  1;

  Za[0][0] = -1;
  Za[0][1] = -1;
  Za[0][2] = -1;
  Za[0][3] =  1;

  Za[1][0] = -1;
  Za[1][1] =  1;
  Za[1][2] =  1;
  Za[1][3] =  1;

  Perceptron percep(p, za, e);

  Matrix Wres = percep.compute();

  Wres.print();



  //Matrix P();

  printf("Exiting...\n");
	return EXIT_SUCCESS;
}
