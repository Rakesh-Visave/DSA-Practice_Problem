#include<iostream>
#include<vector>
using namespace std;

    vector<vector<int>> result;
    void solve(int start, int &n, int k, vector<int> &temp)
    {
        // base cases
        if(k == 0)
        {
            result.push_back(temp);
            return;
        }
        if(start > n)
            return;
        
        // first element is picked
        temp.push_back(start);
        solve(start+1, n, k-1, temp);
        temp.pop_back();  

        //  first element is not picked and going to next element
        solve(start+1, n, k, temp);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,n,k,temp);
        return result;
        
    }
int main()
{
    int n = 4; 
    int k = 2; 

    vector<vector<int>> combinations = combine(n, k);

    cout << "All combinations of size " << k << " out of " << n << " numbers are:" << endl;
    for (const vector<int> &combination : combinations)
    {
        cout << "[";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

}




