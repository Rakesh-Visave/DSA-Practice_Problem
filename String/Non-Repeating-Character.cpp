// GFG -- Non Repeating Character

#include <bits/stdc++.h>
using namespace std;

    char nonrepeatingCharacter(string S)
    {
       int n = S.size();
       int chars = 256;
       int arr[chars] = {0};
     
        
        for(int i= 0; i<n; i++)
        {
            arr[S[i]]++;
        }
        for(int i = 0; i<n; i++)
        {
            if(arr[S[i]] == 1)
                return (char)S[i];
        }
       return '$';
    }

int main()
{
    string S = "hello";
    char ch = nonrepeatingCharacter(S);
    cout<<"The Non Reapting Character is: "<<ch;

}