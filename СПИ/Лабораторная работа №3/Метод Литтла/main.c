#include "libraries.h"

/* Программа, реализующая алгоритм Литтла(поиск кратчайшего пути обхода N
 * городов) */

int main() {
  double record = INFINITY;
  double **distance_matrix;
  int limit = 0;
  int num_node;
  printf("--------------------------------\n");
  printf("Введите количество узлов: ");
  scanf("%i", &num_node);
  gen_matrix_distance(num_node, &distance_matrix);
  if (num_node < 16) {
    printf("--------------------------------\n");
    printf("Исходная матрица переходов\n");
    printf_matrix((num_node + 1), distance_matrix);
  }
  clock_t start = clock();
  // Минимально возможный путь
  limit += subtraction_matrix((num_node + 1), distance_matrix);
  // Рекурсия по ветвям
  recursion(&record, limit, (num_node + 1), distance_matrix);
  clock_t end = clock();
  double time_run = (double)((end - start) / (CLOCKS_PER_SEC / 1000000));
  // Вывод результата
  printf("--------------------------------\n");
  printf("Tour length: %.0f\n", record);
  printf("Time run %.8f\n", time_run / 1000000);
  printf("--------------------------------\n");
  return 0;
}
