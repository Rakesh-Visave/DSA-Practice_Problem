// LEETCODE -- 1704.Determine if String Halves Are Alike

#include<iostream>
using namespace std;

      bool isVowel(char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    bool halvesAreAlike(string s) {
        int n = s.length();
        
        int mid = n/2;
        
        int i = 0, j = mid;
        
        int countL = 0;
        int countR = 0;
        
        while(i < n/2 && j < n) {
            if(isVowel(s[i])) countL++;
            
            if(isVowel(s[j])) countR++;
            
            i++;
            j++;
        }
        
        
        return countL == countR;
    
    }

int  main()
{
    string s = "book";
    bool ans = halvesAreAlike(s);
    if(ans)
        cout<<"string is alike";
    else
        cout<<"String is NOt alike";
}
