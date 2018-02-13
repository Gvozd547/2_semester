#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

int main() {

  mpz_t prime;
  mpz_init(prime);
  mpz_set_ui(prime, 1);
  hgfdgf



    mpz_nextprime(prime, prime);
    printf("Простое число: %s\n", mpz_get_str(NULL,10,prime));

}
