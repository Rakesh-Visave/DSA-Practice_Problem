// CODESTUDIO -- Redundant Brackets
// GEEKFORGEEKS -- Expression contains redundant bracket or not

#include <bits/stdc++.h> 
#include<stack>
#include<iostream>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<int> st;
    for(int i = 0; i<s.length(); i++)
    {
        char ch = s[i];
        if(ch =='(' ||ch =='+' ||ch =='-' ||ch =='*' ||ch =='/')
        {
            st.push(ch);
        }
        else
            if(ch ==')')
            {
                bool isRedundant = true;
                while(st.top() !='(')
                {
                    char top = st.top();
                    if(top =='+' ||top =='-' ||top =='*' ||top =='/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant)
                    return true;
                
                st.pop();
            }
    }
    return false;
}

int main()
{
    string s = "(a+b+(c+d))";
    bool ans = findRedundantBrackets(s);

    if(ans)
        cout<<"The String is having a prarenthesis / string not Balanced";
    else    
        cout<<"The String is  balanced";
}

