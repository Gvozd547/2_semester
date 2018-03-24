#include "libraries.h"

/* Выделение памяти под квадратную матрицу */

void malloc_for_matrix(int size, double ***matrix) {
  *matrix = (double **)malloc(size * sizeof(double *));
  for (size_t i = 0; i < size; i++) {
    (*matrix)[i] = (double *)malloc(size * sizeof(double));
  }
}
