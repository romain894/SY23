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

Perceptron::Perceptron(const Matrix& p, const Matrix& za, float e)
{

}

/*********** DESTRUCTOR ***************/

Perceptron::~Perceptron()
{

}

/*************** PRIVATE ***************/


/**************** PUBLIC ***************/

void Perceptron::test() {
	printf("Coucou !\n");
}
