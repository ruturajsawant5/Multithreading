/*
Write a program which takes an Input a positive integer from the user, say, N.

Your program should output :
5
4
3
2
1

I wish life was so simple. You need to print the values from N to 1 ( in reverse order) via 
multi-threading.

Your program should create N threads with thread id from 1 to N.  The Nth thread must print N, 
the (N-1)th thread must print N-1 and so on .
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int N;  // Global maximum thread number (set by user)

// Thread function: each thread receives its index as argument.
void* thread_function(void* arg) {
    int index = *((int*)arg);
    free(arg);  // Free the allocated memory for this argument

    // If this thread's index is less than N, create a child thread with index+1.
    if (index < N) {
        pthread_t child_thread;
        int* next_index = malloc(sizeof(int));
        if (next_index == NULL) {
            fprintf(stderr, "Memory allocation failed for thread %d\n", index + 1);
            exit(EXIT_FAILURE);
        }
        *next_index = index + 1;

        // Create the child thread.
        int rc = pthread_create(&child_thread, NULL, thread_function, next_index);
        if (rc != 0) {
            fprintf(stderr, "Failed to create thread %d\n", index + 1);
            exit(EXIT_FAILURE);
        }

        // Wait for the child thread (and its descendants) to finish.
        pthread_join(child_thread, NULL);
    }

    // After the child thread finishes, print this thread's index.
    // For example, if N==5, thread with index 5 prints first,
    // then thread with index 4 prints, and so on.
    printf("%d\n", index);
    return NULL;
}

int main(void) {
    printf("Enter N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    pthread_t thread1;
    int* first_arg = malloc(sizeof(int));
    if (first_arg == NULL) {
        fprintf(stderr, "Memory allocation failed for thread 1 argument\n");
        return EXIT_FAILURE;
    }
    *first_arg = 1;  // Start with thread 1

    // Create thread 1.
    int rc = pthread_create(&thread1, NULL, thread_function, first_arg);
    if (rc != 0) {
        fprintf(stderr, "Failed to create thread 1\n");
        return EXIT_FAILURE;
    }

    // Wait for thread 1 (and therefore the entire chain) to finish.
    pthread_join(thread1, NULL);

    return 0;
}
