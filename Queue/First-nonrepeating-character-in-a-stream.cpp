// GFG -- First non-repeating character in a stream
#include<bits/stdc++.h>
using namespace std;

		string FirstNonRepeating(string A){

            // creat map to store char and their frequency
		   unordered_map<char,int> count;
		   queue<char> q;
		   string ans = "";
		   
		   for(int i = 0; i<A.length(); i++)
		   {
		       char ch = A[i];
		       count[ch]++;
		       
		       q.push(ch);
		       
		       while(!q.empty())
		       {    
                // if count >1 character is reapting
		           if(count[q.front()] > 1)
		               q.pop();
		
		           else
		           {
                        // character is not reapting so store into the answer string
		                ans.push_back(q.front());
		                break;
		            }
		       }  
            //    if character is reapting then we  pop element from q  and if finally  q empty then store # 
		       if(q.empty())
		          ans.push_back('#');
		  
		  }
		  return ans;
		}


int main()
{
    string a = "aabc";

    string ans = FirstNonRepeating(a);

    cout<<"first non reapeating Character is: "<<ans;
}