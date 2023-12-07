// LEETCODe -- 1903.Largest Odd Number in String
#include<iostream>
using namespace std;

    string largestOddNumber(string num) {
         int n = num.length();
        
        for(int i = n-1; i>=0; i--) {
            
            if((num[i] - '0') % 2 != 0) {
                return num.substr(0, i+1);
            }
        }
        
        return "";
    }


int main()
{
    string num = "52";

    string ans = largestOddNumber(num);

    cout<<"the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists: "<<ans;
}