#include<bits/stdc++.h>
#include "Heap.cpp"
#include "HeapSort.cpp"
using namespace std;


int main() {
   Heap<int> heap;
   int arr[] = { 1,1,1,1,3,2,2, 2,5};
    heapSort(arr,9);
    for(auto i :arr){
        cout<<i<<" ";

    }



}
