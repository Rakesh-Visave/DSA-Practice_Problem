// LEETCODE -- 459.Repeated Substring Pattern

#include<iostream>
#include<string>
using namespace std;


    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int l = 1; l <= n/2; l++) {
            
            if(n%l == 0) {
                int times = n/l;
                
                string pattern   = s.substr(0, l);
                string newStr = "";
                while(times--) {
                    newStr += pattern;
                }
                
                if(newStr == s)
                    return true;
            }
            
        }
        
        return false; 
    }

int main()

{
    string s = "abcabcabcabc";
    bool ans = repeatedSubstringPattern(s);
    if(ans)
        cout<<"it can be constructed by taking a substring of it and appending multiple copies of the substring together.";
    else   
        cout<<"it can't be constructed by taking a substring of it and appending multiple copies of the substring together.";
}