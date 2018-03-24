#include "libraries.h"

void printf_matrix(int size, double **matrix) {
  for (size_t i = 0; i < size; i++) {
    printf("|");
    for (size_t j = 0; j < size; j++) {
      if ((i == 0) && (j == 0)) {
        printf("   |");
      } else
        printf("%3.0f|", matrix[i][j]);
    }
    printf("\n");
  }
}
