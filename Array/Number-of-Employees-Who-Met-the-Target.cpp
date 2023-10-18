// LEETCODE -- 2798.Number of Employees Who Met the Target
#include<iostream>
#include<vector>
using namespace std;


    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for (int x : hours) {
            ans += x >= target;
        }
        return ans;
    }

int main()
{
    vector<int> hours = {0,1,2,3,4};
    int target = 2;

    int ans = numberOfEmployeesWhoMetTarget(hours,target);
    cout<<"There are "<<ans<<"  employees who met the targe:";

}
