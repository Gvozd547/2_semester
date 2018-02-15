#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


char readBufSimbol[2];
char endString1[1000];
char endString2[1000];
int count;
int finish1 = 0;
int finish2 = 0;

void* thread1(void *args){
  char *check;
  FILE *in1_file = fopen("inFile1.txt", "r");
	while(1){
		if (count == 1){
      check = fgets(readBufSimbol,2,in1_file);
      strcat(endString1,readBufSimbol);
      memset(readBufSimbol,0, sizeof(readBufSimbol));
      count = 2;
    }
    if (check == NULL){
      fclose(in1_file);
      finish1 = 1;
      puts("Первый поток посимвольного чтения из файла завершился.");
      pthread_exit(0);
    }
  }
  fclose(in1_file);
}

void* thread2(void *args){
  char *check;
	FILE *in2_file = fopen("inFile2.txt", "r");
	while(1){
    if (count == 2){
      check = fgets(readBufSimbol,2,in2_file);
      strcat(endString2,readBufSimbol);
      memset(readBufSimbol,0, sizeof(readBufSimbol));
      count = 1;
    }
    if (check == NULL){
      fclose(in2_file);
      finish2 = 1;
      puts("Второй поток посимвольного чтения из файла завершился.");
      pthread_exit(0);
    }
  }
	fclose(in2_file);
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  count = rand() % 1 + 1;
  pthread_t newThread1;
  pthread_t newThread2;
  pthread_create(&newThread1,NULL,thread1,NULL);
  pthread_create(&newThread2,NULL,thread2,NULL);
  while(1){
	  if ((finish1 == 1) && (finish2 == 1)) break;
  }
  sleep(1);
  printf("Символы из 1 файла: %s",endString1);
  printf("Символы из 2 файла: %s",endString2);
  return 0;
}
