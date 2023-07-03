// LEETCODE_1832 --Check if the Sentence Is Pangram

#include<iostream>
#include<string>
using namespace std;

    bool checkIfPangram(string sentence) {

        int arr[26] = {0};
        for(int i = 0; i<sentence.size(); i++){
            char ch = sentence[i];
            int number =  ch - 'a';
            arr[number]++;
        }    
            
        for(int i = 0; i<26; i++)
        {
            if(arr[i] == 0)
                return false;
        }
        return true;
    }


int main()
{
    string sentence = "thequickbrownfoxjumpsoverthelazydog";

    bool ans = checkIfPangram(sentence);

    if(ans)
        cout<<"The string is pangram";
    else    
        cout<<"The string is not pangram";
}