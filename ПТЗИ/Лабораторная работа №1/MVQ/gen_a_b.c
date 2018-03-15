#include "libraries.h"

void gen_a_b(mpz_t q, mpz_t *a, mpz_t *b) {
  gmp_randstate_t state_2;
  gmp_randinit_mt(state_2);
  gmp_randseed_ui(state_2, time(NULL));
  mpz_inits(*a, *b, 0);
  mpz_urandomm(*a, state_2, q);
  mpz_urandomm(*b, state_2, q);
  sleep(1);
}
