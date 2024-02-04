#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    srand(time(NULL));
    std::list<int> test;
    for (int i = 0; i < 100000000; ++i)
    {
        test.push_back(rand());
    }
    printf("Done\n");
    sleep(20);
    printf("Sorting start\n");
    test.sort();
    printf("Sorting Done\n");
    sleep(10);
}