#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_LEN 100

int isSorted(int a[], int n) {
    while (--n > 0)
        if (a[n] < a[n - 1])
            return 0;
    return 1;
}

void shuffle(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int r = rand() % n;
        int temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

void stupidSort(int a[], int n) {
    while (!isSorted(a, n))
        shuffle(a, n);
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    srand(time(NULL));

    int a[LIST_LEN];
    for (int i = 0; i < LIST_LEN; i++) {
        a[i] = rand() % 1000;
    }
    int n = sizeof(a) / sizeof(a[0]);
    stupidSort(a, n);
    printf("Sorted array :\n");
    printArray(a, n);
    return 0;
}
