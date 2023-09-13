
#include <bits/stdc++.h>
using namespace std;


    string findLargest(int N, int S){
         if ((!S && N > 1) || N * 9 < S) {
            return "-1";
        }
        string out;
        for (int i = 0; i < N; ++i) {
            if (S >= 9) {
                out += '9';
                S -= 9;
            } else {
                if (S) {
                    out += to_string(S);
                    S = 0;
                } else {
                    out += '0';
                }
            }
        }
        return out;
    }

int main()
{
    int n = 3;
    int s = 20;

    string ans = findLargest(n,s);
    cout<<"he largest number that can be formed: "<<ans;
    
}