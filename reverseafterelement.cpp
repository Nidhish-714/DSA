#include <iostream>
#include <queue>
using namespace std;

vector<int> reverse(vector<int>a,int n){
    int s = n+1;
    int e = a.size()-1;

    while(s<=e){
        swap(a[s],a[e]);
        s++;
        e--;
    }
    return a;
}

int main(){

    vector<int>a;
    vector<int>ans;
    int n;
    a.push_back(12);
    a.push_back(2);
    a.push_back(1);
    a.push_back(7);
    a.push_back(5);
    a.push_back(9);

    cout<<"enter index from where you want to reverse"<<endl;
    cin>>n;;

    ans = reverse(a,n);

    for(int i:ans){
        cout<<i<<" ";

    }


}