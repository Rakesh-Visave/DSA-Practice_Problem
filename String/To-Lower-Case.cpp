// LEETCODE -- 709.To Lower Case
#include<iostream>
using namespace std;


    string toLowerCase(string s) {
         for(int i = 0; i < s.size(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                s.replace(i,1,1,s[i]+'a'-'A');
            }
        }
        return s;
    }


int main()
{
    string s = "Rakesh";
    string ans = toLowerCase(s);

    cout<<"To Lower Case: "<<ans;

}