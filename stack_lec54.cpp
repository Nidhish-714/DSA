// LIFO--last in first out
// push
// pop
// peek -- top element
// is empty

#include <iostream>
#include <stack>
using namespace std;

class Stack
{
    // properties
public:
    int *arr;
    int top;
    int size;

    // constructor

    Stack(int size)
    {

        // creation of stack
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    // functions

    void push(int val)
    {
        if (size - top > 1)
        { // atleast 1 k jgh hai
            top++;
            arr[top]=val;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "empty stack" << endl;
        }
    }


    int peek()
    {
        if (top >= 0  )
        {
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }

    bool isEmpty()
    {
        if(top==-1){
            return true;
        }
        else {
            return false;
        }
    }
};

int main()
{

    // stack<int>s;
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // cout<<s.top();
    Stack st(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(0);

    st.pop();
   cout<< st.peek();
}

//push 2 stack

// stack1 left se right
// stack2 right se left
// this is for proper space utilisation
//stack n/2 , n/2 allot krne m space achese utilise nhi hgi


class TwoStack{

    int* arr;
    int top1;
    int top2;
    int size;
//constructor
    TwoStack(int s){
        this->size = s;//size dedia (just number dala)
        top1 = -1;
        top2 = s;
        arr = new int [s];//array ki memory allot
    }

    void push1(int num){
        if(top2-top1>1){//space available
        top1++;
        arr[top1] = num;
        }else{
            cout<<"stack overflow"<<endl;
        }
    }
    void push2(int num){
        if(top2-top1>1){//space available
        top2--;//right se left jare
        arr[top2] = num;
        }else{
            cout<<"stack overflow"<<endl;
        }
    }
    int pop1(){
        if(top1>=0){
            int ans = arr[top1];//to return popped element
            top1--;
            return ans;
        }else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
        
    }

    int pop2(){
        if(top2<size){//jaha top point karra h udr next iteration me element ka pop push hga
            int ans = arr[top2];
            top2++;
            return ans;
        }else{
            cout<<"stack 2 is empty"<<endl;
            return -1;
        }
    }
};