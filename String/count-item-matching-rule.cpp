// 1773. Count Items Matching a Rule


#include<iostream>
#include<vector>
#include<string>
using namespace std;


    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

        int ans = 0;

        if(ruleKey == "type")
        {
            for(int i = 0; i < items.size(); i++ )
            {
                if(items[i][0] == ruleValue)
                {
                    ans++;
                }
            }
        }

        if(ruleKey == "color")
        {
            for(int i = 0; i < items.size(); i++ )
            {
                if(items[i][1] == ruleValue)
                {
                    ans++;
                }
            }
        }

        if(ruleKey == "name")
        {
            for(int i = 0; i < items.size(); i++ )
            {
                if(items[i][2] == ruleValue)
                {
                    ans++;
                }
            }
        }

        return ans;
        
    }


int main()
{
    vector<vector<string>> items = {
        {"phone","blue","pixel"},
        {"computer","silver","lenovo"},
        {"phone","gold","iphone"}};

        string ruleKey = "type";
        string ruleValue = "phone";

        int ans = countMatches(items,ruleKey,ruleValue);

        cout<<"the number of items matches the given rule: "<<ans;

}