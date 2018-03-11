#include "libraries.h"

void swap(int position1, int position2, int *mass) {
  int buf;
  buf = mass[position1];
  mass[position1] = mass[position2];
  mass[position2] = buf;
}
