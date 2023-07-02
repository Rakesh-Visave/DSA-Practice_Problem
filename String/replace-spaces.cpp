#include <bits/stdc++.h> 
#include<string>
using namespace std;

string replaceSpaces(string &str){
	string temp = "";
    
	for (int i = 0; i < str.length(); i++) 
	{
          if (str[i] == ' ') 
		  {
			  temp.push_back('@');
			  temp.push_back('4');
			  temp.push_back('0');
          } 
		  else 
		  {
			  temp.push_back(str[i]);
		  }
	}
    return temp;
}

int main()
{
    string str = "Coding Ninjas Is A Coding Platform";

    string ans = replaceSpaces(str);

    cout<<"After Replacing the White Spaces by @40 the string is: "<<ans;
}