// LEETCODE -- 2433. Find The Original Array of Prefix Xor

#include<iostream>
#include<vector>
using namespace std;


    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        for(int i = n-1; i>0; i--)
        {
            pref[i] = (pref[i] ^ pref[i-1]);
        }
        return pref;
    }

int main()
{
    vector<int> pref = {5,2,0,3,1};
    vector<int> ans = findArray(pref);

    cout<<"After XOR operation the Array will be:";
    for(int i : ans)
        cout<<" "<<i;


}