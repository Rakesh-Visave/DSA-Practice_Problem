// LEETCODE 2114. Maximum Number of Words Found in Sentences

#include<iostream>
#include<vector>
using namespace std;

int mostWordsFound(vector<string>& sentences) {

    int maxLength = 0;
    for(string sentence : sentences){
        int word = 1;
        for(char currChar : sentence){
            if(currChar == ' ')
                word += 1;
        }
        maxLength = max(maxLength,word);
    }
    return maxLength;     
}

int main()
{
    vector<string> sentences = {"alice and bob love leetcode", 
                               "i think so too",
                               "this is great thanks very much"
    };

    int maxWordCount = mostWordsFound(sentences);
    cout<<" maximum number of words is "<<maxWordCount;

}