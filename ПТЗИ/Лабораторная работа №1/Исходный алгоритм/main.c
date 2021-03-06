#include "libraries.h"
#include <inttypes.h>

uint64_t get_time() {
  uint32_t low, high;
  __asm__ __volatile__("rdtsc\n" : "=a"(low), "=d"(high));
  return ((uint64_t)high << 32) | low;
}

int main() {
  mpz_t p, g, x, y, X, Y, ka, kb;
  gen_p_g(1024, &p, &g);
  uint64_t start = get_time();
  gen_x_y(p, &x, &y);
  gen_X_Y(p, g, x, y, &X, &Y);
  gen_ka_kb(x, y, p, X, Y, &ka, &kb);
  uint64_t end = get_time();
  print_info(p, g, x, y, X, Y, ka, kb);
  printf("-----------------------------------------------------------------\n");
  printf("Время выболнения (в тактах) %" PRId64 "\n", (end - start));
  printf("-----------------------------------------------------------------\n");
  return 0;
}
