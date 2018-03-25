#include "libraries.h"

void gen_x(mpz_t q, mpz_t *x) {
  gmp_randstate_t state;
  gmp_randinit_mt(state);
  gmp_randseed_ui(state, time(NULL));
  mpz_init(*x);
  mpz_urandomm(*x, state, q);
}

void gen_X(mpz_t p, mpz_t g, mpz_t x, mpz_t *X) {
  mpz_init(*X);
  mpz_powm(*X, g, x, p);
}

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

void gen_sa(mpz_t p, mpz_t Y, mpz_t B, mpz_t e, mpz_t d, mpz_t a, mpz_t x,
            mpz_t q, mpz_t *sa) {
  mpz_t power_sa;
  mpz_inits(power_sa, *sa, 0);
  mpz_set(power_sa, x);
  mpz_addmul(power_sa, d, a);
  mpz_mod(power_sa, power_sa, q);
  mpz_powm(*sa, B, e, p);
  mpz_mul(*sa, Y, *sa);
  mpz_mod(*sa, *sa, p);
  mpz_powm(*sa, *sa, power_sa, p);
}
