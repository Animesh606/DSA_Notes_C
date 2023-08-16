#include <stdio.h>

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubblesort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if(arr[j+1] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubblesortadaptive(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int isSorted = 1;
        for (int j = 0; j < n - i - 1; j++){
            if(arr[j+1] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted)
            return;
    }
}

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--){
            if(arr[j] > key)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int index = i;
        for (int j = i + 1; j < n; j++){
            if(arr[j] < arr[index]){
                index = j;
            }
        }
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {5, 0, 2, 4, 7, 9};
    int n = sizeof(arr)/sizeof(int);
    printArray(arr, n);
    // bubblesort(arr, n);
    // printArray(arr, n);
    // bubblesortadaptive(arr, n);
    // printArray(arr, n);
    // insertionSort(arr, n);
    // printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}