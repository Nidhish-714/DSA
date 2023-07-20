#include <iostream>
#include <set>
using namespace std;

//stores unique element ,no modification
//only insert and delete,in sorted way

int main(){
set<int>s;
s.insert(5);
s.insert(5);
s.insert(5);
s.insert(1);
s.insert(6);
s.insert(6);
s.insert(6);
s.insert(0);
s.insert(0);

for(auto i:s){
    cout<<i<<"  ";
}
cout<<endl;


s.erase(s.begin());
for(auto i:s){
    cout<<i<<"  ";
}
//complexity is O(log n)
cout<<endl;
set<int>::iterator it = s.begin();
it++; //for pointing to s.begin () + 1

s.erase(it);
for(auto i:s){
    cout<<i<<"  ";
}
cout<<endl;

cout<<"present or not "<<s.count(5)<<endl;
cout<<"present or not "<<s.count(6)<<endl;
s.insert(5);
s.insert(5);
s.insert(5);
s.insert(1);
s.insert(6);
s.insert(6);
s.insert(6);
s.insert(0);
s.insert(0);

set<int>::iterator itr = s.find(1); //return iptr of 6
cout<<"value present at itr is "<<*itr<<endl;

for(auto it = itr; it!=s.end();it++){
    cout<<*it<<" ";//it me itr hai jo 1 se chalu hua islie waha se loop chalu hga
}




}