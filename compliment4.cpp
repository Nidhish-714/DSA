#include <iostream>
using namespace std;

int main(){

    // int n,comp,mask = 0,i=0;
    // cin>>n;
    // comp = ~n;
    // while(comp!=0){
    //     comp = comp>>1;
    //     i++;
    // }

    // for(int j = 0; j<i; j++){
    //     comp = comp|1;
    //     comp<<1;
    // }

    // int res;
    // res = comp&n;
    // cout<<res;

    int m , n;
    cin>>n;
    m = n;
    int mask = 0;
    while(m!=0){
        mask = (mask<<1)|1;
        n = m>>1;
    }

    int ans = (~n)& mask;
    cout<<ans;

}