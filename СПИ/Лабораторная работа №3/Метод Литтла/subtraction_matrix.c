#include "libraries.h"

/*Для каждой строки находится минимальное число с последующим вычитанием из всех
 * элементов этой строки этого числа. То же самое проделывается и для столбцов.
 * Все минимальны числа по мтрокам и столбцам суммируются */

int subtraction_matrix(int size, double **matrix) {
  double min_number_candidate = INFINITY;
  int sum_final_candidates = 0;
  // Уменьшение по строкам
  for (size_t i = 1; i < size; i++) {
    for (size_t j = 1; j < size; j++) {
      if (matrix[i][j] < min_number_candidate)
        min_number_candidate = matrix[i][j];
    }
    sum_final_candidates += min_number_candidate;
    for (size_t k = 1; k < size; k++)
      matrix[i][k] = matrix[i][k] - min_number_candidate;
    min_number_candidate = INFINITY;
  }
  // Уменьшение по столбцам
  for (size_t j = 1; j < size; j++) {
    for (size_t i = 1; i < size; i++) {
      if (matrix[i][j] < min_number_candidate)
        min_number_candidate = matrix[i][j];
    }
    sum_final_candidates += min_number_candidate;
    for (size_t k = 1; k < size; k++)
      matrix[k][j] = matrix[k][j] - min_number_candidate;
    min_number_candidate = INFINITY;
  }
  return sum_final_candidates;
}
