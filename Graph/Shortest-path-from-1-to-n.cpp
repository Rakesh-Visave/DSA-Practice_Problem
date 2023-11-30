// GFG -- Shortest path from 1 to n


#include<bits/stdc++.h> 
using namespace std; 


    int minimumStep(int n){
         int cnt = 0;
        while (n > 1) {
            if (n % 3 == 0)
                n /= 3;
            else
                n -= 1;
            ++cnt;
        }
        return cnt;
    }


int main()
{
    int n = 9;
    int ans = minimumStep(n);

    cout<<"The minimum number of edges in a path from vertex 1 to vertex n: "<<ans;
}