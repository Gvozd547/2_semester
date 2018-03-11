#include "libraries.h"

int path_cal(int number_modes, int *sequence, int **distance_matrix) {
  int result = 0;
  int node;
  node = sequence[0];
  result += distance_matrix[0][node];
  node = sequence[number_modes - 2];
  result += distance_matrix[node][0];
  for (int i = 0; i < (number_modes - 2); i++) {
    result += distance_matrix[sequence[i]][sequence[i + 1]];
  }
  return result;
}
