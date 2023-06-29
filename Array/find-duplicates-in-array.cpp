
#include <bits/stdc++.h>
using namespace std;


    vector<int> duplicates(int arr[], int n) {
        
        int temp[n] = {0};
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            temp[arr[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            
            if(temp[i] > 1)
            {
                ans.push_back(i);
            }
        }
        if(ans.size() == 0)
        {
            ans.push_back(-1);
        }
        
        return ans;
    }

int main()
{
    int arr[5]= {2,3,1,2,3};
    int n = 5;

    vector<int> ans = duplicates(arr,n);

    cout<<"The Duplicate Number in Arrya: ";
    for(int i : ans)
    {
        cout<<i<<" ";
    }
}
