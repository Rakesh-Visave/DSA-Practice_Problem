// GFG -- Kth smallest Element

#include<bits/stdc++.h>
using namespace std;

    int kthSmallest(vector<int> arr, int k) {
        
        priority_queue<int> pq;
        // step-1 insert first k element in max heap
        for(int i = 0; i<k; i++)
        {
            pq.push(arr[i]);
        }
        // for insert remaining element if(element < heap.top()) 
        for(int i = k; i<=arr.size()-1; i++)
        {
            if(arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }

int main()
{
    vector<int > nums  = {3,2,1,5,6,4};
    int k = 2;

    int ans = kthSmallest(nums,k);
    cout<<"The Kth Smallest Number is: "<<ans;
}
