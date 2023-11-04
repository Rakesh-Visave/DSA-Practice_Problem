
#include<iostream>
#include<vector>
using namespace std;


    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
      int result = 0;
        
        for(int &x : left) {
            result = max(x, result);
        }
        
        for(int &x : right) {
            result = max(result, n-x);
        }
        
        return result;   
    }


int main()
{
    vector<int> left = {4,3};
    vector<int> right = {0,1};

    int n  =4;

    int ans = getLastMoment(n,left,right);

    cout<<"The last moment when an ant was on the plank is t:"<<ans;
}