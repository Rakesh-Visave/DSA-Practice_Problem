#include<iostream>
#include<cstring>
using namespace std;

    bool winnerOfGame(string colors) {
         int n = colors.length();
        int alice = 0;
        int bob   = 0;
        
        for(int i = 1; i<n; i++) {
            
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1]) {
                if(colors[i] == 'A')
                    alice++;
                else
                    bob++;
            }
        }
        
        return alice > bob;
    }

int main()
{
    string colors = "AAABABB";
    bool ans = winnerOfGame(colors);
    if(ans)
        cout<<"Alice Win";
    else   
        cout<<"Bob";
}