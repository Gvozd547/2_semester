#include "library.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void *thread_read_or_write(void *args) {
  char readBufSymbol[2];
  number_thread *number = (number_thread *) args;
  int type_thread = number->type_thread;

  if (type_thread == 0) {
    FILE *in1_file = fopen("inFile1.txt", "r");
    while (1) {
      if (numberThreadRun == 0) {
        memset(readBufSymbol, 0, sizeof(readBufSymbol));
        if ((fgets(readBufSymbol, 2, in1_file) != NULL)) {
          if (readBufSymbol[0] != '\n') strcat(first_string, readBufSymbol);
          numberThreadRun = 13;
        } else {
          threadEnd[0] = 1;
          numberThreadRun = 13;
          break;
        }
      }
    }
    fclose(in1_file);
    pthread_exit(0);
  }

  if (type_thread == 1) {
    FILE *in2_file = fopen("inFile2.txt", "r");
    while (1) {
      if (numberThreadRun == 1) {
        memset(readBufSymbol, 0, sizeof(readBufSymbol));
        if ((fgets(readBufSymbol, 2, in2_file) != NULL)) {
          if (readBufSymbol[0] != '\n') strcat(second_string , readBufSymbol);
          numberThreadRun = 13;
        } else {
          threadEnd[1] = 1;
          numberThreadRun = 13;
          break;
        }
      }
    }
    fclose(in2_file);
    pthread_exit(0);
  }

  if (type_thread == 2) {
    while (1) {
      if (numberThreadRun == 2) {
        threadEnd[0] = 1;
        threadEnd[1] = 1;
        threadEnd[2] = 1;
        numberThreadRun = 13;
        break;
      }
    }
    pthread_exit(0);
  }
  pthread_exit(0);
}
