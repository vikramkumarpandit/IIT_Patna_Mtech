#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t lock;
int current_id = 1;

void *thread_fun(void *id) {
    int *t1 = (int *)id;

    while (1) {
        pthread_mutex_lock(&lock);
        if (current_id == *t1) {
            printf("process %d\n", *t1);
            current_id++;
            pthread_mutex_unlock(&lock);
            break;
        }
        pthread_mutex_unlock(&lock);
        usleep(100);  // Small delay to prevent busy-waiting
    }

    return NULL;
}

int main() {
    printf("Enter Number of threads = ");
    int n;
    scanf("%d", &n);

    pthread_t thread[100];
    int id[100];

    pthread_mutex_init(&lock, NULL);  // Initialize the mutex

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        // create thread
        int t = pthread_create(&thread[i], NULL, thread_fun, &id[i]);
        if (t != 0) {
            printf("Failed to create thread %d\n", i + 1);
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        pthread_join(thread[i], NULL);
    }

    pthread_mutex_destroy(&lock);  // Destroy the mutex

    return 0;
}
