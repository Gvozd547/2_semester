#include "libraries.h"

void gen_x_y(mpz_t p, mpz_t *x, mpz_t *y) {
  gmp_randstate_t state;
  gmp_randinit_mt(state);
  gmp_randseed_ui(state, time(NULL));
  mpz_inits(*x, *y, 0);
  mpz_urandomm(*x, state, p);
  mpz_urandomm(*y, state, p);
}
