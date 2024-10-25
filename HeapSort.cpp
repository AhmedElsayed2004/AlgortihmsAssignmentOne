#include<bits/stdc++.h>

using namespace std;
template<typename T>
void maxHeapify(T heap[] , int size,int perant = 0) {
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
void heapSort(T arr[],int size){
    for(int perant = (size/2)-1; perant >=0 ; perant--){
        maxHeapify(arr,size,perant);
    }
    for (int i = size-1; i >=0 ; --i) {
        swap(arr[0],arr[i]);
        maxHeapify(arr,i);
    }
}