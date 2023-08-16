#include <stdio.h>

int binarySearch(int *arr, int size, int eliment){
    int low = 0, high = size - 1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == eliment)
            return mid;
        else if(arr[mid] < eliment)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int arr[10] = {2, 5, 6, 7, 9, 12, 15, 17, 20, 24};
    int eliment, size = sizeof(arr)/sizeof(int);
    printf("Enter the eliment to be find: ");
    scanf("%d", &eliment);
    int d = binarySearch(arr, size, eliment);
    if(d == -1)
        printf("%d is not found!!", eliment);
    else
        printf("%d is in the %dth position!!", eliment, d);
    return 0;
}