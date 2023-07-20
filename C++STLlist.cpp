#include <iostream>
#include <list>
using namespace std;

/*
doubly linked list , no random access
*/

int main(){
    list<int>f(5,1);
    for(int k:f){
        cout<<k<<" ";
    }
    list<int> l;
    list<int> n(l);
    for(int j:n){
        cout<<j<<" ";
    }

l.push_back(1);
l.push_front(2);
for(int i:l){
    cout<<i<<" ";
}
cout<<endl;

cout<<"before erase"<<l.size()<<endl;
l.erase(l.begin());//l.erase k andr jisko point kia usko delete krega
cout<<"after erase"<<l.size()<<endl;
}
