#pragma warning(disable : 4996)
#include "Sort.h"

#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <stdarg.h>
#include <cstring>
#include <queue>



    // 1
Sort::Sort(int noElements, int min, int max) {
    table = new int[noElements];
    size = noElements;

    srand(time(NULL));
    for (int i = 0; i < noElements; i++)
       table[i] = (rand() % (max-min) + min);
    
    InsertSort(true);
}

    // 2
Sort::Sort(std::initializer_list<int> list){
    int noParams = list.size();
    
    table = new int[noParams];
    size = noParams;

    int count = 0;
    for (int x : list) {        
        table[count] = x;
        count++;
    }

    BubbleSort(true);
}

    // 3
Sort::Sort(int arr[], int noEl) {
    table = new int[noEl];
    size = noEl;

    for (int i = 0; i < noEl; i++)
        table[i] = arr[i];

    BubbleSort();
}


    // 4
Sort::Sort(int noParams, ...) {
    table = new int[noParams];
    size = noParams;

    va_list valist;
    va_start(valist, noParams);

    for (int i = 0; i < noParams; i++)
        table[i] = va_arg(valist, int);

    va_end(valist);

    QuickSort(true);
}


    // 5
Sort::Sort(char* str){
    std::queue<int> q;
    int noParams=0;

    char* p = strtok(str, ",");

    while (p != NULL) {
        q.push(atoi(p));
        p = strtok(NULL, ",");
        noParams++;
    }

    table = new int[noParams];
    size = noParams;

    for(int i = 0; i < noParams; i++) {
        table[i] = q.front();
        q.pop();
    }

    InsertSort();
 }



void ascendantInsertSort(int x[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++){
        key = x[i];
        j = i - 1;

        while (j >= 0 && x[j] > key){        
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = key;
    }
}
void descendantInsertSort(int arr[], int size) {
    for (int step = 1; step < size; step++){
        int key = arr[step];
        int j = step - 1;
        while (key > arr[j] && j >= 0){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void Sort::InsertSort(bool ascendent) {	
    if (ascendent == true) ascendantInsertSort(table, size);
    else descendantInsertSort(table, size);
}




void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int ascpartition(int x[], int low, int high){
    int pivot = x[high];

    int i = low - 1;

    for (int j = low; j < high; j++){    
        if (x[j] <= pivot){
            i++;
            swap(&x[i], &x[j]);
        }
    }
    swap(&x[i + 1], &x[high]);
    return (i + 1);
}
void ascquickSort(int x[], int low, int high){
    if (low < high){
        int pivot = ascpartition(x, low, high);
        ascquickSort(x, low, pivot - 1);
        ascquickSort(x, pivot + 1, high);
    }
}
void descquickSort(int x[], int low, int high) {
    int i = low;
    int j = high;
    int temp = x[i];

    if (low < high){
        while (i < j){
            while (x[j] <= temp && i < j)
                j--;

            x[i] = x[j];

            while (x[i] >= temp && i < j)
                i++;

            x[j] = x[i];
        }
        x[i] = temp;

        descquickSort(x, low , i - 1);
        descquickSort(x, j + 1, high);
    }
}

void Sort::QuickSort(bool ascendent) {
    if (ascendent == true) ascquickSort(table, 0, size - 1);
    else descquickSort(table, 0, size-1);
}




void ascendantbubbleSort(int array[], int size) {
    for (int step = 0; step < size-1; ++step) 
        for (int i = 0; i < size - step -1 ; ++i)
            if (array[i] > array[i + 1])
                swap(&array[i], &array[i+1]);

}
void descendantbubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i; j++)
            if (array[j] < array[j + 1])
                swap(&array[j], &array[j + 1]);
}

void Sort::BubbleSort(bool ascendent) {
    if (ascendent == true) ascendantbubbleSort(table, size);
    else descendantbubbleSort(table, size);
}



void Sort::Print() {
    for (int i = 0; i < size; i++)
        std::cout << table[i] << " ";
    std::cout << std::endl;
}


int  Sort::GetElementsCount() {
    return size;
}

int Sort::GetElementFromIndex(int index) {
    return table[index];
}


void Sort::Merge(Sort s){
    int* table2 = new int[size + s.GetElementsCount()];
    
    for (int i = 0; i < size; i++)
        table2[i] = table[i];
    for (int i = 0; i < s.GetElementsCount(); i++)
        table2[size + i ] = s.GetElementFromIndex(i);
    
    table = table2;
    size += s.GetElementsCount();
    
    //InsertSort(true);
}