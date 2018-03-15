#include "libraries.h"

void gen_d_e(int size_q, mpz_t X, mpz_t Y, mpz_t *d, mpz_t *e) {
  mpz_inits(*d, *e, 0);
  mpz_set(*d, X);
  mpz_set(*e, Y);
  for (size_t i = 126; i < size_q * 4; i++) {
    mpz_clrbit(*d, i);
    mpz_clrbit(*e, i);
  }
  mpz_setbit(*d, (size_q / 2)-1);
  mpz_setbit(*e, (size_q / 2)-1);
}
