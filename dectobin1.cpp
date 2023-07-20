#include <iostream>
#include <math.h>
using namespace std;

// int main(){
//     int n,d,ans =0,i=0;
//     cout<<"enter a number in decimal"<<endl;
//     cin>>n;
//     while (n>0){
//         //cout<<n<<endl;
//         d = n%2;
//         ans = ans + d*pow(10,i);
//         n = n/2;
//         i++;

//     }

    // cout<<ans;
int main(){
   
    int n,ans =0,i=0;
    cout<<"enter a number in decimal"<<endl;
    cin>>n;

    while(n!=0){
        //cout<<n<<endl;
        int d = n&1;
        //if (n==1) cout<<"d="<<d<<endl;
        ans = ans + (d*pow(10,i));
        cout<<"ans="<<ans<<endl;
        n = n>>1;
        i++;
    }
    cout<<ans;
}


