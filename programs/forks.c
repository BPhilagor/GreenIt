#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define NUM_CHILDREN 10
#define MEMORY_SIZE_MB 10

void consume_cpu() {
    float k = 0;
    for (float i = 1.001; i < 500000; i++)
        for (float j = 1.01; j < 500000; j++)
            k = j * i;
    return;
}

void consume_memory() {
    size_t bytes = MEMORY_SIZE_MB * 1024 * 1024;
    char *memory = malloc(bytes);
    if (memory == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t i = 0; i < bytes; i++) {
        memory[i] = (char)(i % 256);
    }
}

int main() {
    for (int i = 0; i < NUM_CHILDREN; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            return 1;
        } else if (pid == 0) {
            consume_cpu();
            consume_memory();

            exit(0);
        }
    }

    for (int i = 0; i < NUM_CHILDREN; i++) {
        wait(NULL);
    }

    printf("All child processes have finished\n");

    return 0;
}
