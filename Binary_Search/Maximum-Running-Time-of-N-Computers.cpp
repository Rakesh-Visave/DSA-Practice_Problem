// LEETCODE -- 2141.Maximum Running Time of N Computers

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    bool possible(vector<int>& batteries , long long mid_minutes , int n)
    {
        long long target_minutes = n*mid_minutes;

        for(int i = 0; i<batteries.size(); i++)
        {
            target_minutes -= min((long long)batteries[i], mid_minutes);

            if(target_minutes <= 0)
                return true;
        }
        return false;
    }


    long long maxRunTime(int n, vector<int>& batteries) {
        long long s = *min_element(begin(batteries), end(batteries));
        
        long long sum_total_minutes = 0;
        for(auto &mints : batteries)
            sum_total_minutes += mints;
        
        long long e = sum_total_minutes / n;

        long long result = 0;

        while(s <= e)
        {
            long long mid_minutes = s +(e-s)/2;

            if(possible(batteries, mid_minutes, n))
            {
                result = mid_minutes;
                s = mid_minutes + 1;

            }
            else
                    e = mid_minutes - 1;
        }
        return result;
    }

int main()
{
    vector<int> batteries = {3,3,3};
    int n = 2;

    long long ans = maxRunTime(n,batteries);
    cout<<"maximum number of minutes we can run all the n computers simultaneously: "<<ans; 
}

