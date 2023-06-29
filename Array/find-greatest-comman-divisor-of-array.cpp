#include<iostream>
#include<vector>
using namespace std;

    int findGCD(vector<int>& nums) {
        int l = nums.size();
       int maxi=-99999;
       int mini=99999;

       for(int i=0;i<l;i++){
           maxi=max(maxi,nums[i]);
           mini=min(mini,nums[i]);
       }
     
    while (mini != 0) {
        int temp = mini;
        mini = maxi % mini;
        maxi = temp;
    }
    return maxi;

    }

int main(){

    vector<int> nums = {2,5,6,9,10};

    int ans = findGCD(nums);

    cout<<" the greatest common divisor is: "<<ans;
}
