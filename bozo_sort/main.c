#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool is_sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void swap(int *a, int *b) {
    if (a == b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void bozo_sort(int arr[], int n) {
    while (!is_sorted(arr, n)) {
        int i = rand() % n;
        int j = rand() % n;
        swap(&arr[i], &arr[j]);
    }
}

int main() {
    int arr[] = {2, 1, 3, 8, 3, 7, 67, 420};

    int n = sizeof(arr) / sizeof(arr[0]);
    srand(time(NULL));

    bozo_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
