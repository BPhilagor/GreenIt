#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

#define THREAD_NBR 20

void *routine(void *params) {
    while (1) {
        for (int idx = 0; idx < 10000; ++idx) {
            int i = rand();
            int j = rand();

            long l = i * j;
        }
        sleep(1);
    }
}

int main() {
    srand(time(NULL));
    pthread_t thread_id[THREAD_NBR];
    // Loop to introduce delay
    for (int i = 0; i < THREAD_NBR; ++i) {
        pthread_create(thread_id + i, NULL, routine, NULL);
    }
    for (int i = 0; i < THREAD_NBR; ++i) {
        pthread_join(thread_id[i], NULL);
    }
    return 0;

}