#include "libraries.h"

int generation_combinations(int number_modes, int number_combination,
                            int **distance_matrix) {
  int *buffer, *sequence, left, right, position1, position2, result, buf_result;
  sequence = (int *)malloc(number_modes * sizeof(int));
  buffer = (int *)malloc(number_modes * sizeof(int));
  for (int i = 0; i < number_modes; i++)
    sequence[i] = i;
  result = path_cal(number_modes, sequence, distance_matrix);
  int count = 1;
  while (count < number_combination) {
    for (int i = 0; i < number_modes; i++) {
      buffer[i] = sequence[i];
    }
    position1 = number_modes - 2;
    while (buffer[position1] > buffer[position1 + 1])
      position1--;
    position2 = number_modes - 1;
    while (buffer[position2] < buffer[position1])
      position2--;
    swap(position1, position2, buffer);
    left = position1 + 1;
    right = number_modes - 1;
    while (left < right) {
      swap(left, right, buffer);
      left++;
      right--;
    }
    for (int i = 0; i < number_modes; i++)
      sequence[i] = buffer[i];
    buf_result = path_cal(number_modes, sequence, distance_matrix);
    if (buf_result < result)
      result = buf_result;
    count++;
  }
  free(buffer);
  return result;
}
