//
// Created by mahmoud on 10/25/2024.
//

#ifndef ALGO_ASS1_B__PRIORITYQUEUE_H
#define ALGO_ASS1_B__PRIORITYQUEUE_H
#include "Heap.h"
template<typename T>
class PriorityQueue{
private:
    int size{};
    Heap<pair<int,T>> priorityQueue;
public:
    T extractMax() ;
    void insert(T element, int priority) ;

};


#endif //ALGO_ASS1_B__PRIORITYQUEUE_H
