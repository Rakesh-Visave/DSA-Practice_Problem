// LEETCODE 1662.Check If Two String Arrays are Equivalent

#include<iostream>
#include<vector>
using namespace std;


    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
         int idx1 = 0, idx2 = 0, arrIdx1 = 0, arrIdx2 = 0;
        while (arrIdx1 < word1.size() && arrIdx2 < word2.size()) {
            if (word1[arrIdx1][idx1] != word2[arrIdx2][idx2]) {
                break;
            }
            ++idx1;
            if (idx1 == (word1[arrIdx1]).size()) {
                idx1 = 0;
                ++arrIdx1;
            }
            ++idx2;
            if (idx2 == (word2[arrIdx2]).size()) {
                idx2 = 0;
                ++arrIdx2;
            }
        }
        return arrIdx1 ==(word1).size() && arrIdx2 == (word2).size();
    }


int main()
{
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "bc"};

    bool ans = arrayStringsAreEqual(word1,word2);

    if(ans)
        cout<<"the Two String array represent the same string.";
    else
        cout<<"The Two Strig array not represent the same string.";
}
