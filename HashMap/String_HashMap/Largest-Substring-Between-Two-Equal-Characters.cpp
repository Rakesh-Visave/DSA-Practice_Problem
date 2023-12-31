// LEETCODE -- 1624.Largest Substring Between Two Equal Characters


#include<unordered_map>
#include<iostream>
using namespace std;

    int maxLengthBetweenEqualCharacters(string s) {
         int n = s.length();
        unordered_map<char, int> mp;
        
        int result = -1;
        
        for(int i = 0 ; i < n;  i++) {
            char ch = s[i];
            
            if(mp.find(ch) == mp.end()) {
                mp[ch] = i;
            } else {
                result = max(result, i - mp[ch] - 1);
            }
        }
        
        return result;
    }

int main()
{
    string s = "aa";

    int ans = maxLengthBetweenEqualCharacters(s);

    cout<<"the length of the longest substring between two equal characters, excluding the two characters: "<<ans;
}
