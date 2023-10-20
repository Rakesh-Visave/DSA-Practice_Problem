// GFG --Form a number divisible by 3 using array digits

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


    int isPossible(int N, int arr[]) {
  int sum = 0;
        for(int i=0; i<N; i++)
            sum += arr[i]%3;
        return sum%3 == 0;
    }


int main()
{
    int n = 3;
    int arr[n] = {40,50,90};
    int ans = isPossible(n,arr);

    if(ans)
        cout<<"Given nunmber is Divisible by 3";
    else    
        cout<<"Given number is not divisible by 3";
}
