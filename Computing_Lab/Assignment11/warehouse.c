#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_CAPACITY 5
#define MAX_TRANSACTIONS 20

int warehouse[MAX_CAPACITY]; // Warehouse slots
int count = 0;                // Number of current transactions
int in = 0, out = 0;          // Indices for producer and consumer actions

pthread_mutex_t mutex;
sem_t emptySlots;  // Semaphore for empty slots in the warehouse
sem_t fullSlots;   // Semaphore for items available in the warehouse

void* supplier(void* arg) {
    int id = *(int*)arg;

    while (1) {
        // Check if maximum transactions reached
        pthread_mutex_lock(&mutex);
        if (count >= MAX_TRANSACTIONS) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        count++;
        pthread_mutex_unlock(&mutex);

        // Produce an item
        int item = rand() % 100;

        // Wait if warehouse is full
        sem_wait(&emptySlots);
        pthread_mutex_lock(&mutex);

        // Add item to warehouse
        warehouse[in] = item;
        printf("Supplier %d delivered item %d to warehouse slot %d\n", id, item, in);
        in = (in + 1) % MAX_CAPACITY;

        // Print current warehouse state
        printf("Current Warehouse State: ");
        for (int i = 0; i < MAX_CAPACITY; i++) {
            if (warehouse[i] == -1)
                printf("[-] ");
            else
                printf("[%d] ", warehouse[i]);
        }
        printf("\n");

        pthread_mutex_unlock(&mutex);
        sem_post(&fullSlots); // Signal that there is an available item

        sleep(1); // Simulate time taken for the supplier to produce the next item
    }

    free(arg);
    return NULL;
}

void* deliveryAgent(void* arg) {
    int id = *(int*)arg;

    while (1) {
        // Check if maximum transactions reached
        pthread_mutex_lock(&mutex);
        if (count >= MAX_TRANSACTIONS) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        count++;
        pthread_mutex_unlock(&mutex);

        // Wait if warehouse is empty
        sem_wait(&fullSlots);
        pthread_mutex_lock(&mutex);

        // Remove item from warehouse
        int item = warehouse[out];
        warehouse[out] = -1; // Mark slot as empty
        printf("Delivery Agent %d picked up item %d from warehouse slot %d\n", id, item, out);
        out = (out + 1) % MAX_CAPACITY;

        // Print current warehouse state
        printf("Current Warehouse State: ");
        for (int i = 0; i < MAX_CAPACITY; i++) {
            if (warehouse[i] == -1)
                printf("[-] ");
            else
                printf("[%d] ", warehouse[i]);
        }
        printf("\n");

        pthread_mutex_unlock(&mutex);
        sem_post(&emptySlots); // Signal that there is an available slot

        sleep(1); // Simulate time taken for the delivery agent to process the next item
    }

    free(arg);
    return NULL;
}

int main() {
    int numSuppliers, numAgents;
    printf("Enter number of suppliers (<10): ");
    scanf("%d", &numSuppliers);
    printf("Enter number of delivery agents (<10): ");
    scanf("%d", &numAgents);

    // Initialize the warehouse slots to empty (-1)
    for (int i = 0; i < MAX_CAPACITY; i++) {
        warehouse[i] = -1;
    }

    // Initialize the semaphores and mutex
    sem_init(&emptySlots, 0, MAX_CAPACITY);
    sem_init(&fullSlots, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create supplier and delivery agent threads
    pthread_t suppliers[numSuppliers], agents[numAgents];
    for (int i = 0; i < numSuppliers; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&suppliers[i], NULL, supplier, id);
    }
    for (int i = 0; i < numAgents; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&agents[i], NULL, deliveryAgent, id);
    }

    // Wait for all threads to complete
    for (int i = 0; i < numSuppliers; i++) {
        pthread_join(suppliers[i], NULL);
    }
    for (int i = 0; i < numAgents; i++) {
        pthread_join(agents[i], NULL);
    }

    // Cleanup
    sem_destroy(&emptySlots);
    sem_destroy(&fullSlots);
    pthread_mutex_destroy(&mutex);

    printf("All transactions completed.\n");
    return 0;
}
