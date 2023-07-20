#include <iostream>
#include <stack>
using namespace std;

/*
last in first out
*/
int main(){
    stack<string>s;
    s.push("nidhish");
    s.push("anil");
    s.push("wakodikar");

    cout<<"top element     "<<s.top()<<endl;
    s.pop();
    cout<<"top element     "<<s.top()<<endl;

    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;

}
