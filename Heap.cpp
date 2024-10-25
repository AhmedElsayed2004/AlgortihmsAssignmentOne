//
// Created by mahmoud on 10/25/2024.
//

#include "Heap.h"
template<typename T>
void Heap<T>::insert(T element) {
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
template<typename T>
void Heap<T>::insert(T arr[],int size){
    for(int element = 0; element <size; element++){
        this->insert(arr[element]);
    }

}
template<typename T>
T Heap<T>::extractMax() {
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
        T max = heap[last] ;
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
template<typename T>
void Heap<T>::heapSort() {
    int tempSize =size;
    if(!isMaxHeap){
        buildMaxHeap(size);
        isMaxHeap=1;
    }
    if(size==0){
        throw std::runtime_error("\nheap is empty!\n");
    }else{
        int last = tempSize-1;
        tempSize--;
        swap(heap[0],heap[last]);
        T max = heap[last] ;
        heap.pop_back();
        int perant=0, leftChild = 2*perant+1,rightChild = 2*perant+2,current;
        while(leftChild<tempSize){
            if(heap[leftChild]<heap[rightChild] and rightChild <tempSize){
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
template<typename T>
void Heap<T>::buildMaxHeap(int size){
    maxHeapify(size);
}
template<typename T>
void Heap<T>::buildMinHeap(int size){
    minHeapify(size);
}
template<typename T>
T Heap<T>::extractMin() {
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
template<typename T>
void Heap<T>::maxHeapify(int size) {
    vector<int> heap;
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
template<typename T>
void Heap<T>::minHeapify(int size) {
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
