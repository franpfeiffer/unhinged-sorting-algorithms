#include<stdio.h>

void stalin_sort(int arr[], int size){
    int last = arr[0];
    printf("%d ", last);

    for(int i = 1; i < size; i++){
        if(arr[i] >= last){
            printf("%d ", arr[i]);
            last = arr[i];
        }
    }
}

int main() {
    int arr[] = {7, 42, 13, 89, 5, 76, 21, 3, 58, 94, 11, 67, 29, 84, 37, 2, 71, 46, 18, 99, 54, 26, 63, 80, 15, 90, 33, 8, 72, 49};
    stalin_sort(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
