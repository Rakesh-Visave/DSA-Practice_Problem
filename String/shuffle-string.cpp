// LEETCODE  -- 1528. Shuffle String


#include<iostream>
#include<vector>
using namespace std;

    string restoreString(string s, vector<int>& indices) {

        string ans = s;
        for(int i = 0; i< s.size(); i++)
        {
            ans[indices[i]] = s[i];
        }
        return ans;
        
    }

int main()
{
    string s = "codeleet";
    vector<int> indices = {4,5,6,7,0,2,1,3};

    string ans = restoreString(s,indices);

    cout<<"The Suffled String is: "<<ans;
}