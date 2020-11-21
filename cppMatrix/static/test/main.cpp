#include <iostream>
#include <stdio.h>
#include <matrix.h>
//#define DEBUG


using namespace std;

int main()
{
  uint nRow = 2;
  uint nCol = 3;
  printf("A  =\n");
  Matrix MatrixA(nRow, nCol);
  MatrixA.generateRandomMatrix();
  printf("B = \n");
  Matrix MatrixB(nRow, nCol);
  MatrixB.generateRandomMatrix();
  printf("C = \n");
  Matrix MatrixC(nCol+2, nRow);
  MatrixC.generateRandomMatrix();
  printf("D = \n");
  Matrix MatrixD(nRow, nCol);
  MatrixD.generateRandomMatrix();
	MatrixD.array[1][2] = 3.14159;
  printf("D = \n");
  MatrixD.print();
  printf("\nM1 = A + B =");
  Matrix MatrixM1 = MatrixA + MatrixB;
  // MatrixM1.print();
  printf("\nM2 = A - B");
  Matrix MatrixM2 = MatrixA - MatrixB;
  // MatrixM2.print();
  printf("\nM3 = C * D");
  Matrix MatrixM3 = MatrixC * MatrixD;
  // MatrixM3.print();
  double x = 5;
  printf("\nx = %f", x);
  printf("\nM4 = C + x");
  Matrix MatrixM4 = MatrixC + x;
  printf("\nM4 = C - x/2");
  MatrixM4 = MatrixC - x/2;
  printf("\nM4 =\n");
  MatrixM4.print();
  printf("\nM5 = C * x");
  Matrix MatrixM5(1, 1);
  MatrixM5 = MatrixC * x;
  printf("\nM5 =\n");
  MatrixM5.print();
  printf("Exiting...\n");
	return EXIT_SUCCESS;
}
