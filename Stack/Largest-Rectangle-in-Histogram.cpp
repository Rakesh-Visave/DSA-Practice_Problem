#include<iostream>
#include<vector>
#include<stack>
using namespace std;

    vector<int> nextSmallerElement(vector<int> arr , int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);

        for(int i = n-1; i >= 0; i--)
        {
            int curr = arr[i];
            while( st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr,int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);

        for(int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while( st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();


        // gives nextSmallerElement indexes in vector
        vector<int>next(n);
        next = nextSmallerElement(heights , n);

        // gives prevSmallerElement indexs in vector
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = -99999;

        for(int i = 0; i<n; i++)
        {
            int l = heights[i];
            if(next[i]  == -1)
            {
                next[i] = n;
            }
            // after getting prev and next we need to find width w = next-prev-1
            int w = next[i] - prev[i] -1;

            // calculate area of ractangle
            int finalArea = l*w;

            // find maximum area 
            area = max(area,finalArea);

        }
        return area;

        
    }


int main()
{
    vector<int> heights = {2,1,5,6,2,3};

    int ans = largestRectangleArea(heights);

    cout<<"The Largest Araay Rectangle is: "<<ans;


}