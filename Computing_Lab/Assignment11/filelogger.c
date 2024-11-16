#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t log_mutex;

int num_messages;

void* processA(void* arg) {
    for (int i = 1; i <= num_messages; i++) {
        pthread_mutex_lock(&log_mutex);  // Lock mutex before writing to log buffer
        printf("Process A: Message %d - Task completed\n", i);
        pthread_mutex_unlock(&log_mutex);  // Unlock mutex after writing
        usleep(100000);  // Sleep to simulate time taken for logging
    }
    return NULL;
}

void* processB(void* arg) {
    for (int i = 1; i <= num_messages; i++) {
        pthread_mutex_lock(&log_mutex);  // Lock mutex before writing to log buffer
        printf("Process B: Message %d - Task completed\n", i);
        pthread_mutex_unlock(&log_mutex);  // Unlock mutex after writing
        usleep(100000);  // Sleep to simulate time taken for logging
    }
    return NULL;
}

int main() {
    printf("Enter number of Messages per Process: ");
    scanf("%d", &num_messages);

    pthread_t threadA, threadB;

    // Initialize the mutex
    pthread_mutex_init(&log_mutex, NULL);

    // Create threads for Process A and Process B
    pthread_create(&threadA, NULL, processA, NULL);
    pthread_create(&threadB, NULL, processB, NULL);

    // Wait for both threads to complete
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&log_mutex);

    printf("Logging completed.\n");
    return 0;
}
