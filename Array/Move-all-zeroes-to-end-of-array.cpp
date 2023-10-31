
#include <bits/stdc++.h>
using namespace std;


	void pushZerosToEnd(int arr[], int n) {
	    int j = -1;
	    for(int i = 0; i<n; i++)
	    {
	        if(arr[i] == 0)
	        {
	            j = i;
	            break;
	        }
	    }
	    if(j == -1)
	        return;
	    
	    for(int i = j+1; i<n; i++)
	    {
	        if(arr[i] != 0)
	        {
	            swap(arr[i],arr[j++]);
	        }
	    }
	}

int main()
{
    int n = 5;
    int arr[n] = {3,5,0,0,4};

    pushZerosToEnd(arr,n);

    cout<<"After Moving All Zero to The End the Array Will be:";
    for(int i : arr)
        cout<<" "<<i;
}