#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

    unordered_set<string> st;
    int t[301];
    int n;
    
    bool solveMem(string &s, int idx) {
        
        if(idx == n) {
            return true;
        }
        
        if(t[idx] != -1)
            return t[idx];
        
        for(int l = 1; l<=n; l++) {
            
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solveMem(s, idx+l))
                return t[idx] = true;
            
        }
        
        return t[idx] = false;
    }
    

    bool solveTab(string s, vector<string>& wordDict) {
        unordered_set<string> st(begin(wordDict), end(wordDict));
        int n = s.length();
        vector<bool> t(n+1, false);
       
        
        t[0] = true; 
        
        for(int i = 1; i<=n; i++) {
           
            for(int j = 0; j<i; j++) {
                string temp = s.substr(j, i-j);
                
                if(st.count(temp) && t[j]) {
                    t[i] = true;
                    break;
                }
            }
        }
        return t[n]; 
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        // // Approach-1 Memoization
        // n = s.length();
        
        // memset(t, -1, sizeof(t));
        
        // for(string &word : wordDict) {
        //     st.insert(word);
        // }
        
        // return solveMem(s, 0);

        
        // Approch-2 Tabulation
        return solveTab(s, wordDict);
    }



int main() {
    string inputString = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    bool result = wordBreak(inputString, wordDict);

    cout << "Can the string be segmented: " << (result ? "Yes" : "No") << endl;

    return 0;
}
