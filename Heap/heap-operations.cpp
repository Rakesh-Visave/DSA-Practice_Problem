// Heap operations 
//     1.insertion
//     2.Deletion
//     3.mixHeap - build heap
//     4.heapsort

#include<iostream>
#include<algorithm>
using namespace std;


class heap{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }


void  insert(int val)
{
    size = size + 1;
    int index = size;
    arr[index] = val;

    while(index > 1)
    {
        int parent = index/2;
        if(arr[parent] < arr[index])
        {
            swap(arr[parent] , arr[index]);
            index = parent;
        }
        else    
            return;
    }
}

void deleteFromHeap()
{
    // check heap is empty
    if(size == 0)
        cout<<"Heap is empty";
    
    // step-1 replace first element with last element
    arr[1] = arr[size];
    
    // step-2 delete last element
    size--;

    // find leftIndex and rightIndex
    int  i = 1;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;

    // arrange root element in their right position to satisfy the heap property
    while(i < size)
    {
    if(leftIndex < size && arr[i] < arr[leftIndex])
    {
        swap(arr[i], arr[leftIndex]);
        i = leftIndex;
    }
    else if(rightIndex < size && arr[i] < arr[rightIndex])
    {
        swap(arr[i], arr[rightIndex]);
        i = rightIndex;
    }
    else 
        return;
    }
}



// printing Heap
void printArray()
{
    for(int i = 1; i<= size; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
};

void heapify(int arr[] , int n , int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr,n,largest);
    }
    
}

void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        // step-1 swap root  element with last position
        swap(arr[size], arr[1]);
        size--;

        // step-2 arrange root element at right position
        heapify(arr,size,1);
    }
}

int main()
{
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(50);
    h.printArray();

    h.deleteFromHeap();
    h.printArray();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i = n/2; i>0; i--){
        heapify(arr,n,i);
    }

    cout<<"Printing array After Heapify: "<<endl;
    for(int i = 1; i<=n; i++)
    {
        cout<<arr[i]<<" ";

    }cout<<endl;


    heapSort(arr,n);

    cout<<"After HeapSort the Array is: "<<endl;
    for(int i = 1; i<=n; i++)
    {
        cout<<arr[i]<<" ";

    }

    return 0;
}