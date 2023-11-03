//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

	bool checkTriplet(int arr[], int n) {
	    unordered_set<int> s;

        for (int i = 0; i < n; ++i)
            s.insert(arr[i] * arr[i]);

        for (auto a : s) {
            for (auto b : s) {
                if (s.find(a + b) != s.end())
                    return true;
            }
        }
        
        return false;
	}


int main()
{

    int n = 5;
    int arr[n] = {3, 2, 4, 6, 5};

    bool ans = checkTriplet(arr,n);

    if(ans)
        cout<<"this Array form pythagorean";
    else
        cout<<"This not from pythagorean";

}