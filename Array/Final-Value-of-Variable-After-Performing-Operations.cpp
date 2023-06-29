#include<iostream>
#include<vector>

using namespace std;

    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int x = 0;
        for(int i = 0; i < n; i++)
        {
            if(operations[i][1] == '+')
            {
                x++;
            }
            else{
                x--;
            }
            
        }
        return x;
        
    }

int main(){

    vector<string> operations ={ "--X","X++","X++"   };

    int x  = finalValueAfterOperations(operations);

    cout<<"The Value of X is"<<x;
}