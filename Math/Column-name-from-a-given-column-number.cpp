
#include<bits/stdc++.h>
using namespace std;

    string colName (long long int n)
    {
        string out;
        vector<char> code(26);
        for (int i = 1; i < 26; ++i)
            code[i] = (char)('A' + i - 1);
        code[0] = 'Z';

        while (n) {
            out += code[n % 26];
            if (n % 26 == 0)
                --n;
            n /= 26;
        }

        reverse(out.begin(), out.end());
        return out;
    }

int main()
{
    long long int n = 28;

    string ans = colName(n);

    cout<<"Col Name for given col Number is : "<<ans;
    
}