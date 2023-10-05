
#include<bits/stdc++.h>
using namespace std;



    long long int countAtMostK(string s, int k) {
        long long int cnt = 0;
        int freq[26] = {0};
        int i = 0, diff = 0;

        for (int j = 0; j < s.size(); ++j) {
            if (!freq[s[j] - 'a'])
                ++diff;
            ++freq[s[j] - 'a'];

            while (diff > k && i <= j) {
                --freq[s[i] - 'a'];
                if (!freq[s[i] - 'a'])
                    --diff;
                ++i;
            }
            cnt += j - i + 1;
        }

        return cnt;
    }
    long long int substrCount (string s, int k) {
    	   return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }


int main()
{
    string s = "aba";
    int k = 2;

    long long int ans = substrCount(s,k);
    cout<<"The Number of substrings are: "<<ans;
}