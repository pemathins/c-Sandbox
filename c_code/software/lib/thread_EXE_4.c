#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

#define NUM_THREADS 1000000

void* thread_func(int* i) {
    printf("Thread ID: %ld, threadNo : %d\n", (long)pthread_self(),i);
    sleep(1);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    struct sched_param param;
    int i, rc;

    // Initialize attribute object
    pthread_attr_init(&attr);

    // Set stack size to 10240 bytes
    pthread_attr_setstacksize(&attr, 10);

    // Create 1 detached thread and 24 attached threads
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&threads[0], &attr, thread_func, NULL);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    for (i = 1; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], &attr, thread_func, NULL);
    }

    // Set scheduling policy to FIFO and weight to heavy
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    param.sched_priority = 10;
    pthread_attr_setschedparam(&attr, &param);

    // Set attributes for all threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
        if (rc) {
            fprintf(stderr, "Error: pthread_attr_setscope\n");
            exit(EXIT_FAILURE);
        }
        rc = pthread_create(&threads[i], &attr, thread_func, &i);
        if (rc) {
            fprintf(stderr, "Error: pthread_create\n");
            exit(EXIT_FAILURE);
        }
    }

    // Join all attached threads
    for (i = 1; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "Error: pthread_join\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
