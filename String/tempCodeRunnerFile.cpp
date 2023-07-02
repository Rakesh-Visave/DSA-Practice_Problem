#include <bits/stdc++.h> 
#include<string>
#include<algorithm>
#include<iostream>
// using namespace std;

char toLowerCase(char ch) 
{
  if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
   else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isAlphaNumeric(char ch) {
    return isalnum(ch);
}

bool checkPalindrome(string s)
{

        int st = 0;
        int e = s.size()-1;

        while (st <= e) {
            if(!isAlphaNumeric(s[e]))
                e--;
            
            if(!isAlphaNumeric( s[st] ))
                st++;

            if(toLowerCase( s[st] ) != toLowerCase( s[e] ))
               return 0;

            else {

                st++;
                e--;
            
            }
        
        }
        return 1;
}

int main()
{
    string s = "A1b22Ba";

    bool ans  = checkPalindrome(s);

    cout<<"The String is  pallindrome: "<<ans;
}