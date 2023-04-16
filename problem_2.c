
// Create a c program to solve the given problem:
//Create N number of threads. Each thread will print out a message and its thread ID. 
//Make the main thread sleep for 10 second for every alternate thread it creates.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *threadFunc(void *arg) {
    int tid = *((int *) arg);
    printf("Thread %d: ", tid);
    pthread_exit(NULL);
}

int main() {
    int n = 5; // number of threads to create
    int threadIds[n];
    int i;

    for (i = 0; i < n; i++) {
        threadIds[i] = i + 1;
        if (i % 2 == 0) {
            sleep(10); // sleep for 10 seconds for alternate threads
        }
        pthread_create(&threads[i], NULL, threadFunc, &threadIds[i]);
    }

    
    
    return 0;
}
