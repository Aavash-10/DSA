
//Insertion Sort

#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {

        // current index is minimum
        minIndex = i;

        // Search for minimum element in rest of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for(i=0;i<n;i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {5,2,9,1,6};
    int n =5;

    printf("Original array:\n");
    printArray(arr,n);

    selectionSort(arr,n);

    printf("Sorted array:\n");
    printArray(arr,n);

    return 0;
}