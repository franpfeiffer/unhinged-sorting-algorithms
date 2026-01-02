#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *sleep_and_print(void *arg) {
    int num = *((int *)arg);
    sleep(num);
    printf("%d ", num);
    free(arg);

    return NULL;
}

void sleep_sort(int arr[], int n) {
    pthread_t threads[n];
    for (int i = 0; i < n; i++) {
        int *arg = malloc(sizeof(*arg));
        if (arg == NULL) {
            perror("skill issue");
            exit(EXIT_FAILURE);
        }
        if (pthread_create(&threads[i], NULL, sleep_and_print, arg) != 0) {
            perror("creating the thread failed miserably");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    int arr[] = {5, 3, 1, 4, 2, 8, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("this might take a while...\n");

    printf("sorted array: ");
    sleep_sort(arr, n);

    return 0;
}
