
#include <bits/stdc++.h>
using namespace std;


    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int,int>, int> f;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int gcd = __gcd(numerator[i], denominator[i]);
            numerator[i] /= gcd;
            denominator[i] /= gcd;
            
            int x, y;
            x = numerator[i];
            y = denominator[i];
            
            int z = y - x;
            
            if(f.count({z, y}))
                ans += f[{z, y}];
            
            ++f[{numerator[i], denominator[i]}];
        }
        
        return ans;

    }

int main()
{
    // Hardcoded input
    int n = 5;
    int numerator[] = {2, 3, 4, 2, 1};
    int denominator[] = {4, 6, 8, 4, 2};

    int result = countFractions(n, numerator, denominator);
    cout << "The number of fractions with the same reduced form: " << result << endl;

    return 0;
}