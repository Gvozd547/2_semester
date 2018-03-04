#include "library.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int mass[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2};

int threadEnd[] = {0, 0, 0};
int numberThreadRun;
int next;
number_thread number[3];
char first_string[30];
char second_string[30];

int main(int argc, char const *argv[]) {

  srand(time(NULL));
  for (size_t i = 0; i < sizeof(number); i++) {
    number[i].type_thread = i;
  }
  pthread_t read_first_string;
  pthread_create(&read_first_string, NULL, thread_read_or_write, (void *)&number[0]);
  pthread_t read_second_string;
  pthread_create(&read_second_string, NULL, thread_read_or_write, (void *)&number[1]);
  pthread_t write_first_string;
  pthread_create(&write_first_string, NULL, thread_read_or_write, (void *)&number[2]);
  numberThreadRun = mass[(rand() % 18)];
  printf("%s: ", "numberThreadRun");
  while (1) {
    if (numberThreadRun == 13) {
      while (1) {
        if ((threadEnd[0] == 1) && (threadEnd[1] == 1) && (threadEnd[1] == 1)) {
          printf("\nСимволы, прочитанные из файла 1: %s\n", first_string);
          printf("Символы, прочитанные из файла 2: %s\n", second_string);
          exit(0);
        }
        next = mass[(rand() % 20)];
        if ((next == 0) && (threadEnd[0] == 0)) {
          numberThreadRun = 0;
          printf(" %i", numberThreadRun);
          break;
        } else if ((next == 0) && (threadEnd[0] == 1) && (threadEnd[1] != 1)) numberThreadRun = 1;
        if ((next == 1) && (threadEnd[1] == 0)) {
          numberThreadRun = 1;
          printf(" %i", numberThreadRun);
          break;
        } else if ((next == 1) && (threadEnd[0] == 0) && (threadEnd[0] != 1)) numberThreadRun = 0;
        if (next == 2 && threadEnd[2] == 0) {
          numberThreadRun = 2;
          break;
        }
      }
    }
  }
  return 0;
}
