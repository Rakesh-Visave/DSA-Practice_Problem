//  GFG -- Subarray with given sum


#include <bits/stdc++.h>
using namespace std;

    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        
        vector<int> out;
        int i = 0;
        long long sum = 0;
        for(int j = 0; j< n;++j){
            sum += arr[j];
            while(sum > s && i<j){
                sum -= arr[i];
                ++i;
            }
            if(sum == s){
                out.push_back(i+1);
                out.push_back(j+1);
                return out;
            }
        }
        
        out.push_back(-1);
        return out;
    }
int main()
{
    vector<int> arr =  {1,2,3,7,5};
    int n = 5;
    int s = 12;

    cout<<"The sum of elements is at postions: ";
    vector<int> ans = subarraySum(arr,n,s);
    for(auto i: ans)
        cout<<" "<<i;
}