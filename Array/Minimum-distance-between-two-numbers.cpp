// GFG -- Minimum distance between two numbers


#include <bits/stdc++.h>
using namespace std;


    int minDist(int a[], int n, int x, int y) {
        int lastX, lastY, out;
        lastX = lastY = -1;
        out = INT_MAX;
        
        for(int i = 0; i < n; ++i) {
            if(a[i] == x)
                lastX = i;
            if(a[i] == y)
                lastY = i;
            
            if(lastX != -1 && lastY != -1)
                out = min(out, abs(lastX - lastY));
        }
        return out == INT_MAX ? -1 : out;
    }

int main(){

    int n =4;
    int a[] = {1,2,3,2};

    int x = 1;
    int y = 2;

    int ans = minDist(a,n,x,y);
    cout<<"There are two distances between x and y which the least is:"<<ans;
}