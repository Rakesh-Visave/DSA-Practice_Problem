// LEETCODE -- 1287.Element Appearing More Than 25% In Sorted Array


#include<iostream>
#include<vector>
using namespace std;

    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int freq = n/4;
        
        for(int i = 0; i<n-freq; i++) {
          
            if(arr[i] == arr[i+freq]) {
                return arr[i];
            }   
          
        }
        return -1;

    }


int main()
{
    vector<int> arr =  {1,2,2,6,6,6,6,7,10};

    int ans = findSpecialInteger(arr);

    cout<<"Element Appearing More Than 25% In Sorted Array is: "<<ans;
}