#include<bits/stdc++.h>
#include "Heap.cpp"
#include "HeapSort.cpp"
using namespace std;


int main() {
   Heap<int> heap;
   int arr[] = { 1,20,3,4,5,90,6,0};
   heapSort(arr,8);
   for (int i = 0; i < 8; ++i) {
       cout<<arr[i]<<" ";
   }



}
