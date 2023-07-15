// CODESTUDIO -- Build Min Heap
#include <bits/stdc++.h> 
#include<vector>
#include<iostream>
using namespace std;

void heapifyAlgo(vector<int> &arr, int n , int i)
{
    int Smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[Smallest] > arr[left])
    {
        Smallest = left;
    }
    if(right < n && arr[Smallest] > arr[right])
    {
        Smallest = right;
    }

    if(Smallest != i)
    {
        swap(arr[i], arr[Smallest]);
        heapifyAlgo(arr,n,Smallest);
    }
    
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i = n/2-1; i>=0; i--){
        heapifyAlgo(arr,n,i);
    }
    return arr;
}


int main() {
    std::vector<int> arr = {9, 5, 2, 8, 1, 6};

    std::cout << "Before building min heap: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    arr = buildMinHeap(arr);

    std::cout << "After building min heap: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}