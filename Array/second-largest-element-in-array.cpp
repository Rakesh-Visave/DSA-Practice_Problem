#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int secondLargest(vector<int> a , int n)
{
    int largest = a[0];
    int slargest = INT_MIN;

    for(int i = 1; i<n; i++)
    {
        if(a[i] > largest){
            slargest = largest;
            largest = a[i];
        }
        else if(a[i] > slargest)
            slargest = a[i];
    }
    return slargest;
}

int secondSmallest(vector<int> a , int n)
{
    int smallest = a[0];
    int ssmallest = INT_MAX;

    for(int i = 1; i<n; i++)
    {
        if(a[i] < smallest){
            ssmallest = smallest;
            smallest= a[i];
        }
        else if(a[i] < ssmallest)
            ssmallest = a[i];
    }
    return ssmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int sLargest = secondLargest(a,n);
    int sSmallest = secondSmallest(a,n);

    return {sLargest,sSmallest};
}

int main()
{
    vector<int> a = {3,4,6,7,8,9};
    int n = 6;

    vector<int> ans = getSecondOrderElements(n,a);
    cout<<"The Second Largest Element is: "<<ans[0]<<endl;
    cout<<"The Second Smallest Element is: "<<ans[1]<<endl;
}
