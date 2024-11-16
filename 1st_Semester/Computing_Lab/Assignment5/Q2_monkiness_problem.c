#include <stdio.h>

// Function to perform binary search to find the largest valid j such that B[j] >= A[i]
int binary_search(int B[], int i, int n, int value) {
    int low = i, high = n - 1, result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // If B[mid] >= value, it's a valid j, search right for larger j
        if (B[mid] >= value) {
            result = mid;  // Found valid j
            low = mid + 1; // Try to find a larger valid j
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    
    return result;  // Returns largest valid j or -1 if not found
}

// Function to calculate the monkiness for one test case
int find_monkiness(int A[], int B[], int n) {
    int max_monkiness = 0;
    
    // For each element in A, find the largest valid j in B using binary search
    for (int i = 0; i < n; i++) {
        int j = binary_search(B, i, n, A[i]);  // Search for valid j >= i and B[j] >= A[i]
        
        if (j != -1) {
            int monkiness = j - i;
            if (monkiness > max_monkiness) {
                max_monkiness = monkiness;
            }
        }
    }
    
    return max_monkiness;
}

int main() {
    int tc;  // Number of test cases
    scanf("%d", &tc);

    while (tc--) {
        int n;  // Size of the arrays
        scanf("%d", &n);
        
        int A[n], B[n];  // Arrays A and B
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &B[i]);
        }

        // Find and print the monkiness for this test case
        int result = find_monkiness(A, B, n);
        printf("%d\n", result);
    }

    return 0;
}
