#include "libraries.h"

void gen_ka_kb(mpz_t x, mpz_t y, mpz_t p, mpz_t X, mpz_t Y, mpz_t *ka,
               mpz_t *kb) {
  mpz_inits(*ka, *kb, 0);
  mpz_powm(*ka, Y, x, p);
  mpz_powm(*kb, X, y, p);
}
