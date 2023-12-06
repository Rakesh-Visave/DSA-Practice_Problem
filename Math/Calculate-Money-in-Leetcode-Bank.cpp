// LEETCODE -- 1716.Calculate Money in Leetcode Bank


#include<iostream>
using namespace std;

    int totalMoney(int n) {
        int result = 0;
        
        int monday_money = 1;
        
        while(n > 0) {
            
            int money = monday_money;
            for(int day = 1; day <= min(n, 7); day++) {
                result += money++;
            }            
            n  -= 7;
            monday_money += 1;
        }
        
        return result;
    }


int main()
{
    int n = 4;
    int ans  = totalMoney(n);

    cout<<"the total amount of money he will have in the Leetcode bank at the end of the nth day: "<<ans;

}
