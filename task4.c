#include <stdio.h>
#include <pthread.h>

#define SIZE 5
int numbers[SIZE] = {1, 2, 3, 4, 5};

void* compute_square(void* arg) {
  int n = *(int*)arg;
  printf("Square of %d is %d\n", n, n * n);
  return NULL;
}

int main(void) {
  pthread_t threads[SIZE];

  for (int i = 0; i < SIZE; ++i) {
    if (pthread_create(&threads[i], NULL, compute_square, &numbers[i]) != 0) {
      perror("pthread_create");
      return 1;
      }
  }

  for (int i = 0; i < SIZE; ++i) {
    pthread_join(threads[i], NULL);
  }

  printf("All squares computed.\n");
  return 0;
}
