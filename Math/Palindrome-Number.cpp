// LEETCODE -- 9. Palindrome Number
#include<iostream>
using namespace std;

    bool isPalindrome(int x) {
    
        int temp = x;
        long long rev = 0;
        while(x > 0)
        {
            int r = x % 10;
            rev = (rev*10) + r;
            x = x/10;
        }
        if(rev == temp)
            return true;
        else
            return false;  
    }

int main()
{
    int x = 121;
    bool ans = isPalindrome(x);
    if(ans)
        cout<<"The given number: "<<x<<" is palindrome";
    else    
        cout<<"The given number: "<<x<<"is Not palindrome";
}