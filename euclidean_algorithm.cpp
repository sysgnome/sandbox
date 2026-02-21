#include "euclidean_algorithm.h"

int gcd(int a, int b) {
  if (a == 0) {
    return b;
  }

  return gcd(b % a, a);
}

int beta_gcd(int a, int b) {
  int tmp = a;

  if (a == 0) {
    return b;
  }

  a = b;
  b = tmp - (a * (tmp/a));

  return beta_gcd(a, b);
}
