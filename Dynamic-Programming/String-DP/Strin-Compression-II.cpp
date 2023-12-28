//1531. LEETCODE -- String Compression II

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

    int n;
    vector<vector<int>> t;
    int solve(int i, int k, string &s) {
        if(k < 0) {
            return 100000;
        }

        if(i >= n || (n-i) <= k) {
            return 0;
        }

        if(t[i][k] != -1) {
            return t[i][k];
        }

        int delete_i = solve(i+1, k-1, s);

        int keep_i = INT_MAX;
        
        int deleted  = 0;
        int freq     = 0;
        int addition = 0;

        for(int j = i; j < n && deleted <= k; j++) {
            if(s[j] == s[i]) {
                freq++;
                if(freq == 2 || freq == 10 || freq == 100) {
                    addition++;
                }
            } else {
                deleted++;
            }

            keep_i = min(keep_i, 1 + addition + solve(j+1, k-deleted, s));
        }

        return t[i][k] = min(delete_i, keep_i);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
        t = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, s);
    }


int main()
{
    string s  = "aaabcccd";
    int k  =2;

    int ans = getLengthOfOptimalCompression(s,k);
    cout<<"he minimum length of the run-length encoded version of s after deleting at most k characters: "<<ans;
}

