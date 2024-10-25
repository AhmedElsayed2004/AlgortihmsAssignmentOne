//
// Created by mahmoud on 10/25/2024.
//

#ifndef ALGO_ASS1_B__HEAP_H
#define ALGO_ASS1_B__HEAP_H
#include "vector"
using namespace std;

class Heap {
private:
    int size{};
    bool isMaxHeap{1};
    vector<int> heap;
    void maxHeapify(int);
    void minHeapify(int);
    void buildMaxHeap(int);
    void buildMinHeap(int);
public:
    void insert(int);
    int extractMax();
    int extractMin();
};


#endif //ALGO_ASS1_B__HEAP_H
