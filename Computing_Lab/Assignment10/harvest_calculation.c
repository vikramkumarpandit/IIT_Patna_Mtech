#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int start;
    int end;
    int *array;
    int index;
} ThreadData;

int *partial_sums;  // Array to store partial sums for each thread

void* calculate_partial_sum(void* arg) {
    ThreadData *data = (ThreadData*)arg;
    int sum = 0;
    for (int i = data->start; i < data->end; i++) {
        sum += data->array[i];
    }
    partial_sums[data->index] = sum;  // Store partial sum in global array
    pthread_exit(0);
}

int main() {
    int num_fields, num_teams;
    printf("Enter number of fields: ");
    scanf("%d", &num_fields);
    printf("Enter number of teams: ");
    scanf("%d", &num_teams);

    int *harvest = (int*)malloc(num_fields * sizeof(int));
    partial_sums = (int*)malloc(num_teams * sizeof(int));

    printf("Enter Array: ");
    for (int i = 0; i < num_fields; i++) {
        scanf("%d", &harvest[i]);
    }

    pthread_t threads[num_teams];
    ThreadData thread_data[num_teams];

    int part_size = num_fields / num_teams;
    int remainder = num_fields % num_teams;
    
    for (int i = 0; i < num_teams; i++) {
        thread_data[i].start = i * part_size;
        thread_data[i].end = (i == num_teams - 1) ? (i + 1) * part_size + remainder : (i + 1) * part_size;
        thread_data[i].array = harvest;
        thread_data[i].index = i;
        
        pthread_create(&threads[i], NULL, calculate_partial_sum, &thread_data[i]);
    }

    for (int i = 0; i < num_teams; i++) {
        pthread_join(threads[i], NULL);
    }

    int total_sum = 0;
    for (int i = 0; i < num_teams; i++) {
        total_sum += partial_sums[i];
    }

    printf("Total sum: %d\n", total_sum);

    free(harvest);
    free(partial_sums);

    return 0;
}
