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
	//Array.array[3][4] = 3.789;
	//printf("%f\n", Array.array[3][4]);
  //cout << "Generate random Matrix :" << endl << "";
  printf("\nM1 = A + B =");
  Matrix MatrixM1 = MatrixA + MatrixB;
  // MatrixM1.print();
  printf("\nM2 = A - B");
  Matrix MatrixM2 = MatrixA - MatrixB;
  // MatrixM2.print();
  printf("\nM3 = C * D");
  Matrix MatrixM3 = MatrixC * MatrixD;
  // MatrixM3.print();
  // printf("\nM4 = D * C");
  // Matrix MatrixM4 = MatrixD * MatrixC;
  // MatrixM4.print();
  double x = 5;
  printf("\nM5 = C + x");
  Matrix MatrixM5 = MatrixC + x;
  printf("\nM5 = C - x");
  Matrix MatrixM6 = MatrixC - x;
  printf("\nM5 = C * x");
  MatrixM5();
  MatrixM5 = MatrixC * x;
  printf("Exiting...\n");
	return EXIT_SUCCESS;
}
