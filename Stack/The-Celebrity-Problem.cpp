#include<iostream>
#include<vector>
#include<stack>
using namespace std;

     bool knows(vector<vector<int>>& M, int a, int b, int n)
     {
         if(M[a][b] == 1)
             return true;
         else
            return false;
     }
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int> s;
        // step- 1 Push All elment in Stack
        for(int i = 0; i < n; i++)
        {
           s.push(i);
        }
       
       while(s.size() >1)
       {
           int a = s.top();
           s.pop();
           
           int b = s.top();
           s.pop();
           
        //  Step -2  check A knows B or B knows A
           if(knows(M,a,b,n))
               s.push(b);
           else
               s.push(a);
       }
    //    step -3 here we get one candidate who can be potential celebrity 
    //    here verify the celebrity
                // -by all row 0 count == n
                // - all Col 1 count == n-1



        int candidate = s.top();
        // -by all row 0 count == n
        int rowZeroCount = 0;
        for(int i = 0; i< n; i++)
        {
            if(M[candidate][i] == 0)
                 rowZeroCount++;
        }
         if(rowZeroCount  != n)
            return -1;
         
        // - all Col 1 count == n-1
         int colZeroCount = 0;
         for(int i = 0; i< n; i++)
         {
             if(M[i][candidate] == 1)
                 colZeroCount++;
         }
         if(colZeroCount  != n-1)
           return -1;
         
    return candidate;
         
       
}

int main()
{
    vector<vector<int>> M = { {0,1,0}, {0,0,0}, {0,1,0} };
    int n = 3;

    int ans = celebrity(M,n);

    cout<<"The Celebrity person is: "<<ans;
}
