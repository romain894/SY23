#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "matrix.h"

#define DEBUG
#define OPTIONNAL_CHECKS

class Perceptron
{
private:
  Matrix p;
  Matrix za;
  float e;

public:
  Perceptron(const Matrix& p, const Matrix& za, float e);
  ~Perceptron();

  Matrix compute();

};

#endif //PERCEPTRON_H
