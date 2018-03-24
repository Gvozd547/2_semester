#include "libraries.h"

/* Выделение памяти под матрицу M1 и заполнение ее элемента из входной матрицы
 * без элементов i строки и j столбца. Добавление в новую матрицу INFINITY для
 * предотвращения поялвления цикла */

void copy_matrix_for_m1(int size, int index_i, int index_j, double **matrix_in,
                        double ***matrix_out) {
  // Определение индекса удаляемой строки по глобальному индексу
  for (size_t i = 1; i < size; i++) {
    if ((matrix_in[i][0]) == index_i) {
      index_i = i;
      break;
    }
  }
  // Определение индекса удаляемого столбца по глобальному индексу
  for (size_t j = 1; j < size; j++) {
    if ((matrix_in[0][j]) == index_j) {
      index_j = j;
      break;
    }
  }
  // Создание новой матрицы без i строки и j столбца
  malloc_for_matrix((size - 1), matrix_out);
  int new_i = 0;
  for (size_t i = 0; i < size; i++) {
    int new_j = 0;
    if (i != index_i) {
      for (size_t j = 0; j < size; j++) {
        if (j != index_j) {
          (*matrix_out)[new_i][new_j] = matrix_in[i][j];
          new_j++;
        }
      }
      new_i++;
    }
  }
  // Поиск и присваивание элементу INFINITY
  int index_i_inf = -1;
  int index_j_inf = -1;
  int have_inf;
  // Поиск строки, в которой нет INFINITY
  for (size_t i = 1; i < (size - 1); i++) {
    have_inf = 0;
    for (size_t j = 1; j < (size - 1); j++) {
      if (((*matrix_out)[i][j]) == INFINITY) {
        have_inf = 1;
      }
    }
    if (have_inf == 0) {
      index_i_inf = i;
      break;
    }
  }
  // Поиск столбца, в котором нет INFINITY
  for (size_t j = 1; j < (size - 1); j++) {
    have_inf = 0;
    for (size_t i = 1; i < (size - 1); i++) {
      if (((*matrix_out)[i][j]) == INFINITY) {
        have_inf = 1;
      }
    }
    if (have_inf == 0) {
      index_j_inf = j;
      break;
    }
  }
  // Пересечению присваивается INFINITY
  if ((index_i_inf != -1) && (index_j_inf != -1)) {
    (*matrix_out)[index_i_inf][index_j_inf] = INFINITY;
  }
}

/* Выделение памяти под матрицу M2 и заполнение ее элемента из входной матрицы
 * Добавление в новую матрицу INFINITY */

void copy_matrix_for_m2(int size, int index_i, int index_j, double **matrix_in,
                        double ***matrix_out) {
  // Определение индекса i элемента для INFINITY по глобальному индексу
  for (size_t i = 1; i < size; i++) {
    if ((matrix_in)[i][0] == index_i) {
      index_i = i;
      break;
    }
  }
  // Определение индекса j элемента для INFINITY по глобальному индексу
  for (size_t j = 1; j < size; j++) {
    if ((matrix_in)[0][j] == index_j) {
      index_j = j;
      break;
    }
  }
  // Создание новой матрицы с элементом [i][j] = INFINITY
  malloc_for_matrix(size, matrix_out);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++)
      (*matrix_out)[i][j] = matrix_in[i][j];
  }
  (*matrix_out)[index_i][index_j] = INFINITY;
}
