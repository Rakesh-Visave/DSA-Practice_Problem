// LEETCODE -- 844. Backspace String Compare

#include<iostream>
using namespace std;

     string buildString(string &s) {
        int n = s.length();
        string temp = "";
        
        int i = 0;
        while(i < n) {
            if(s[i] != '#') {
                temp.push_back(s[i]);
            } else if(!temp.empty()) {
                temp.pop_back();
            }
            i++;
        }
        
        return temp;
    }
    bool backspaceCompare(string s, string t) {
         return buildString(s) == buildString(t);
    }


int main()
{
    string s ="ab#c";
    string t = "ad#c";

    bool ans = backspaceCompare(s,t);

    if(ans)
        cout<<"Both are same";
    else   
        cout<<"both are not Equal";
}
