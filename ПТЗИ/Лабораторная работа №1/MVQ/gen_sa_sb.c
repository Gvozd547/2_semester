#include "libraries.h"

void gen_sa_sb(mpz_t p ,mpz_t X, mpz_t Y, mpz_t A, mpz_t B, mpz_t d, mpz_t e, mpz_t a,
               mpz_t b, mpz_t x, mpz_t y, mpz_t q, mpz_t *sa,
               mpz_t *sb) {
  mpz_t power_sa, power_sb;
  mpz_inits(power_sb, power_sa, *sa, *sb, 0);
  mpz_set(power_sa, x);
  mpz_addmul(power_sa, d, a);
  mpz_mod(power_sa, power_sa, q);
  mpz_powm(*sa, B, e, p);
  mpz_mul(*sa, Y, *sa);
  mpz_mod(*sa, *sa, p);
  mpz_powm(*sa, *sa, power_sa, p);
  mpz_set(power_sb, y);
  mpz_addmul(power_sb, e, b);
  mpz_mod(power_sb, power_sb, q);
  mpz_powm(*sb, A, d, p);
  mpz_mul(*sb, X, *sb);
  mpz_mod(*sb, *sb, p);
  mpz_powm(*sb, *sb, power_sb, p);
}
