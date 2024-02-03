#include <stdio.h>
#include <unistd.h>

int main() {
    // Loop to introduce delay
    for (long i = 0; i < 1000000; i++) {
        for (long j = 0; j < 10000000000; j++) {
            long test = i * j;
            (void) test;
        }
        printf("%ld\n", i);
        sleep(3);
    }

    return 0;

}