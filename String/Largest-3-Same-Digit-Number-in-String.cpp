// LEETCODE -- 2264.Largest 3-Same-Digit Number in String

#include<iostream>
#include<cstring>
using namespace std;

    string largestGoodInteger(string num) {
         char maxChar = ' ';
        
        for(int i = 2; i<num.length(); i++) {
            if(num[i] == num[i-1] && num[i] == num[i-2]) {
                maxChar = max(maxChar, num[i]);
            }
        }
        
        return maxChar == ' ' ? "" : string(3, maxChar);
    }


int main()
{
    string num = "6777133339";
    string ans = largestGoodInteger(num);

    cout<<"the maximum good integer as a string or an empty string "" if no such integer exists: "<<ans;
}