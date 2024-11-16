#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Queue structure
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void enqueue(Queue *q, int value) {
    q->data[++(q->rear)] = value;
}

int dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->data[(q->front)++];
}

bool is_empty(Queue *q) {
    return q->front > q->rear;
}

void initialize_queue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Stack structure using two queues
typedef struct {
    Queue q1, q2;
} Stack;

void push(Stack *s, int value) {
    // Enqueue the new element to q2
    enqueue(&s->q2, value);

    // Move all elements from q1 to q2 to maintain stack order
    while (!is_empty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Swap the two queues
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    printf("Pushed %d to the stack\n", value);
}

int pop(Stack *s) {
    if (is_empty(&s->q1)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = dequeue(&s->q1);
    printf("Popped %d from the stack\n", value);
    return value;
}

int main() {
    Stack s;
    initialize_queue(&s.q1);
    initialize_queue(&s.q2);

    int choice, value;

    while (1) {
        printf("\nStack Operations using Queue:\n");
        printf("1. Push\n2. Pop\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
