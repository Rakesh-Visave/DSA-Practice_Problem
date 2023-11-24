// leetcodE -- 1561.Maximum Number of Coins You Can Get


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    int maxCoins(vector<int>& piles) {
          int n = piles.size();
        
        sort(begin(piles), end(piles));
        
        int result = 0;
        
        int Bob = 0, Me = n-2, Alice = n-1;
        
        while(Me > Bob) {
            
            result += piles[Me];
        
            Me    -= 2;    
            Bob   += 1;
            Alice -= 2; //(You can remove this becasue it's required. I Used it for the sake of completeness)
        }
        
        return result;
}


int main()
{
    vector<int> piles = {2,4,1,2,7,8};
    int ans  = maxCoins(piles);

    cout<<"the maximum number of coins that you can have: "<<ans;
}