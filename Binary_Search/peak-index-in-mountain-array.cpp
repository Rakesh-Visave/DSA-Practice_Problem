// LEETCODE - 852. Peak Index in a Mountain Array

#include<iostream>
#include<vector>
using namespace std;

    int peakIndexInMountainArray(vector<int>& arr) {

        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e-s)/2;

        while(s < e)
        {
            if(arr[mid] < arr[mid+1])
                s = mid+1;
            else
                e = mid;
         mid = s + (e-s)/2;
        }
        return s;
        
    }
    


int main()
{
    vector<int> arr = {0,10,5,2};
    int peakindex = peakIndexInMountainArray(arr);

  cout<<"The peak Element of an Array is"<<peakindex;

  
}