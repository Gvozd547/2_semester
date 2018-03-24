#include "libraries.h"

void generation_matrix_distance(int **matrix_path, int number_nodes) {
  for (int i = 0; i < number_nodes; i++) {
    matrix_path[i] = malloc(number_nodes * sizeof(int));
  }
  for (int i = 0; i < number_nodes; i++) {
    for (int j = 0; j < number_nodes; j++) {
      if (i != j) {
        matrix_path[i][j] = rand() % 5 + 1;
      } else
        matrix_path[i][j] = 0;
    }
  }
}
