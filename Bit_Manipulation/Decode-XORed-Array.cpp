// LEETCODE -- 1720. Decode XORed Array

#include<iostream>
#include<vector>
using namespace std;

    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);

        for(int i = 0; i<encoded.size(); i++)
        {
            int x = ans[i] ^ encoded[i];
            ans.push_back(x);
        }
        return ans;
        
    }

int main()
{
    vector<int> encoded = {1,2,3};
    int first = 1;

    vector<int> ans = decode(encoded,first);
    cout<<"Decoded Array is:"<<endl;
    for(int i : ans)
    {
        cout<<i<<" ";
    }
}
