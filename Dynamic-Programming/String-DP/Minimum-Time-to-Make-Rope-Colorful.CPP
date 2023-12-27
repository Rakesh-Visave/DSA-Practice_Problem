// leetcode -- 1578.Minimum Time to Make Rope Colorful

#include<iostream>
#include<vector>
using namespace std;

    int minCost(string colors, vector<int>& neededTime) {
           int n = colors.size();
        
        int time    = 0;
        int prevMax = 0;
        
        for(int i = 0; i<n; i++) {
            
            if(i > 0 && colors[i] != colors[i-1]) {
                prevMax = 0;
            }
            
            
            
            int curr = neededTime[i];
            
            time += min(prevMax, curr); //greedily
            
            prevMax = max(prevMax, curr);
            
        }
        
        return time;   
    }

int main()
{
    vector<int> neededTime = {1,2,3,4,5};
    string colors = "abaac";

    int ans = minCost(colors,neededTime);

    cout<<" the minimum time Bob needs to make the rope colorful: "<<ans; 
}