// LEETCODE -- 1347.Minimum Number of Steps to Make Two Strings Anagram

#include<iostream>
using namespace std;

    int minSteps(string s, string t) {
        int n = s.length();
        
        int mp[26] = {0};
        
        for(int i = 0; i<n; i++) {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }

        int result = 0;

        for(int i = 0; i < 26; i++) {
            result += max(0, mp[i]);
        } 
        
        return result;
    }

int main()
{
    string s = "bab";
    string t = "aba";

    int ans = minSteps(s,t);

    cout<<"the minimum number of steps to make t an anagram of s: "<<ans;;


}