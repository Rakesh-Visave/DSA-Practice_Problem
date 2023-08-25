// GFG --- Palindrome String

 
#include <bits/stdc++.h>
using namespace std;
	
	int isPalindrome(string S)
	{
	   int i = 0, j = S.size() - 1;
	   while(i < j){
	       if(S[i] != S[j])
	        return false;
	        ++i;
	        --j;
	   }
	   return true;
	}

int main()
{
    string s = "aba";

    int ans = isPalindrome(s);
    if(ans)
        cout<<"The String is palindrome";
    else    
        cout<<"The string is not Palindrome";
        
}