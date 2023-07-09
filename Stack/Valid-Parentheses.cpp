// LEETCODE -- CODESTUDIO -- 20. Valid Parentheses

#include<iostream>
#include<stack>
using namespace std;

    bool isValid(string s) {

        stack<int> st;
        for(int i = 0; i<s.length(); i++)
        {
            char ch = s[i];
            if(ch == '{' ||ch == '[' ||ch == '(' )
            {
                st.push(ch);
            }
            else
                if(!st.empty())
                {
                    int top = st.top();
                    if(ch == '}' && top == '{' ||
                       ch == ']' && top == '[' || 
                       ch == ')' && top == '(' )
                       {
                           st.pop();
                       }
                       else
                            return false;
                }
                else
                    return false;
    
        }
        if(st.empty())
            return true;
        else
            return false;
        
    }

int main()
{
    string str  = "()[]{}";

    bool ans = isValid(str);

    if(ans)
        cout<<"The Given string is Valid";
    else    
        cout<<"The Given String is Not Valid";
}
