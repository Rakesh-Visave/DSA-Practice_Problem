#include<iostream>
using namespace std;

int sqrt(int n)
{
    int s = 0;
    int e = n;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e)
    {
        int squre = mid*mid;
        if(squre == n)
        {
            return mid;
        }
        if(squre < n)
        {
         ans = mid;
         s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;

}

int main(){

    int n;
    cout<<"Enter the Element to find the Squre Root: "<<endl;
    cin>>n;

    cout<<"The squre root of given element is "<<sqrt(n);
}