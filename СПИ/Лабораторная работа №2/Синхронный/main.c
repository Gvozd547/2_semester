/* Лабораторная работа № 2. Асинхронный конвеер */
#include "prototypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  int amount_of_number;
  int length_of_conveyor;
  int *status_conveyor;
  int *number_of_operations_in_cell;
  int result = 0;
  srand(time(NULL));

  puts("Cинхронный конвеер, количество тактов на единицу конвеера от 3 до 7 (const = 7)");
  puts("Введите количество обрабатываемых чисел: ");
  scanf("%i", &amount_of_number);
  puts("Введите длину конвеера");
  scanf("%i", &length_of_conveyor);

  status_conveyor = (int *)malloc(length_of_conveyor * sizeof(int));
  number_of_operations_in_cell =
      (int *)malloc(length_of_conveyor * sizeof(int));

  for (int i = 0; i < length_of_conveyor; i++) {
    status_conveyor[i] = 0;
    number_of_operations_in_cell[i] = 0;
  }

  status_conveyor[0] = 1;
  number_of_operations_in_cell[0] = 7;

  while (amount_of_number > 0) {
    conveyor(status_conveyor, number_of_operations_in_cell, length_of_conveyor,
             &amount_of_number);
    result += 1;
  }

  printf("Количество операций: %i\n", result);

  return 0;
}
