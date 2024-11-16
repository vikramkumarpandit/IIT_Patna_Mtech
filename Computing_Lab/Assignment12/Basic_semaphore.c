#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;  // Declare a semaphore

void* threadFunction(void* arg) {
    int threadNum = *(int*)arg;
    printf("Thread %d: Waiting to enter critical section...\n", threadNum);
    
    sem_wait(&semaphore); // Wait (decrement) on the semaphore
    printf("Thread %d: Inside critical section\n", threadNum);
    sleep(2); // Simulate some work in the critical section
    printf("Thread %d: Exiting critical section\n", threadNum);
    
    sem_post(&semaphore); // Signal (increment) the semaphore
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int threadNum1 = 1, threadNum2 = 2;

    // Initialize the semaphore with a value of 1
    sem_init(&semaphore, 0, 1);

    // Create two threads that use the same function
    pthread_create(&thread1, NULL, threadFunction, &threadNum1);
    pthread_create(&thread2, NULL, threadFunction, &threadNum2);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the semaphore
    sem_destroy(&semaphore);

    printf("Main: All threads have finished execution\n");
    return 0;
}
