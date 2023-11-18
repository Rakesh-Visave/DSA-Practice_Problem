// LEETCODe -- 2325.Decode the Message

#include<iostream>
using namespace std;


    string decodeMessage(string key, string message) {
         char d[128]{};
        d[' '] = ' ';
        char i = 'a';
        for (char& c : key) {
            if (!d[c]) {
                d[c] = i++;
            }
        }
        for (char& c : message) {
            c = d[c];
        }
        return message;      
    }


int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv"; 

    string ans = decodeMessage(key,message);

    cout<<"The Decoded String is: "<<ans;
}