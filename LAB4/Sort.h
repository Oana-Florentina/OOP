#pragma once
#include <initializer_list>

class Sort {
    int* table;
    int size;

public:

    Sort(int noElements, int min, int max);//1
    Sort(std::initializer_list<int> list);
    Sort(int arr[], int noEl);//3
    Sort(int noParams, ...);
    Sort(char* str);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);

    void Merge(Sort s);
};