// LEETCODe -- 1436.Destination City
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


    string destCity(vector<vector<string>>& paths) {
         unordered_map<string, int> mp;
        
        for(auto &path : paths) {
            string source = path[0]; //outdegree
            mp[source]++;
        }
        
        for(auto &path : paths) {
            string dest = path[1];
            
            if(mp[dest] == 0) {
                return dest;
            }
        }
        
        return "";
    }


int main()
{
    vector<vector<string>> paths = {{"London","New York"}, {"New York","Lima"}, {"Lima","Sao Paulo"}};

    string ans = destCity(paths);

    cout<<"the destination city, that is, the city without any path outgoing to another city: "<<ans;
}