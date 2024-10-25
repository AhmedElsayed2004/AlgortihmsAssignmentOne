#include<bits/stdc++.h>
#include "Heap.cpp"
using namespace std;


int main() {
   Heap heap;
   heap.insert(1);
   heap.insert(0);
   heap.insert(44);
   heap.insert(2);
   heap.insert(3);
   heap.insert(4);
   heap.insert(50);
   heap.insert(60);
   heap.insert(20);
   heap.insert(7);
   int x = heap.extractMax();
   cout<<"Max element is: "<<x<<"\n";
    x = heap.extractMin();
    cout<<"Min element is: "<<x<<"\n";
    x = heap.extractMax();
    cout<<"Max element is: "<<x<<"\n";
    x = heap.extractMax();
    cout<<"Max element is: "<<x<<"\n";
    x = heap.extractMax();
    cout<<"Max element is: "<<x<<"\n";
    x = heap.extractMax();
    cout<<"Max element is: "<<x<<"\n";
    x = heap.extractMin();
    cout<<"Min element is: "<<x<<"\n";
    x = heap.extractMax();
    cout<<"Max element is: "<<x<<"\n";


}
