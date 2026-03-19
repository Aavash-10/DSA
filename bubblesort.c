//Bubble sort

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    // passes = 1,2,3,4,5
    for (i = 0; i < n - 1; i++) {

        // Comparisons
        for (j = 0; j < n - i - 1; j++) {

            // Swap elements are in wrong order
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// print array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 9, 1, 6};
    int n = 5;

    printf("Original array:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
