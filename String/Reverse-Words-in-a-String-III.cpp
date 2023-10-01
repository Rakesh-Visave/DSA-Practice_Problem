// LEETCODE -- 557. Reverse Words in a String III

#include<iostream>
#include<algorithm>
using namespace std;

    string reverseWords(string s) {
         int n = s.length();
        
        for (int i = 0; i < n; i++) {
            
            if (s[i] != ' ') {
                
                int j = i;
                
                while( j < n && s[j] != ' ') {
                    j++;
                }
                
                reverse(s.begin() + i, s.begin() + j);
                
                i = j;
            }
            
        }
        
        return s;
    }


int main()
{
    string s = "Let's take LeetCode contest";
    string ans = reverseWords(s);

    cout<<ans;
}