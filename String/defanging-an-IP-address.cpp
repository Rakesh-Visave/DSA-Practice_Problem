// LEETCODE - 1108. Defanging an IP Address

#include<iostream>
using namespace std;

    string defangIPaddr(string address) {
        string defagedString = "";
        
        for(auto character : address)
        {
            if(character == '.')
                defagedString.append("[.]");
            else
                defagedString.push_back(character);
        }
        return defagedString;
        
    }


int main()
{
    // string address = "1.1.1.1";
    string address = "255.100.50.0";

    string defagedString  = defangIPaddr(address);

    cout<<"Defaged String is :"<<defagedString;
}
