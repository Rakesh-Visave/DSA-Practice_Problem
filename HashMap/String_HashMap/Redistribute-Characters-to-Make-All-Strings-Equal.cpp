// LEETCODE -- 1897.Redistribute Characters to Make All Strings Equal
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


    bool makeEqual(vector<string>& words) {
         int n = words.size();
        unordered_map<char, int> count;

        for (string& word : words) {
            for (char &ch : word) {
                count[ch]++;
            }
        }

        for (auto &it : count) {
            if (it.second % n != 0) {
                return false;
            }
        }

        return true;
    }

int main()
{
    vector<string> words = {"abc","aabc","bc"};

    bool ans = makeEqual(words);

    if(ans)
        cout<<" if you can make every string in words equal using any number of operations";
    else
        cout<<" if you can  not make every string in words equal using any number of operations";
}
