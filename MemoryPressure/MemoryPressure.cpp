// MemoryPressure.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 466608
#define SIZE2 1024

int main(int argc, char *argv[])
{
    vector<int*> vec;

    for (int i = 0; i < SIZE; i++) {
        try {
            int *p = (int*)malloc(SIZE2 * sizeof(int));
            if (p == nullptr) {
                cout << "test Error allocating memory for " << i << endl;
                break;
            }
            vec.push_back(p);
        } catch (bad_alloc e) {
            cout << "Bad Alloc for " << i << endl;
            break;
        }
    }

    while (true) {
        for (int i = 0; i < SIZE; i++) {
            for_each(vec.begin(), vec.end(), [](auto& x) { x++; });
            cout << vec[0] << " " << vec[SIZE2 - 1] << endl;
        }
    }

    getchar();
    return 0;
}
