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

  double e = 0.1;

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

  printf("Enter Perceptron constructor\n");
  Perceptron percep(p, Za, e);
  printf("Exit Perceptron constructor\n");

  printf("Enter Perceptron compute\n");
  Matrix Wres = percep.compute();
  printf("Exit Perceptron compute\n");

  printf("Wres = \n");
  Wres.print();


  //Matrix P();

  printf("Exiting...\n");
	return EXIT_SUCCESS;
}
