#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    cout<<"finding 6 "<<binary_search(v.begin(),v.end(),6)<<endl;

    cout<<"lower bound"<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;//returns an iterator
    cout<<"upper bound"<<upper_bound(v.begin(),v.end(),4)-v.begin()<<endl;//returns an iterator

int a = 4;
int b = 6;

cout<<max(a,b);
cout<<min(a,b);

swap(a,b);

cout<<a;

string abcd = "abcd";

reverse(abcd.begin(),abcd.end());
cout<<abcd<<endl;

rotate(v.begin(),v.begin()+1,v.end());
cout<<"after rotate"<<endl;

for ( int i:v){
    cout<<i<<" ";
}
sort(v.begin(),v.end());
cout<<"after sort"<<endl;

for ( int i:v){
    cout<<i<<" ";
}



}