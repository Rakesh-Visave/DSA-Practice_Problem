// LEETCODE -- 204. Count Primes

#include<iostream>
#include<vector>
using namespace std;

    int countPrimes(int n) {

        vector<bool> prime(n+1, true);
        int count = 0;
        prime[0] = prime[1] = false;

        for(int i = 2; i < n; i++)
        {
            if(prime[i])
            {
                count++;
                for(int j = 2*i; j < n; j = j+i)
                {
                    prime[j] = 0;
                }
            }
        }
        return count;
    }

int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;

    int ans = countPrimes(n);

    cout<<"the number of prime number: "<<ans;

    
}