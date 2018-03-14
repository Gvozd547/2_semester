#include "libraries.h"

int main() {
  mpz_t p, g, x, y, X, Y, ka, kb;
  gen_p_g(1024, &p, &g);
  gen_x_y(p, &x, &y);
  gen_X_Y(p, g, x, y, &X, &Y);
  gen_ka_kb(x, y, p, X, Y, &ka, &kb);
  print_info(p, g, x, y, X, Y, ka, kb);
  return 0;
}
