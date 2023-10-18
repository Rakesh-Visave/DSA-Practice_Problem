// LEETCODE  -- 1816.Truncate Sentence

#include<iostream>
using namespace std;

    string truncateSentence(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && (--k) == 0) {
                return s.substr(0, i);
            }
        }
        return s;
    }

int main()
{
    string s = "Hello how are you Contestant";
    int k = 4;

    string ans = truncateSentence(s,k);
    cout<<"first k words are: "<<ans;
}