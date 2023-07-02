//LEETCODE  --  1221. Split a String in Balanced Strings

#include<iostream>
using namespace std;

    int balancedStringSplit(string s) {
        int rcount=0;
        int lcount = 0;
        int count = 0;
        for(char ch : s){
            if(ch == 'R')
            {
                rcount++;
            }
            else
            {
                lcount++;
            }
            if(rcount == lcount)
            {
                count++;
            }
        }
        return count;
    }

int main()
{
    string s = "RLRRLLRLRL";

    int count = balancedStringSplit(s);

    cout<<"the maximum number of balanced strings we have: "<<count;
}