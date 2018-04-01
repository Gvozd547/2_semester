#include "libraries.h"

typedef struct {
  int index_detail;
  int time_machine_1;
  int time_machine_2;
} time_proc;

double max(double a, double b) { return a > b ? a : b; }

int factorial(int number) {
  if (number <= 1) {
    return 1;
  } else
    return number * factorial(number - 1);
}

void swap(int position1, int position2, int *mass) {
  int buf;
  buf = mass[position1];
  mass[position1] = mass[position2];
  mass[position2] = buf;
}

int main() {
  srand(time(NULL));
  int num_all_detail;
  printf("Введите кол-во деталей: ");
  scanf("%i", &num_all_detail);
  time_proc *all_detail =
      (time_proc *)malloc(num_all_detail * sizeof(time_proc));
  for (size_t i = 0; i < num_all_detail; i++) {
    all_detail[i].index_detail = i + 1;
    all_detail[i].time_machine_1 = rand() % 9 + 1;
    all_detail[i].time_machine_2 = rand() % 9 + 1;
  }
  clock_t start = clock();
  int *sequence = (int *)malloc(num_all_detail * sizeof(int));
  int *buffer = (int *)malloc(num_all_detail * sizeof(int));
  for (int i = 0; i < num_all_detail; i++)
    sequence[i] = i;
  int t1 = 0;
  int t2 = 0;
  int price = 0;
  for (size_t i = 0; i < num_all_detail; i++) {
    t1 += all_detail[sequence[i]].time_machine_1;
    t2 = max(t2, t1) + all_detail[sequence[i]].time_machine_2;
  }
  price = t2;
  int position1, position2, left, right;
  int number_combination = factorial(num_all_detail);
  int count = 0;
  while (count < number_combination) {
    for (int i = 0; i < num_all_detail; i++) {
      buffer[i] = sequence[i];
    }
    position1 = num_all_detail - 2;
    while (buffer[position1] > buffer[position1 + 1])
      position1--;
    position2 = num_all_detail - 1;
    while (buffer[position2] < buffer[position1])
      position2--;
    swap(position1, position2, buffer);
    left = position1 + 1;
    right = num_all_detail - 1;
    while (left < right) {
      swap(left, right, buffer);
      left++;
      right--;
    }
    for (int i = 0; i < num_all_detail; i++)
      sequence[i] = buffer[i];
    t1 = 0;
    t2 = 0;
    for (size_t i = 0; i < num_all_detail; i++) {
      t1 += all_detail[sequence[i]].time_machine_1;
      t2 = max(t2, t1) + all_detail[sequence[i]].time_machine_2;
    }
    if (t2 < price) {
      price = t2;
    }
    count++;
  }
  clock_t end = clock();
  double time_run = (double)((end - start) / (CLOCKS_PER_SEC / 1000000));
  printf("------------------------------------------\n");
  printf("Time run %.6f\n", time_run / 1000000);
  printf("------------------------------------------\n");
  return 0;
}
