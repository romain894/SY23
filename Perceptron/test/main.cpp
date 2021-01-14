#include <iostream>
#include <stdio.h>
#include <perceptron.h>
//#define DEBUG


using namespace std;

int main()
{
  printf("Hello world !\n");

  uint nRow = 2;
  uint nCol = 3;
  printf("A  =\n");
  Matrix MatrixA(nRow, nCol);
  MatrixA.generateRandomMatrix();

  printf("%f\n", MatrixA[0][1]);

  //Matrix P();

  //Perceptron PerceptronTest(7);

  //PerceptronTest.test();

  printf("Exiting...\n");
	return EXIT_SUCCESS;
}
