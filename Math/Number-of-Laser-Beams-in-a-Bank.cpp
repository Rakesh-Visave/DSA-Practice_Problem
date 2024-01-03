// LEETCODE -- 2125.Number of Laser Beams in a Bank
#include<iostream>
#include<vector>
using namespace std;

    int numberOfBeams(vector<string>& bank) {
          int n = bank.size();
        
        int prevDeviceCount = 0;
        int result    = 0;
        
        for(int i = 0; i<n; i++) {
            
            int currDeviceCount = 0;
            for(char &ch : bank[i]) {
                if(ch == '1') {
                    currDeviceCount++;
                }
            }
            
            result += (prevDeviceCount * currDeviceCount);
            
            prevDeviceCount = currDeviceCount == 0 ? prevDeviceCount : currDeviceCount;
            
        }
        
        return result;
    }

int main()
{
    vector<string> bank = {"011001","000000","010100","001000"};

    int ans = numberOfBeams(bank);

    cout<<"The total number of laser beams in the bank:"<<ans;
}