#include "libraries.h"

int main() {

  int number_modes;
  int number_combination;
  int **distance_matrix;
  int result;
  printf("--------------------------------\n");
  printf("Введите число узлов: ");
  scanf("%i", &number_modes);

  srand(time(NULL));

  number_combination = factorial(number_modes - 1);

  distance_matrix = (int **)malloc(number_modes * sizeof(int *));

  generation_matrix_distance(distance_matrix, number_modes);

  result = generation_combinations(number_modes, number_combination, distance_matrix);

  printf("--------------------------------\n");
  printf("Матрица расстояний\n");
  for (size_t i = 0; i < number_modes; i++) {
    printf("|");
    for (size_t j = 0; j < number_modes; j++) {
      printf("%i|", distance_matrix[i][j]);
    }
    printf("\n");
  }
  printf("--------------------------------\n");
  printf("Длина минимального пути: %i\n", result);
  printf("--------------------------------\n");

  return 0;
}
