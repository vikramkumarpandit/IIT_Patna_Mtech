#include <stdio.h>

void print_next_greater(int arr[], int n) {
    int result[n];  // Array to store the result
    int stack[n];   // Stack to keep indices of array elements
    int top = -1;   // Initialize stack top as -1 (stack is empty)

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack while stack is not empty
        // and the stack's top element is less than or equal to arr[i]
        while (top != -1 && arr[stack[top]] <= arr[i]) {
            top--;
        }

        // If the stack is not empty, the top element of the stack is the
        // next greater element; otherwise, there is no greater element
        result[i] = (top == -1) ? -1 : arr[stack[top]];

        // Push this element index onto the stack
        stack[++top] = i;
    }

    // Print the results
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Next Greater Element:\n");
    print_next_greater(arr, n);
    
    return 0;
}
