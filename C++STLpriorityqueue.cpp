#include <iostream>
#include <queue>
using namespace std;

/*
first element is always greatest
*/

int main(){
    //max heap
    priority_queue<int> maxi;
    //mini heap
    priority_queue<int,vector<int> , greater<int>> mini;

    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    maxi.push(4);
    maxi.push(5);
    int size = maxi.size();
    // maxi.pop();
    // cout<<maxi.top();



    // for(int i = 0 ; i<maxi.size() ; i++){
    //     cout<<maxi.top()<<endl;
    //     maxi.pop();
    // } //not work completely as every time size of maxi chnges when we pop

    for(int i = 0 ; i<size ; i++){
        cout<<maxi.top()<<endl;
        maxi.pop();
    } //jo top par h vai pop hoga

    cout<<mini.empty();


cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
    mini.push(1);
    mini.push(2);
    mini.push(3);
    mini.push(4);
    mini.push(5);

    mini.pop();

    cout<<mini.top();//here minimum wala will be popped




}