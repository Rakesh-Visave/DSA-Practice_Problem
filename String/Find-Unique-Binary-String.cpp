// LEETCODe -- 1980.Find unique binary string

#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_set>
#include<bitset>

using namespace std;


    string findDifferentBinaryString(vector<string>& nums) {
       unordered_set<int> st;
        
        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));
        }
        
        int n = nums.size();
        
        string result= "";
        
        for(int number = 0; number <= n; number++) {
            if(st.find(number) == st.end()) {
                result = bitset<16>(number).to_string();
                break;
            }
        }
        
        return result.substr(16-n);   
    }


int main()
{
    vector<string> nums  = {"01","10"};

    string ans = findDifferentBinaryString(nums);

    cout<<"Answer is: "<<ans;

}