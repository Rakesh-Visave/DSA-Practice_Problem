// GFG -- Find the String


#include <bits/stdc++.h>
using namespace std;


      void dfs(int k, string prev, unordered_set<string> &seen, string &edges) {
        for (char i = '0'; i <= ('0' + k - 1); i++) {
            string cur = prev + i;
            if (seen.find(cur) == seen.end()) {
                seen.insert(cur);
                dfs(k, cur.substr(1), seen, edges);
                edges += i;
            }
        }
    }
    string findString(int n, int k) {
         unordered_set<string> seen;
        string startingNode = string(n - 1, '0');
        string edges;
        dfs(k, startingNode, seen, edges);

        string ret = edges + startingNode;
        return ret;
    }

int main()
{
    int n =2;
    int k = 2;

    string ans = findString(n,k);

    cout<<"Answer is: "<<ans;
}