#include <iostream>
#include <stdio.h>
#include <matrix.h>
//#define DEBUG


using namespace std;

int main()
{
  uint nRow = 3;
  uint nCol = 2;
  printf("A  =\n");
  Matrix ArrayA(nRow, nCol);
  ArrayA.generateRandomMatrix();
  printf("B = \n");
  Matrix ArrayB(nRow, nCol);
  ArrayB.generateRandomMatrix();
  printf("C = \n");
  Matrix ArrayC(nCol, nRow);
  ArrayC.generateRandomMatrix();
  printf("D = \n");
  Matrix ArrayD(nRow, nCol);
  ArrayD.generateRandomMatrix();
  printf("E = \n");
  Matrix ArrayE(nCol, nCol);
  ArrayE.generateRandomMatrix();
  printf("M = \n");
  Matrix Array(nRow, nCol);
  Array.generateRandomMatrix();
	//Array.array[3][4] = 3.789;
	//printf("%f\n", Array.array[3][4]);
  //cout << "Generate random Matrix :" << endl << "";
  Array.add(&ArrayA, &ArrayB);
  Array.sub(&ArrayA, &ArrayB);
  ArrayE.mul(&ArrayC, &ArrayD);
  printf("Exiting.\n");
	return EXIT_SUCCESS;
}
