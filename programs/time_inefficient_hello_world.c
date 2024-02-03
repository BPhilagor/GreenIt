#include <stdio.h>
#include <unistd.h>

int main() {
// Loop to introduce delay
for (int i = 0; i < 100; i++) {
    sleep(1); // Sleep for 1 second
}

// Print "Hello World" to the console
printf("Hello World");
return 0;

}