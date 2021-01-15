#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../include/perceptron.h"

#ifdef DEBUG

#endif

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

Perceptron::Perceptron(Matrix p, Matrix za, float e)
{
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
}

/*********** DESTRUCTOR ***************/

Perceptron::~Perceptron()
{

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

	while (dW > e) {
		for (size_t i = 0; i < nColP; i++) {
			Matrix Pi = p.getCol(i); //get the column i of p
			Matrix Yi = W.transpose()*Pi;
			//a verifier: pas sur de -1 et 1 pour le signe peut etre 0 et 1 ???
			Matrix Zi = Yi.sign();
			Matrix Error = za.getCol(i) - Zi;
			dW = Pi*Error.transpose()*e;
			W = W + dW;
		}
	}

	return W;
}
