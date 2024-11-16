#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Function to check if a number is prime
bool check_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to select the pivot
int select_pivot(int arr[], int low, int high) {
    int min_prime = 1000; // Arbitrarily large value
    int index = -1;

    // Find the least prime number in the range
    for (int i = low; i <= high; i++) {
        if (check_prime(arr[i])) {
            if (arr[i] < min_prime) {
                min_prime = arr[i];
                index = i;
            }
        }
    }

    // If a prime number is found, return its index
    if (index != -1) {
        return index;
    }
    
    // If no prime number, choose the middle element based on size
    int mid = low + (high - low) / 2;
    if ((high - low + 1) % 2 != 0) {
        return mid;  // If odd, choose the middle element
    } else {
        return mid - 1;  // If even, choose mid - 1
    }
}

// Function to swap two elements
void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

// Partition function using selected pivot
int partition(int arr[], int low, int high) {
    int pivot_index = select_pivot(arr, low, high);
    int pivot_value = arr[pivot_index];
    
    // Swap pivot element with the last element
    swap(&arr[pivot_index], &arr[high]);
    int store_index = low;

    // Rearrange elements around the pivot
    for (int i = low; i < high; i++) {
        if (arr[i] > pivot_value) {  // Sorting in descending order
            swap(&arr[store_index], &arr[i]);
            store_index++;
        }
    }

    // Swap pivot back to its correct position
    swap(&arr[store_index], &arr[high]);

    return store_index; // Return the final position of the pivot
}

// QuickSort algorithm
void Quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        Quick_sort(arr, low, p - 1);
        Quick_sort(arr, p + 1, high);
    }
}

int main() {
    printf("Enter size of the Array = ");
    int arr[100];
    int n;
    scanf("%d", &n);

    printf("Enter elements in Array = ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int low = 0, high = n - 1;
    Quick_sort(arr, low, high);

    printf("After Sorting = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
