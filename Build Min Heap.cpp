Problem Link: https://www.codingninjas.com/studio/problems/build-min-heap_1171167?leftPanelTab=0

#include <bits/stdc++.h> 
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    if (leftChild < n && arr[largest] > arr[leftChild]) largest = leftChild;
    if (rightChild < n && arr[rightChild] < arr[largest]) largest = rightChild;

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i=n/2; i>=0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}
