#include "libraries.h"

void gen_sa_sb(mpz_t X, mpz_t Y, mpz_t A, mpz_t B, mpz_t d, mpz_t e, mpz_t a,
               mpz_t b, mpz_t x, mpz_t y, mpz_t q, mpz_t *sa,
               mpz_t *sb) {
  mpz_t power_sa, power_sb;
  mpz_inits(power_sb, power_sa, *sa, *sb, 0);

  mpz_powm(*sa, B, e, q);
  mpz_mul(*sa, Y, *sa);
  mpz_mul(power_sa, d, a);
  mpz_add(power_sa, power_sa, x);
  mpz_powm(*sa, *sa, power_sa, q);

  mpz_powm(*sb, A, d, q);
  mpz_mul(*sb, X, *sb);
  mpz_mul(power_sb, e, b);
  mpz_add(power_sb, power_sb, y);
  mpz_powm(*sb, *sb, power_sb, q);
}
