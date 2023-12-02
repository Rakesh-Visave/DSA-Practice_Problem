// LEETCODE -- 1160.Find Words That Can Be Formed by Characters

#include<iostream>
#include<vector>
using namespace std;

    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCount(26, 0);
        
        for(char &ch : chars) {
            charCount[ch-'a']++;
        }
        
        int result = 0;
        
        for(string &word : words) {
            
            vector<int> wordCount(26, 0);
            for(char &ch : word) {
                wordCount[ch-'a']++;
            }
            
            bool ok = true;
            for(int i = 0; i < 26; i++) {
                if(wordCount[i] > charCount[i]) {
                    ok = false;
                    break;
                }
            }
            
            if(ok)
                result += word.size();
            
        }
        
        return result;
        
    }


int main()
{
    vector<string> words = {"cat","bt","hat","tree"};
    string chars = "atach";

    int ans = countCharacters(words,chars);

    cout<<"the sum of lengths of all good strings in words: "<<ans;
}