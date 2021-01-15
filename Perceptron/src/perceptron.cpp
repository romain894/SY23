#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../include/perceptron.h"

using namespace std;

/*********** CONSTRUCTOR **************/

Perceptron::Perceptron(Matrix p, Matrix za, double e)
{
	//assign local variables from constructor to the object own variables
	this->p = p;
	this->za = za;
	this->e = e;
	#ifdef OPTIONNAL_CHECKS
	  printf("Check p and za size...\n");
		if (p.getNCol() != za.getNCol())
		{
			printf("\nERROR WITH p AND za SIZE !\n\n");
		}
		else {
			printf("p and za size OK\n");
		}
  #endif

	//we must not destroy p and za matrix else there memory will be freed and we
	//will no longer be able to use them again
	p.preventMemoryFreeing();
	za.preventMemoryFreeing();
}

/*********** DESTRUCTOR ***************/

Perceptron::~Perceptron()
{
	//p and za matrix will be already freed at the end of the main program where
	//they have been declared, so we must not destroy these object else they will
	//be destroyed twice
	p.preventMemoryFreeing();
	za.preventMemoryFreeing();
}

/*************** PRIVATE ***************/


/**************** PUBLIC ***************/

Matrix Perceptron::compute() {
	size_t nRowP = p.getNRow(); //Number of rows of p array
	size_t nColP = p.getNCol(); //Number of columns of p array, always equal to
	//nColP
	size_t nRowZa = za.getNRow(); //Number of row of za array

	Matrix dW(nRowP + 1, nRowZa); //create a new dW array for learning
	Matrix W(nRowP + 1, nRowZa); //create a new W array for storing the learning
	//result
	W.generateRandomMatrix(); //set each value of W to a random one between 0 and
	//1

	//Perceptron learning algorithme (Rosemblatt) :
	bool dWnotEqualToZero; //used to know if we need to start again the do while
	//loop. Set to false if each value of dW is equal to 0
	do {
		dWnotEqualToZero = false;
		for (size_t i = 0; i < nColP; i++) {
			Matrix Pi = p.getCol(i); //get the column i of p
			Pi.resize(Pi.getNRow() + 1, 1); //add an element a the end of the column
			Pi[Pi.getNRow()-1][0] = 1; //affect 1 to the last element
			Matrix Yi = W.transpose()*Pi; //Yi = W^T * P_i
			Matrix Zi = Yi.sign(); //Zi = sign(Y_i)
			Matrix Error = za.getCol(i) - Zi; //Error = Z_a_i - Z_i
			dW = Pi*Error.transpose()*e; //dW = e*P_i*Error^T
			W = W + dW;
			#ifdef DEBUG
				printf("dW = \n");
				dW.print();
				printf("W = \n");
				W.print();
			#endif
			if (!(dW == 0)) { //at least one dW in n is not equal to 0
				dWnotEqualToZero = true; //set to true to start again the do while loop
			}
		}
	}
	while (dWnotEqualToZero);  //is dW == 0 we exit this do while loop

	return W;
}
