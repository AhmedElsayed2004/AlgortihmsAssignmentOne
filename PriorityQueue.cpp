#include "PriorityQueue.h"
template<typename T>
void PriorityQueue<T>::insert(T element, int priority){
    size++;
    priorityQueue.insert(make_pair(priority,element));
}
template<typename T>
T PriorityQueue<T>::extractMax(){
    if(size==0){
        throw std::runtime_error("\npriority Queue is empty!\n");
    }
        size--;
        auto x = priorityQueue.extractMax();
        return x.second;
}
