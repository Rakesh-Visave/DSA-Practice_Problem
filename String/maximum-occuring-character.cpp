
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using namespace std;


    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
        
        for(int i = 0; i < str.length(); i++ )
        {
            char ch  = str[i];
            int number =  ch - 'a';
            arr[number]++;
            
        }
        int maxi = -1;
        int ans = 0;
        for(int i = 0; i<26; i++)
        {
         
            if(maxi < arr[i])
            {
                ans = i;
                maxi = arr[i];
            }
        }
        return ans + 'a';
    }


int main()
{
    string str = "testsample";

    char ch  = getMaxOccuringChar(str);

    cout<<"The Maximum Occured Character in this string is: "<<ch;
}