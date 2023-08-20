
#include<bits/stdc++.h>

using namespace std;

    int lower_bound(int arr[],int n, int x){
        int l = 0, r = n - 1;
        while(l < r){
            int m = (l + r) / 2;
            
            if(x <= arr[m])
                r = m;
            else
                l = m + 1;
        }
            
        return l;
    }

    int upper_bound(int arr[],int n, int x){
        int l = 0, r = n - 1;
        while(l < r){
            int m = (l + r) / 2;
            if(x >= arr[m])
                l = m+1;
            else
                r = m;
        }
        
        if(l < n && arr[l] <= x)
            l++;
            
        return l;
    }
    
	int count(int arr[], int n, int x) {
	   int start = lower_bound(arr,n,x);
	    if(arr[start] != x)
	        return 0;
	       
	    int last = upper_bound(arr,n,x);
	    
	    return last - start;
	}

int main()
{
    int arr[7] = {1, 1, 2, 2, 2, 2, 3};
    int n = 7;

    int x = 2;

    int ans = count(arr,n,x);
    cout<<"The Number of occurence is: "<<ans;
}