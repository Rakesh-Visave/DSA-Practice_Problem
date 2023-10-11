//LEETCODE  --  2251.Number of Flowers in Full Bloom

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
         int m = flowers.size();
        int n = people.size();
        
        vector<int> result(n);
        
        vector<int> start_time(m);
        vector<int> end_time(m);
        
        for(int i = 0; i<m; i++) {
            start_time[i] = flowers[i][0];
            end_time[i]   = flowers[i][1];
        }
        
        sort(begin(start_time), end(start_time));
        sort(begin(end_time), end(end_time));
        
        for(int i = 0; i<n; i++) {
            int bloomed_already = upper_bound(begin(start_time), end(start_time), people[i]) - begin(start_time);
            
            int died_already    = lower_bound(begin(end_time), end(end_time), people[i]) - begin(end_time);

            result[i] = bloomed_already - died_already;
            
        }
        
        return result;
    }


int main()
{
     vector<vector<int>> flowers = {{1,6},{3,7},{9,12},{4,13}};
     vector<int> people = {2,3,7,11};

     vector<int> ans = fullBloomFlowers(flowers , people);
     cout<<"Answer is:";
     for(int i : ans)
     {
        cout<<i << " ";

     }

}