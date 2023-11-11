#include<iostream>
#include<unordered_map>
using namespace std;


#define MAX_CHARS 256



    bool areIsomorphic(string str1, string str2)
    {
        
       if (str1.size() != str2.size())
            return false;

        unordered_map<char, char> mp1, mp2;
        for (int i = 0; i < str1.size(); i++) {
            mp1[str1[i]] = str2[i];
            mp2[str2[i]] = str1[i];
        }

        for (int i = 0; i < str1.size(); i++) {
            if ((mp1[str1[i]] != str2[i]) || (mp2[str2[i]] != str1[i]))
                return false;
        }
        return true;
        
    }

int main()
{
    string str1 = "aab";
    string str2 = "xxy";

    bool ans = areIsomorphic(str1,str2);

    if(ans)
        cout<<"Given string is isomorphic";
    else
        cout<<"Given string is not isomorphic";
    
}