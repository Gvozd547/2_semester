#include "libraries.h"

int generation_combinations(int number_modes, int number_combination,
                            int **distance_matrix) {
  int *buffer, *sequence, left, right, position1, position2, result, buf_result;
  int count = 0;
  sequence = (int *)malloc((number_modes - 1) * sizeof(int));
  buffer = (int *)malloc((number_modes - 1) * sizeof(int));
  for (int i = 0; i < (number_modes - 1); i++)
    sequence[i] = i + 1;
  result = path_cal(number_modes, sequence, distance_matrix);
  while (count < (number_combination - 1)) {
    for (int i = 0; i < (number_modes - 1); i++) {
      buffer[i] = sequence[i];
    }
    position1 = number_modes - 3;
    while (buffer[position1] > buffer[position1 + 1])
      position1--;
    position2 = number_modes - 2;
    while (buffer[position2] < buffer[position1])
      position2--;
    swap(position1, position2, buffer);
    left = position1 + 1;
    right = number_modes - 2;
    while (left < right) {
      swap(left, right, buffer);
      left++;
      right--;
    }
    for (int i = 0; i < number_modes - 1; i++)
      sequence[i] = buffer[i];
    buf_result = path_cal(number_modes, sequence, distance_matrix);
    if (buf_result < result)
      result = buf_result;
    count++;
  }
  free(buffer);
  return result;
}
