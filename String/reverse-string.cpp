// LEETCODE -- 344. Reverse String

#include<iostream>
#include<vector>
using namespace std;

    void reverseString(vector<char>& s) {

        int start = 0;
        int n = s.size();
        int end = n-1;

        while(start < end)
        {
            swap(s[start++],s[end--]);
        }

       
        
    }


int main()
{
    vector<char> s = {'h','e','l','l','o'};

    reverseString(s);
    cout<<"The Reverse String is: ";
    for(char ch : s)
    {
        cout<<ch<<" ";
    }
}