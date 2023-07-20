#include <iostream>
#include <array>
using namespace std;

int main(){
    array<int,4> a ={1,2,3,4};
    int size = a.size();

    for(int i=0 ; i<size ;i++){
        cout<<a[i]<<endl;
    }

    cout<<"element at 2 is "<<a.at(2)<<endl;
    cout<<a.empty()<<endl;
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;

}