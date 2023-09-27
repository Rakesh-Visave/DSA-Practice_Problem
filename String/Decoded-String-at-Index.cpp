// LEECTODE -- 880.Decoded String at Index


#include<iostream>
#include<cstring>
using namespace std;

    string decodeAtIndex(string S, int K) {
          int n = S.length();
        long long size = 0;
        
        for(char ch:S) {
            if(isdigit(ch)) {
                size = size*(ch-'0');
            } else {
                size++;
            }
        }
        
        for(int i = n-1; i>=0; i--) {
            K = K%size;
            
            if(K == 0  && isalpha(S[i]))
                return string(1, S[i]);
            
            if(isalpha(S[i]))
                size--;
            else
                size = size/(S[i]-'0');
        }
        
        return "";
        
    }


int main()
{
    string s = "leet2code3";
    int k = 10;
    string ans = decodeAtIndex(s,k);

    cout<<"Answer is :"<<ans;
}

