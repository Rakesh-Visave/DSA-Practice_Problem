#include<iostream>
#include<vector>
using namespace std;

    int compress(vector<char>& chars) {

        int i = 0; 
        int ansIndex = 0;
        int n = chars.size();

        while(i < n)
        {
            int j = i+1;
            while(j < n && chars[i] == chars[j])
            {
                j++;
            }
            chars[ansIndex] = chars[i];
            ansIndex++;
            int count = j - i;
            if(count > 1)
            {
                string cnt = to_string(count);
                for(char ch : cnt)
                {
                    chars[ansIndex] = ch;
                    ansIndex++;
                }
            }
            i = j;
        }
        return ansIndex;   
    }

int main()
{
    vector<char> chars  = {'a',
    'b','b','c','c','c'};
    int ans = compress(chars);

    cout<<"After modifying the input array, the new length of the array: "<<ans;   

}