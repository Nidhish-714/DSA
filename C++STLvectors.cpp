#include <iostream>
#include <vector>
using namespace std;
//doubles its capacity when needed and elements are filled
int main(){

    vector<int> v;
    vector<int> a (5,1);//vector of size 5 having 11111 elements
    cout<<"capacity --> "<<v.capacity()<<endl;
    cout<<"size --> "<<v.size()<<endl;
    v.push_back(1);
    cout<<"capacity --> "<<v.capacity()<<endl;
    cout<<"size --> "<<v.size()<<endl;
    v.push_back(2);
    cout<<"capacity --> "<<v.capacity()<<endl;
    cout<<"size --> "<<v.size()<<endl;
    v.push_back(3);
    cout<<"capacity --> "<<v.capacity()<<endl;
    cout<<"size --> "<<v.size()<<endl;
    v.push_back(4);
    cout<<"capacity --> "<<v.capacity()<<endl;
    cout<<"size --> "<<v.size()<<endl;
    v.push_back(5);
    cout<<"capacity --> "<<v.capacity()<<endl;//doubles its capacity
    cout<<"size --> "<<v.size()<<endl;//size gives exact number of elements
   cout<<"element at 2 is "<<v.at(2)<<endl;
   cout<<v.front()<<endl;
   cout<<v.back()<<endl;

   cout<<"before pop"<<endl;
   for(int i:v){
    cout<<i<<" ";
   }
   v.pop_back();
   cout<<"after pop"<<endl;
   for(int i:v){
    cout<<i<<" ";
   }
   //while using clear operation size is 0 but capacity remains same
   cout<<v.size();
   v.clear();
   cout<<"after clearing "<<v.size();
   
   vector<int> last(a);//making a vector last same as (s) vector
      cout<<"printing last "<<endl;
   for(int i:last){
    cout<<i<<" ";
   }

   


}
