#include "libraries.h"

void gen_A_B(mpz_t q, mpz_t g, mpz_t a, mpz_t b, mpz_t *A, mpz_t *B) {
  mpz_inits(*A, *B, 0);
  mpz_powm(*A, g, a, q);
  mpz_powm(*B, g, b, q);
}
