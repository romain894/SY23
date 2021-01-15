#ifndef PERCEPTRON_H
#define PERCEPTRON_H

//Romain THOMAS 2021
//V1.0

#include "matrix.h"

#define DEBUG
//#define OPTIONNAL_CHECKS

class Perceptron
{
private:
  Matrix p;
  Matrix za;
  double e;

public:
  Perceptron(Matrix p, Matrix za, double e);
  ~Perceptron();

  Matrix compute();

};

#endif //PERCEPTRON_H
