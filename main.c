#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// Prototypes for the sorting algorithms
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);

// Prototypes for helper functions
int partition(int arr[], int low, int high);
void copyArray(int arr[], int arr2[], int n);
void printArray(int arr[], int n);

int main(){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    // Time start
    int n, i;

    // Read in the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Create an array of size n and read in the elements
    int arr[n], arr2[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // Print the sorted array using each sorting algorithm
    // Bubble Sort
    copyArray(arr, arr2, n);
    printf("\nSorted array using Bubble Sort algorithm: \n");
    bubbleSort(arr2, n);
    printArray(arr2, n);
    
    // Selection Sort
    copyArray(arr, arr2, n);
    printf("\nSorted array using Selection Sort algorithm: \n");
    selectionSort(arr2, n);
    printArray(arr2, n);

    // Insertion Sort
    copyArray(arr, arr2, n);
    printf("\nSorted array using Insertion Sort algorithm: \n");
    insertionSort(arr2, n);
    printArray(arr2, n);

    // Quick Sort
    copyArray(arr, arr2, n);
    printf("\nSorted array using Quick Sort algorithm: \n");
    quickSort(arr2, 0, n-1);
    printArray(arr2, n);
    
    // Time end
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nProgram took %f seconds to execute \n", cpu_time_used);

    return 0;
}

// Bubble Sort Algorithm
void bubbleSort(int arr[], int n){
    int i, j, swap;
    bool swapped;

    // Iterate through the array
    for (i = 0; i < n - 1; i++) {
        swapped = false;  // Initialize swapped to false at the beginning of each pass

        // Iterate through the unsorted part of the array
        for (j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;

                swapped = true;  // Set swapped to true to indicate a swap occurred
            }
        }
        
        // If no swaps were made in this pass, the array is already sorted, so exit
        if (swapped == false)
            break;
    }
}

// Selection Sort Algorithm
void selectionSort(int arr[], int n){
    int min_idx, swap;

    // Iterate through the array
    for (int i=0; i<n-1; i++) {
        min_idx = i;

        // Find the index of the minimum element in the unsorted part
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the current element
        if (min_idx != i) {
            swap = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = swap;
        }
    }
}

// Insertion Sort Algorithm
void insertionSort(int arr[], int n){
    int key, j;

    // Iterate through the array starting from the second element
    for (int i=1; i<n; i++) {
        key = arr[i];  // Store the current element
        j = i - 1;

        // Move elements that are greater than the key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Place the key in its correct position
        arr[j + 1] = key;
    }
}

// Quick Sort Algorithm
void quickSort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Quick Sort Algorithm Helper Function
int partition(int arr[], int low, int high){
    int swap, pivot = arr[high];
    int i = (low - 1);

    // Iterate through the array
    for (int j=low; j<=high-1; j++) {
        // If the current element is smaller than or equal to the pivot, swap them
        if (arr[j] < pivot) {
            i++;
            swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }
    }

    // Swap the pivot element with the element at the correct position
    swap = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = swap;

    return (i + 1);  // Return the index of the pivot
}

// Copy of array
void copyArray(int arr[], int arr2[], int n){
    for (int i=0; i<n; i++) {
        arr2[i] = arr[i];  // Copy elements from arr to arr2
    }
}

// Print array
void printArray(int arr[], int n){
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);  // Print each element of the array
    }
    printf("\n");  // Print a newline character to separate the output
}
