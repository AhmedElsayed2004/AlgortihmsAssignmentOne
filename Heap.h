//
// Created by mahmoud on 10/25/2024.
//

#ifndef ALGO_ASS1_B__HEAP_H
#define ALGO_ASS1_B__HEAP_H
#include <iostream>
#include "vector"
using namespace std;
template<typename T>
class Heap {
private:
    int size{};
    bool isMaxHeap{1};
    vector<T> heap;
    void maxHeapify(int);
    void minHeapify(int);
    void buildMaxHeap(int);
    void buildMinHeap(int);
public:

    virtual void insert(T);
    void insert(T arr[],int size);
    virtual T extractMax();
    T extractMin();
};


#endif //ALGO_ASS1_B__HEAP_H
