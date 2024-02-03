#include <stdio.h>
#include <time.h>

// Function to simulate unnecessary computation
void wasteTime() {
for (long i = 0; i < 1000000000; i++) {
	// Volatile to prevent optimization by the compiler
	volatile double dummy = 3.14159 * i;
	}
}

int main() {
	// Call the wasteful function
	wasteTime();
	// Print "Hello World" to the console
	printf("Hello World");
	
	return 0;
}