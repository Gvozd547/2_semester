#include "libraries.h"

int main() {
  mpz_t p, g, q, t, a, b, A, B, x, y, X, Y, d, e, sa, sb;
  gen_p_q_g_t(1024, 256, &p, &q, &g, &t);
  gen_a_b(q, &a, &b);
  gen_A_B(q, g, a, b, &A, &B);
  gen_x_y(q, &x, &y);
  gen_X_Y(q, g, x, y, &X, &Y);
  gen_d_e(256, X, Y, &d, &e);
  gen_sa_sb(X, Y, A, B, d, e, a, b, x, y, q, &sa, &sb);
  print_info(p, g, q, t,x,y, X, Y,a, b, A, B, d, e, sa, sb);
  return 0;
}
