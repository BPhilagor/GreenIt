#include <stdio.h>
#include <unistd.h>

int main() {
    // Loop to introduce delay
    for (long i = 0; i < 1000000; i++) {
        for (long j = 0; i < 1000000; j++) {
            long test = i * j;
            (void) test;
        }
        printf("%ld\n", i);
    }

    return 0;

}