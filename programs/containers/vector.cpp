#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main()
{
    srand(time(NULL));
    std::vector<int> test;
    for (int i = 0; i < 100000000; ++i)
    {
        test.push_back(rand());
    }
    printf("Done\n");
    sleep(20);
    printf("Sorting start\n");
    std::sort(test.begin(), test.end());
    printf("Sorting Done\n");
    sleep(10);
}