#include<iostream>
#include<string>
#include<vector>
using namespace std;




    vector<string> cellsInRange(string s) {
        char col1 = s[0];
        char col2 = s[3];
        char row1 = s[1];
        char row2 = s[4];

        vector<string> ans;

        for(int i =col1 ; i<= col2; i++)
        {
            for(int j = row1; j <=row2; j++)
            {
                ans.push_back(string(1,i)+string(1,j));
             
            }
        }
        return ans;
        
    }

int main()
{
    string s =  "K1:L2";

    vector<string > ans = cellsInRange(s);

    for(string i : ans)
    {
        cout<<i<<" ";
    }



}