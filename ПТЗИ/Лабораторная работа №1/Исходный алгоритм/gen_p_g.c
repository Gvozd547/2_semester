#include "libraries.h"

void gen_p_g(int size, mpz_t *p, mpz_t *g) {
  char *buf;
  mpz_t q, t;
  mpz_inits(q, *p, *g, t, 0);
  size = size / 8;
  buf = (char *)malloc(size * sizeof(char));
  srand(time(0));
  do {
    for (size_t i = 0; i < size; i++)
      buf[i] = rand();
    buf[0] &= 0x7f;
    buf[0] |= 0x40;
    mpz_import(q, size, 1, 1, 0, 0, buf);
    mpz_nextprime(q, q);
    mpz_mul_ui(*p, q, 2);
    mpz_add_ui(*p, *p, 1);
  } while (!mpz_probab_prime_p(*p, 25));
  mpz_set_ui(*g, 1);
  do {
    mpz_add_ui(*g, *g, 1);
    mpz_powm(t, *g, q, *p);
  } while (!mpz_cmp_ui(t, 1));
  free(buf);
}
