#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void* Thread_Fun(void *arg) {
    int *id = (int*)arg;
    printf("Process %d\n", *id);
    return NULL;
}

int main() {
    pthread_t thread[5];
    int arg[5];

    // Create threads
    for (int i = 0; i < 5; i++) {
        arg[i] = i + 1;
        int q = pthread_create(&thread[i], NULL, Thread_Fun, &arg[i]);
        pthread_join(thread[i], NULL);
        if (q != 0) {
            printf("Error creating thread %d\n", i + 1);
            return 1;
        }
    }

   

    printf("All threads created and joined successfully\n");
    return 0;
}
