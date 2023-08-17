// GFG -- Next Smallest Palindrome


#include <bits/stdc++.h>
#include<iostream>
using namespace std;

	vector<int> generateNextPalindrome(int num[], int n) {
	       vector<int> out(num, num + n); // Copy num array for output
        
        int i = 0, j = n - 1;

        while (i < j) { // Convert 'out' array into a palindrome
            out[j] = out[i];
            ++i;
            --j;
        }

        bool isBig = false;
        for (int it = n / 2; it < n; ++it) { // Check if 'out' is greater than 'num'
            if (out[it] > num[it]) {
                isBig = true;
                break;
            }
            if (out[it] < num[it])
                break;
        }

        if (isBig) // If 'out' is greater, no further operation needed
            return out;

        i = (n % 2) ? n / 2 : (n / 2 - 1);  // Mids of the out array
        j = n / 2;

        while (i >= 0) { // Incrementing numbers from the middle to the corners
            if (out[i] < 9) {
                out[i] = out[j] = out[i] + 1;
                return out;
            }
            out[i] = out[j] = 0;
            --i;
            ++j;
        }

        out[0] = 1; // If all digits are 9, convert to [1, 0, 0, ..., 0, 1]
        out.push_back(1);

        return out;
	}



//{ Driver Code Starts.

int main()
{
    int nums[11] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};
    int n = 11;
    vector<int> ans = generateNextPalindrome(nums,n);

    cout<<"Next smallest palindrome is: ";
    for(auto i : ans)
        cout<<" "<<i;
}