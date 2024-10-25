//
// Created by mahmoud on 10/25/2024.
//

#include <iostream>
#include "Heap.h"
void Heap::insert(int element) {
    if(!isMaxHeap){
        buildMaxHeap(size);
        isMaxHeap=1;
    }
    size++;
    heap.push_back(element);
    int i = size-1;
    while (i != 0 && heap[(i-1)/2] < heap[i]) {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }

}
int Heap::extractMax() {
    if(!isMaxHeap){
        buildMaxHeap(size);
        isMaxHeap=1;
    }
    if(size==0){
        throw std::runtime_error("\nheap is empty!\n");
    }else{
        int last = size-1;
        size--;
        swap(heap[0],heap[last]);
        int max =heap[last] ;
        heap.pop_back();
        int perant=0, leftChild = 2*perant+1,rightChild = 2*perant+2,current;
        while(leftChild<size){
            if(heap[leftChild]<heap[rightChild] and rightChild <size){
                current=rightChild;
            }else{
                current= leftChild;
            }
            if(heap[perant]<heap[current]){
                swap(heap[perant],heap[current]);
                perant=current;
                leftChild=2*perant+1;
                rightChild=2*perant+2;
            }else{
                break;
            }
        }
        return max ;

    }
}
void Heap::buildMaxHeap(int size){
    maxHeapify(size);
}void Heap::buildMinHeap(int size){
    minHeapify(size);
}
int Heap::extractMin() {
    if(isMaxHeap){
        buildMinHeap(size);
        isMaxHeap=0;
    }
    if(size==0){
        throw std::runtime_error("\nheap is empty!\n");
    }else{
        int last = size-1;
        size--;
        swap(heap[0],heap[last]);
        int min =heap[last] ;
        heap.pop_back();
        int perant = 0 ,leftChild = 2*perant+1,rightChild = 2*perant+2,current;
        while(leftChild<size){
            if(heap[leftChild]>heap[rightChild] and rightChild <size){
                current=rightChild;
            }else{
                current= leftChild;
            }
            if(heap[perant]>heap[current]){
                swap(heap[perant],heap[current]);
                perant=current;
                leftChild=2*perant+1;
                rightChild=2*perant+2;
            }else{
                break;
            }
        }
        return min ;

    }
}
void Heap::maxHeapify(int size) {
    for(int perant = (size/2)-1; perant >=0 ; perant--){
        int leftChild = 2*perant+1,rightChild = 2*perant+2,current;
        while(leftChild<size){
            if(heap[leftChild]<heap[rightChild] and rightChild < size){
                current=rightChild;
            }else{
                current= leftChild;
            }
            if(heap[perant]<heap[current]){
                swap(heap[perant],heap[current]);
                perant=current;
                leftChild=2*perant+1;
                rightChild=2*perant+2;
            }else{
                break;
            }
        }

    }


}
void Heap::minHeapify(int size) {
    for(int perant = (size/2)-1; perant >=0 ; perant--){
        int leftChild = 2*perant+1,rightChild = 2*perant+2,current;
        while(leftChild<size){
            if(heap[leftChild]>heap[rightChild] and rightChild < size){
                current=rightChild;
            }else{
                current= leftChild;
            }
            if(heap[perant]>heap[current]){
                swap(heap[perant],heap[current]);
                perant=current;
                leftChild=2*perant+1;
                rightChild=2*perant+2;
            }else{
                break;
            }
        }

    }

}
