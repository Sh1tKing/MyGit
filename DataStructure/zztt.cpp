#include <stdio.h>
int main() {
    int n;

    printf("Input n(n<=10):\n");
    scanf("%d", &n);
    int arr[5];
    printf("Input %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max_idx = 0, min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }

    int temp = arr[max_idx];
    arr[max_idx] = arr[min_idx];
    arr[min_idx] = temp;

    printf("Exchange results:");
    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");

    return 0;
}