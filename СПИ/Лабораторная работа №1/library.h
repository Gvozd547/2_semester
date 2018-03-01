void* thread_read_or_write(void *args);
void threadStatusPrint();

typedef struct {
  int type_thread;
} number_thread;

extern char first_string[];
extern char second_string[];
extern int threadStart[];
extern int threadEnd[];
extern int numberThreadRun;
