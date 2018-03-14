#include "libraries.h"

int main() {
  mpz_t p, g, q, t, x, y, X, Y, ka, kb;
  gen_p_q_g_t(1024, 256, &p, &q, &g, &t);
  gen_x_y(q, &x, &y);
  gen_X_Y(p, g, x, y, &X, &Y);
  gen_ka_kb(x, y, p, X, Y, &ka, &kb);
  print_info(p, g, q, t, x, y, X, Y, ka, kb);
  return 0;
}
