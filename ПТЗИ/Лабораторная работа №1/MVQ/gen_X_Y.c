#include "libraries.h"

void gen_X_Y(mpz_t p, mpz_t g, mpz_t x, mpz_t y, mpz_t *X, mpz_t *Y) {
  mpz_inits(*X, *Y, 0);
  mpz_powm(*X, g, x, p);
  mpz_powm(*Y, g, y, p);
}
