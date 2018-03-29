#include "libraries.h"

int path_cal(int number_modes, int *sequence, int **distance_matrix) {
  int result = 0;
  for (int i = 0; i < (number_modes - 1); i++) {
    result += distance_matrix[sequence[i]][sequence[i + 1]];
  }
  result += distance_matrix[sequence[number_modes - 1]][sequence[0]];
  return result;
}
