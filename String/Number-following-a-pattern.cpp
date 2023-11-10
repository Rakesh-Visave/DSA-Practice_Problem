// GFG -- Number following a pattern

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


    string printMinNumberForPattern(string S){
         vector<pair<char, int>> col;
        char curr = S[0];
        int c = (S[0] == 'I');
        
        for (auto i: S){
            if (i == curr)
                ++c;
            else{
                col.push_back({curr, c});
                c = 1;
                curr = i;
            }
        }               
        if (S.back() == 'I')
            ++c;
        col.push_back({curr, c});
        
        string out;
        c = 1;
        for (auto i: col){
            char op = i.first;
            int cnt = i.second + (op == 'D'? 1: -1);
            string temp;
            while (cnt--){
                temp += (char)('0' + c++);
            }
            if (op == 'D')
                reverse(temp.begin(), temp.end());
            out += temp;
        }
        return out;
    }

int main()
{
    string s = "D";

    string ans = printMinNumberForPattern(s);
    cout<<s<<" is meant for decreasing, so we choose the minimum number among all possible numbers";

    
}