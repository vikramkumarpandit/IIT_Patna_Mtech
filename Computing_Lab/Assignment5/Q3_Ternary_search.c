#include <stdio.h>

// Function for iterative ternary search
int ternary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        
        // Check if the target is at mid1 or mid2
        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }
        
        // Narrow down the search space
        if (target < arr[mid1]) {
            high = mid1 - 1;  // Search in the left third
        } else if (target > arr[mid2]) {
            low = mid2 + 1;   // Search in the right third
        } else {
            low = mid1 + 1;   // Search in the middle third
            high = mid2 - 1;
        }
    }
    
    // If the element is not found
    return -1;
}

int main() {
    int n, target;
    
    // Input the size of the array and the target value
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the target value: ");
    scanf("%d", &target);
    
    // Perform ternary search
    int result = ternary_search(arr, n, target);
    
    // Output the result
    if (result != -1) {
        printf("Target found at index: %d\n", result);
    } else {
        printf("Target not found\n");
    }

    return 0;
}
