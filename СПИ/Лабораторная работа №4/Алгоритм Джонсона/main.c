#include "libraries.h"

typedef struct {
  int index_detail;
  int time_machine_1;
  int time_machine_2;
} time_proc;

int compare_one_group(const void *struct1, const void *struct2) {
  time_proc x1 = *((time_proc *)struct1);
  time_proc x2 = *((time_proc *)struct2);
  return x1.time_machine_1 - x2.time_machine_1;
}

int compare_second_group(const void *struct1, const void *struct2) {
  time_proc x1 = *((time_proc *)struct1);
  time_proc x2 = *((time_proc *)struct2);

  return x2.time_machine_2 - x1.time_machine_2;
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
  int num_one_group = 0;
  for (size_t i = 0; i < num_all_detail; i++) {
    if (all_detail[i].time_machine_1 <= all_detail[i].time_machine_2)
      num_one_group++;
  }
  clock_t start = clock();
  time_proc *detail_one_group =
      (time_proc *)malloc(num_one_group * sizeof(time_proc));
  time_proc *detail_second_group =
      (time_proc *)malloc((num_all_detail - num_one_group) * sizeof(time_proc));
  int k = 0;
  int l = 0;
  for (size_t i = 0; i < num_all_detail; i++) {
    if (all_detail[i].time_machine_1 <= all_detail[i].time_machine_2) {
      detail_one_group[k].index_detail = all_detail[i].index_detail;
      detail_one_group[k].time_machine_1 = all_detail[i].time_machine_1;
      detail_one_group[k].time_machine_2 = all_detail[i].time_machine_2;
      k++;
    } else {
      detail_second_group[l].index_detail = all_detail[i].index_detail;
      detail_second_group[l].time_machine_1 = all_detail[i].time_machine_1;
      detail_second_group[l].time_machine_2 = all_detail[i].time_machine_2;
      l++;
    }
  }
  qsort(detail_one_group, num_one_group, sizeof(time_proc), compare_one_group);
  qsort(detail_second_group, (num_all_detail - num_one_group),
        sizeof(time_proc), compare_second_group);
  for (size_t i = 0; i < num_all_detail; i++) {
    if (i < num_one_group) {
      all_detail[i].index_detail = detail_one_group[i].index_detail;
      all_detail[i].time_machine_1 = detail_one_group[i].time_machine_1;
      all_detail[i].time_machine_2 = detail_one_group[i].time_machine_2;
    } else {
      all_detail[i].index_detail =
          detail_second_group[i - num_one_group].index_detail;
      all_detail[i].time_machine_1 =
          detail_second_group[i - num_one_group].time_machine_1;
      all_detail[i].time_machine_2 =
          detail_second_group[i - num_one_group].time_machine_2;
    }
  }
  clock_t end = clock();
  double time_run = (double)((end - start) / (CLOCKS_PER_SEC / 1000000));
  printf("------------------------------------------\n");
  printf("Time run %.6f\n", time_run / 1000000);
  printf("------------------------------------------\n");
  return 0;
}
