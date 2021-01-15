#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../include/perceptron.h"

using namespace std;

/*
entree :
p : entre
za : sortie attendue
e : taux d'apprentissage
sortie :
w : la matrice contenant l'apprentissage
*/

/*********** CONSTRUCTOR **************/

Perceptron::Perceptron(Matrix p, Matrix za, double e)
{
	printf("123 !!!\n");
	this->p = p;
	printf("456 !!!\n");
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

	p.preventMemoryFreeing();
	za.preventMemoryFreeing();
}

/*********** DESTRUCTOR ***************/

Perceptron::~Perceptron()
{
	//theses matrix will be already freed at the end of the main program where
	//they have been declared
	p.preventMemoryFreeing();
	za.preventMemoryFreeing();
}

/*************** PRIVATE ***************/


/**************** PUBLIC ***************/

	Matrix Perceptron::compute() {
	size_t nRowP = p.getNRow();
	size_t nColP = p.getNCol();
	size_t nRowZa = za.getNRow();
	// size_t nColZa = za.getNCol(); always equal to nColP

	Matrix dW(nRowP + 1, nRowZa);
	Matrix W(nRowP + 1, nRowZa);
	W.generateRandomMatrix();

	bool dWnotEqualToZero;

	do {
		#ifdef DEBUG
			printf("\n\n");
		#endif
		dWnotEqualToZero = false;
		for (size_t i = 0; i < nColP; i++) {
			#ifdef DEBUG
				printf("get the column i of p :\n");
			#endif
			Matrix Pi = p.getCol(i); //get the column i of p
			#ifdef DEBUG
				printf("add an element a the end of the column and affect it 1\n");
			#endif
			Pi.resize(Pi.getNRow() + 1, 1); //add an element a the end of the column
			#ifdef DEBUG
				printf("affect 1 to the last element\n");
			#endif
			Pi[Pi.getNRow()-1][0] = 1;//affect 1 to the last element
			#ifdef DEBUG
				printf("finish compute :\n");
			#endif
			printf("***************************************************\n");
			printf("W.transpose() =\n");
			W.transpose().print();
			printf("Pi =\n");
			Pi.print();
			printf("***************************************************\n");
			Matrix Yi = W.transpose()*Pi;
			printf("Yi =\n");
			Yi.print();
			Matrix Zi = Yi.sign();
			printf("Za =\n");
			za.getCol(i).print();
			printf("Zi =\n");
			Zi.print();
			Matrix Error = za.getCol(i) - Zi;
			dW = Pi*Error.transpose()*e;
			W = W + dW;
			#ifdef DEBUG
				printf("dW = \n");
				dW.print();
				printf("W = \n");
				W.print();
			#endif
			if (dW == 0) {
				#ifdef DEBUG
					printf("dW == 0\n");
				#endif
			}
			else {
				dWnotEqualToZero = true;
				#ifdef DEBUG
					printf("dW != 0\n");
				#endif
			}
		}

		//exit (EXIT_FAILURE); //stop the programm
	}
	while (dWnotEqualToZero);

	return W;
}
