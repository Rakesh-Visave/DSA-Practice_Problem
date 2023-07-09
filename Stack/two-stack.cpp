// CODESTUDIO -- two stack

#include <bits/stdc++.h> 
class TwoStack {

    int size;
    int top1;
    int top2;
    int *arr;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
         top1 = -1;
         top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
            if(top2 - top1 > 1)
            {
                top1++;
                arr[top1] = num;
            }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2 -top1 >1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 >=0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
            return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        
        if(top2 <size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};


int main()
{
    TwoStack st(7);
    st.push1(10);
    st.push1(20);

    st.push2(70);
    st.push2(60);

    int poppedValue1 = st.pop1();
    int poppedValue2 = st.pop2();

    if(poppedValue1 != -1)
        cout<<"The Popped Value is: "<<poppedValue


}
