// GEEK-FOR-GEEKS -- Replace all 0's with 5


#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

int convertFive(int n) {

    string s = to_string(n);
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '0')
        {
            s[i] = '5';
        }
    }
    int nums = stoi(s);
    return nums;
}

int main()
{
    int n = 1005;

    int ans = convertFive(n);

    cout<<"After Replacing 0 with 5 the Answer is: "<<ans;
}