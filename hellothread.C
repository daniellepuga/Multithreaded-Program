// test
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *run(void *arg){
  int iteration = 0;
  char *string_to_print = arg;
  while(iteration < 5) {

    printf("%s%d\n", string_to_print, iteration);

    iteration++;

  }
  
  return NULL;
}

char *thread_1 = "thread 1: ";
char *thread_2 = "thread 2: ";

int main() {
  printf("Launching threads\n");
  pthread_t t1, t2;

  pthread_create(&t1, NULL, run, thread_1);
  pthread_create(&t2, NULL, run, thread_2);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Threads complete!");
}