// LEETCODE -- 1496.Path Crossing

#include<iostream>
#include<unordered_set>
using namespace std;

    bool isPathCrossing(string path) {
        unordered_set<string> st;
        
        int x = 0;
        int y = 0;
        string key = to_string(x) + "_" + to_string(y);
        st.insert(key);
        
        for(char &ch : path) {
            if(ch == 'E') {
                x += 1;
            } else if(ch == 'W') {
                x -= 1;
            } else if(ch == 'N') {
                y += 1;
            } else {
                y -= 1;
            }
            
            key = to_string(x) + "_" + to_string(y);
            if(st.find(key) != st.end()) {
                return true;
            }
            
            st.insert(key);
        }
        
        return false;
    }


int main()
{
    string path  = "NES";

    bool ans = isPathCrossing(path);

    if(ans)
        cout<<"the path visits the origin twice.";
    else
        cout<<"the path doesn't cross any point more than once.";
}