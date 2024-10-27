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
        maxHeapify(0);
        return max ;

    }
}
template<typename T>
void Heap<T>::buildMaxHeap(int size){
    for (int i = 0; i < size; ++i) {
        maxHeapify(i);
    }
}
template<typename T>
void Heap<T>::buildMinHeap(int size){
    for(int perant = (size/2)-1; perant >=0 ; perant--){
        minHeapify(perant);
    }

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
        minHeapify(0);
        return min ;

    }
}
template<typename T>
void Heap<T>::maxHeapify(int perant) {
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
template<typename T>
void Heap<T>::minHeapify(int perant) {

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
