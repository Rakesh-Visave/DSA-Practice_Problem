#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cout<<"Enter Element to find fibonacci number: ";
    cin>>n;
    
    int prev1 = 1;
    int prev2 = 0; 
       
    for(int i =2; i<=n; i++)
    {
        int curr = prev1 + prev2;
        // shfting their positions
        prev2 = prev1;
        prev1 = curr;
    }


    cout<< "fibonacci number at "<<n<<" th position is: "<<prev1;
    return 0;
}