#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
  long id = (long)arg;
  printf("Thread %ld is running\n", id);
  return NULL;
}

int main(void) {
  pthread_t threads[3];

  for (long i = 0; i < 3; ++i) {
    if (pthread_create(&threads[i], NULL, thread_func, (void*)i) != 0) {
      perror("pthread_create");
      return 1;
    }
  }

  for (int i = 0; i < 3; ++i) {
    pthread_join(threads[i], NULL);
  }

  printf("All threads have finished.\n");
  return 0;
}
