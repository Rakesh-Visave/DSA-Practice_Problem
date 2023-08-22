//LEETCODE --  168.Excel Sheet Column Title

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

    string convertToTitle(int columnNumber) {
         string s;
        
        while(columnNumber) {
            columnNumber--;
            
            int remain = columnNumber%26;
            char ch    = remain + 'A';
            s.push_back(ch);
            
            columnNumber /= 26;
            
        }
        
        reverse(begin(s), end(s));
        return s;
        
    }
int main()
{
    int coln = 28;
    string ans = convertToTitle(coln);
    cout<<"its corresponding column title as it appears in an Excel sheet is: "<<ans;
}
