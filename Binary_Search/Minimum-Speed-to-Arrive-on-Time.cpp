// LEETCODE -- 1870.Minimum Speed to Arrive on Time

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

    double isPossible(vector<int> &dist, int midSpeed)
    {
        double time = 0.0;
        int n = dist.size();

        for(int i = 0; i<n-1; i++)
        {
            double t = (double)dist[i] / (double)midSpeed;
            time +=ceil(t);
        }
        time += (double)dist[n-1] / (double)midSpeed;
        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 1;
        int e = 1e7;

        int minSpeed = -1;
        while(s <= e)
        {
            int midSpeed = s + (e-s)/2;
            if(isPossible(dist,midSpeed) <= hour)
            {
                minSpeed = midSpeed;
                e = midSpeed - 1;
            }
            else
                s = midSpeed + 1; 
        }
        return minSpeed;
    }   

int main()
{
    vector<int> dist = {1,3,2};
    double hour = 6.0;

    int ans = minSpeedOnTime(dist,hour);
    cout<<"minimum  speed that all the trains must travel  to reach the office on time is: "<<ans;   
}

