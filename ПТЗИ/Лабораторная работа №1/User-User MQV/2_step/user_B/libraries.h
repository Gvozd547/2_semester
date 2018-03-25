#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <gmp.h>

void gen_y(mpz_t q, mpz_t *y);
void gen_Y(mpz_t p, mpz_t g, mpz_t y, mpz_t *Y);
void gen_d_e(int size_q, mpz_t X, mpz_t Y, mpz_t *d, mpz_t *e);
void gen_sb(mpz_t p, mpz_t X, mpz_t A, mpz_t d, mpz_t e, mpz_t b, mpz_t y,
            mpz_t q, mpz_t *sb);
