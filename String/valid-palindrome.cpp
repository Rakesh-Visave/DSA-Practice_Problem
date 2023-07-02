// 125. Valid Palindrome

#include<iostream>
#include<string>
using namespace std;
    bool isValid(char ch)
    {
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')||(ch >= '0' && ch <= '9'))
        {
            return 1;
            
        }
        else
        {
            return 0;
        }
    }
    

    char toLowerCase(char ch)
    {
        if((ch >= 'a' && ch <='z') || (ch >= '0' && ch <='9') )
        {
            // cout<<ch;
            return ch;
        }
        else
        {
            char temp = ch - 'A' + 'a';
            return temp;   
           
        }
    }


    bool Palindrome(string s)
    {
        int st= 0;
        int e = s.length()-1;

        while(st <= e)
        {
            if(s[st] != s[e])
            {
                return 0;
            }
            else
            {
                st++;
                e--;    
            }
        }
        return 1;
    }

    bool isPalindrome(string s) {

        int i = 0;
        string temp = "";
        for(int j = 0; j<s.length(); j++)
        {
            if(isValid(s[j]))
            {
                temp.push_back(s[j]);
            }
        }
        for(int j = 0; j < s.length(); j++)
        {
            temp[j] = toLowerCase(temp[j]);
        }

        return Palindrome(temp);
        
    }

int main()

{
    string s = "A man, a plan, a canal: Panama";

    bool ans  = isPalindrome(s);

    cout<<ans;
}