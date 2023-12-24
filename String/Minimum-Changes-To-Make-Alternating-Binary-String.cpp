// LEETCODE -- 1758.Minimum Changes To Make Alternating Binary String

#include<iostream>
using namespace std;

    int minOperations(string s) {
       int n = s.length();
        int start_with_0 = 0;
        int start_with_1 = 0;
        
        //010101
        //101010
        for(int i = 0; i<n; i++) {
            if(i%2 == 0) {
                if(s[i] == '0') {
                    start_with_1++;
                } else {
                    start_with_0++;
                }
            } else {
                if(s[i] == '1') {
                    start_with_1++;
                } else {
                    start_with_0++;
                }
            }
        }
        
        return min(start_with_0, start_with_1); 
    }


int main()
{
    string s = "0100";

    int ans = minOperations(s);

    cout<<"the minimum number of operations needed to make s alternating: "<<ans;
}