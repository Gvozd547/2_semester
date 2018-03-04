#include <stdio.h>
#include <stdlib.h>

void conveyor(int *status_conveyor, int *number_of_operations_in_cell,
              int length_of_conveyor, int *amount_of_number) {

  int size = (length_of_conveyor * 2 - 1);

  if ((status_conveyor[size - 1] == 1) &&
      (number_of_operations_in_cell[size - 1] == 1))
    *amount_of_number = *amount_of_number - 1;
  else if ((status_conveyor[size - 1] == 1) &&
           (number_of_operations_in_cell[size - 1] != 1)) {
    number_of_operations_in_cell[size - 1] =
        number_of_operations_in_cell[size - 1] - 1;
  }

  for (int i = (size - 2); i >= 0; i--) {

    if ((i % 2) != 0) {
      if ((status_conveyor[i] == 1) && (status_conveyor[i + 1] == 0)) {
        status_conveyor[i] = 0;
        status_conveyor[i + 1] = 1;
        number_of_operations_in_cell[i + 1] = rand() % 4 + 4;
      }
    }

    if ((i % 2) == 0) {
      if ((status_conveyor[i] == 1) && (status_conveyor[i + 1] == 0) &&
          (number_of_operations_in_cell[i] == 1)) {
        status_conveyor[i] = 0;
        status_conveyor[i + 1] = 1;
      } else if ((status_conveyor[i] == 1) &&
                 (number_of_operations_in_cell[i] != 1)) {
        number_of_operations_in_cell[i] = number_of_operations_in_cell[i] - 1;
      }
    }
  }

  if (status_conveyor[0] == 0) {
    status_conveyor[0] = 1;
    number_of_operations_in_cell[0] = rand() % 4 + 4;
  }
}
