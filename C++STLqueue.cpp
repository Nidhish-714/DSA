#include <iostream>
#include <queue>
using namespace std;
/*
line .....first in first out 
*/
int main(){

    queue<string>s;
    s.push("nidhish");
    s.push("anil");
    s.push("wakodikar");
    cout<<s.front();//pele nidhish gya tha


    s.pop();
    cout<<endl;
    cout<<s.front();
    cout<<endl;
    cout<<s.size();


}