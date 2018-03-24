#include "libraries.h"

/* Рекурсия для поиска кратчайшего пути. Суть заключается в первичном нахождение
 * начения пути через ветви, которые содержат i,j ребро(на каждом шагу
 * удаляется строка и столбец) из исходной матрицы. После достижения
 * минимального рармера матрицы, получаем первый возможный правельный вариант.
 * Затем идет обратная раскрутка с проверкой варианта, когда искомый
 * маршрут не содержит ребро i,j. В случае, если альтернатива выходит дороже
 * первично найденного пути, поиск по этой ветви прекращается */

void recursion(double *record, int limit, int size, double **matrix) {
  int limit_m1, limit_m2;
  limit_m1 = limit_m2 = limit;
  // Нахождения штрафа и глобальные индексы, соответствующие этому элементу;
  int index_i, index_j, res_fine;
  calc_fine(size, matrix, &index_i, &index_j, &res_fine);
  // Создание 2-х копий матрицы и обработка их для варианта M1 и M2
  double **matrix_m1, **matrix_m2;
  copy_matrix_for_m1(size, index_i, index_j, matrix, &matrix_m1);
  copy_matrix_for_m2(size, index_i, index_j, matrix, &matrix_m2);
  free(matrix);
  // Расчет стоимости для варината M1
  if ((size - 1) > 3)
    limit_m1 += subtraction_matrix((size - 1), matrix_m1);
  // Прекращение рекурсии по варианту M1
  if (((size - 1) > 3) && (limit_m1 <= *record))
    recursion(record, limit_m1, (size - 1), matrix_m1);
  // Обновление результата
  if ((size - 1) == 3 && (limit_m1 < *record))
    *record = limit_m1;
  // Расчет стоимости для варината M2
  limit_m2 = limit_m2 + res_fine;
  subtraction_matrix(size, matrix_m2);
  // Прекращение рекурсии по варианту M2
  if (((size - 1) > 3) && (limit_m2 <= *record))
    recursion(record, limit_m2, size, matrix_m2);
}
