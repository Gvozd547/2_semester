#include "libraries.h"

/* Выделение памяти для маршрутной матрицы и заполенние ее рандомными значениями
 * Нулевая строка и нулевой столбец заполняются значениями глобальных индексов
 */

void gen_matrix_distance(int size, double ***matrix) {
  srand(time(NULL));
  malloc_for_matrix((size + 1), matrix);
  for (size_t i = 1; i < (size + 1); i++) {
    for (size_t j = 1; j < (size + 1); j++) {
      if (i != j)
        (*matrix)[i][j] = rand() % 100 + 1;
      else
        (*matrix)[i][j] = INFINITY;
    }
  }
  for (size_t i = 1; i < (size + 1); i++)
    (*matrix)[i][0] = i - 1;
  for (size_t j = 1; j < (size + 1); j++)
    (*matrix)[0][j] = j - 1;
}
