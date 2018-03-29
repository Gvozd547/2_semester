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
  number_combination = factorial(number_modes);
  distance_matrix = (int **)malloc(number_modes * sizeof(int *));
  generation_matrix_distance(distance_matrix, number_modes);
  clock_t start = clock();
  result = generation_combinations(number_modes, number_combination,
                                   distance_matrix);
  clock_t end = clock();
  double time_run = (double)((end - start) / (CLOCKS_PER_SEC / 1000000));
  printf("--------------------------------\n");
  printf("Tour length: %i\n", result);
  printf("Time run %.8f\n", time_run / 1000000);
  printf("--------------------------------\n");
  return 0;
}
