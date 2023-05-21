
#include <iostream>
#include "MAP.h"


void main(){
    int v[] = { 1,2,2,3,3,3,2,2,1,1, 4,4,4,4,4,4,4,5,4,4,4,4,4,4,4,4,1 };
    int n = 27;

    int maxcount = 0;
    int currentcount = 0;
    for (int i = 1; i < n; i++) {
        if (v[i-1] == v[i]) currentcount++;
        if(v[i - 1] != v[i] || i+1==n) {
            currentcount++; //de vreme ce elementul i este diferit, trebuie sa numar si elementul i-1
            maxcount = std::max(maxcount, currentcount); 
            currentcount = 0;
        }
    }
    std::cout << maxcount;

    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    //for (auto [key, value, index] : m)
    //    printf("Index:%d, Key=%d, Value=%s\n", index, key, value);


    m[20] = "result";
    m[15] = "C#";
    m.Delete(10);
    //m.Sort();

    for (auto [key, value, index] : m)
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    //m.Clear();

    Map<int, const char*> m2;
    m2[30] = "tastatura";
    m2[100] = "mouse";

    m.Swap(m2);

    printf("\n");
    for (auto [key, value, index] : m)
        printf("m => Index:%d, Key=%d, Value=%s\n", index, key, value);
    for (auto [key, value, index] : m2)
        printf("m2 => Index:%d, Key=%d, Value=%s\n", index, key, value);

    printf("\n");
    m.add(m2);
    m[1000] = "1";
    m2[1000] = "vector";
    for (auto [key, value, index] : m)
        printf("m => Index:%d, Key=%d, Value=%s\n", index, key, value);

}

