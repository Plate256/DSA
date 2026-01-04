#include <stdio.h>

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify (int array[], int size, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < size && array[l] > array[largest]){
        largest = l;
    }
    if (r < size && array[r] > array[largest]){
        largest = r;
    }
    
    if (largest != i){
        swap (&array[i], &array[largest]);
        heapify (array, size, largest);
    }
}

void heapsort (int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify (arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--){
        swap (&arr[0], &arr[i]);
        heapify (arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  

int main (){
     int arr[] = {12, 6, 10, 5, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    heapsort(arr, n);
    printArray(arr, n);
}