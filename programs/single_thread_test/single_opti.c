#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void costly_operation() {
    for (int idx = 0; idx < 100000; ++idx) {
        long l;
        for (int idx2 = 0; idx2 < 10000; ++idx2) {
            int i = rand();
            int j = rand();
            l = i * j;
        }
    }
}

int main() {

    long operations = 0;
    while (1) {
        costly_operation();
        printf("Done !\n");
        sleep(30);
    }

}