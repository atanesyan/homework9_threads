#include <stdio.h>
#include <pthread.h>

#define SIZE 6
int arr[SIZE] = {1, 2, 3, 4, 5, 6};

struct ThreadData {
  int start;
  int end;
};

void* sum_part(void* arg) {
  struct ThreadData* data = arg;
  int sum = 0;
  for (int i = data->start; i < data->end; ++i) {
    sum += arr[i];
  }
  printf("Partial sum (%d to %d) = %d\n", data->start, data->end - 1, sum);
  return NULL;
}

int main(void) {
  pthread_t t1, t2;
  struct ThreadData d1 = {0, SIZE / 2};
  struct ThreadData d2 = {SIZE / 2, SIZE};

  if (pthread_create(&t1, NULL, sum_part, &d1) != 0 ||
    pthread_create(&t2, NULL, sum_part, &d2) != 0) {
    perror("pthread_create");
    return 1;
  }

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Both threads completed.\n");
  return 0;
}
