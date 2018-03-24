#include "libraries.h"

/* Функция расчета штрафа для каждого нуля. После нахождения очередного нуля c
 * индексом [i][j], просматривается вся i строка и находится минимальный
 * элемент(сам ноль с индексом [i][j] не учитываетс). То же самое проедлывается
 * и для столбца с индексом [j]. Находится сумма этих 2-х минимальныйх чисел.
 * Если это число больше суммы другого кандидата, то теперь кандидатом
 * становится это число*/

void calc_fine(int size, double **matrix, int *index_i, int *index_j,
               int *res_fine) {

  double min_num_in_line = INFINITY;
  double min_num_in_col = INFINITY;
  int sum_fine_candidate;
  *res_fine = -1;
  for (size_t i = 1; i < size; i++) {
    for (size_t j = 1; j < size; j++) {
      // Поиск нуля
      if (matrix[i][j] == 0) {
        // Поиск min в строке
        for (size_t k = 1; k < size; k++) {
          if (k != j) {
            if (matrix[i][k] < min_num_in_line) {
              min_num_in_line = matrix[i][k];
            }
          }
        }
        // Поиск min в столбце
        for (size_t k = 1; k < size; k++) {
          if (k != i) {
            if (matrix[k][j] < min_num_in_col) {
              min_num_in_col = matrix[k][j];
            }
          }
        }
        sum_fine_candidate = min_num_in_line + min_num_in_col;
        min_num_in_line = INFINITY;
        min_num_in_col = INFINITY;
        // Сравнение нового кандидата с прошлыи
        if (sum_fine_candidate > (*res_fine)) {
          *index_i = matrix[i][0];
          *index_j = matrix[0][j];
          *res_fine = sum_fine_candidate;
        }
      }
    }
  }
}
