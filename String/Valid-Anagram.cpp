// LEETCODE -- 242.Valid Anagram

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

    bool isAnagram(string s, string t) {
        sort(begin(s), end(s));
        sort(begin(t), end(t));
        
        return s == t;
    }


int main()
{
    string s =  "anagram";
    string t = "nagaram";

    bool ans = isAnagram(s,t);

    if(ans)
        cout<<"The string is a valid Anagram";
    else
        cout<<"The String is not Anagram";
}