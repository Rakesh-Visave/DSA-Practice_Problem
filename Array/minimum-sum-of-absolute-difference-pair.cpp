// GEEK-FOR-GEEKS -- Minimum Sum of Absolute Differences of Pairs
#include <bits/stdc++.h>
using namespace std;

    long long findMinSum(vector<int> &A,vector<int> &B,int N){
        
        long long int sum = 0;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        for(int i = 0; i < N; i++)
        {
            sum += abs(A[i] - B[i]); 
        }
        return sum;
    }

int main(){

    vector<int> A = {4,1,8,7};
    vector<int> B = {2,3,6,5};

    int sum  = findMinSum(A,B,4);

    cout<<"sum of the absolute differences of all the pairs is minimum: "<<sum;
    
}
