#include "libraries.h"

void gen_y(mpz_t q, mpz_t *y) {
  gmp_randstate_t state;
  gmp_randinit_mt(state);
  gmp_randseed_ui(state, time(NULL));
  mpz_init(*y);
  mpz_urandomm(*y, state, q);
}

void gen_Y(mpz_t p, mpz_t g, mpz_t y, mpz_t *Y) {
  mpz_init(*Y);
  mpz_powm(*Y, g, y, p);
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

void gen_sb(mpz_t p, mpz_t X, mpz_t A, mpz_t d, mpz_t e, mpz_t b, mpz_t y,
            mpz_t q, mpz_t *sb) {
  mpz_t power_sb;
  mpz_inits(power_sb, *sb, 0);
  mpz_set(power_sb, y);
  mpz_addmul(power_sb, e, b);
  mpz_mod(power_sb, power_sb, q);
  mpz_powm(*sb, A, d, p);
  mpz_mul(*sb, X, *sb);
  mpz_mod(*sb, *sb, p);
  mpz_powm(*sb, *sb, power_sb, p);
}
