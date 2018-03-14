#include "libraries.h"

void gen_p_q_g_t(int size_p, int size_q, mpz_t *p, mpz_t *q, mpz_t *g,
                 mpz_t *t) {
  char *buf_t_, *buf_q;
  int r = 2;
  mpz_t r_mpz;
  int size_t_ = size_p - size_q;
  mpz_inits(*p, *q, *g, *t, r_mpz, 0);
  size_t_ /= 8;
  size_q /= 8;
  srand(time(0));
  buf_t_ = (char *)malloc(size_t_ * sizeof(char));
  buf_q = (char *)malloc(size_q * sizeof(char));
  do {
    for (int i = 0; i < size_t_; i++)
      buf_t_[i] = rand();
    buf_t_[0] |= 0x80;
    for (int i = 0; i < size_q; i++)
      buf_q[i] = rand();
    buf_q[0] |= 0x80;
    mpz_import(*t, size_t_, 1, 1, 0, 0, buf_t_);
    mpz_import(*q, size_q, 1, 1, 0, 0, buf_q);
    mpz_nextprime(*q, *q);
    mpz_mul(*p, *q, *t);
    mpz_add_ui(*p, *p, 1);
  } while (!mpz_probab_prime_p(*p, 25));
  while (1) {
    mpz_set_ui(r_mpz, r);
    mpz_powm(*g, r_mpz, *t, *p);
    if (mpz_cmp_ui(*g, 1) > 0) {
      break;
    }
  }
  free(buf_t_);
  free(buf_q);
}
