#include<iostream>
using namespace std;

class stack{

        public:
        int *arr;
        int top ;
        int size;
        
        stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element){
            if(size - top > 1){
                top++;
                arr[top] = element;
            }
            else
                cout<<"Stack OverFlow";
        }

        void pop(){
            if(top >=0)
                top--;
            else
                cout<<"Stack underFlow";
        }

        bool isEmpty(){
            if(top == -1)
                return true;
            else
                return false;
        }


        int peek(){   
            if(top >=0)
                return arr[top];
            else{  
                cout<<"Stack is Empty";
                return -1;
            }
        }
};

int main()
{
    stack st(5);
    st.push(10);
    st.push(15);
    st.push(17);

    st.pop();
    st.pop();

    cout<<"the Top element is: "<<st.peek();

}