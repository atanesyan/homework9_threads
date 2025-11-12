#include <stdio.h>
#include <pthread.h>

void* print_numbers(void* arg) {
  long id = (long)arg;
  for (int i = 1; i <= 5; ++i) {
    printf("Thread %ld: %d\n", id, i);
  }
  return NULL;
}

int main(void) {
  pthread_t threads[3];

  for (long i = 0; i < 3; ++i) {
    if (pthread_create(&threads[i], NULL, print_numbers, (void*)i) != 0) {
      perror("pthread_create");
        return 1;
      }
  }

  for (int i = 0; i < 3; ++i) {
    pthread_join(threads[i], NULL);
  }

  printf("All threads finished printing numbers.\n");
  return 0;
}
