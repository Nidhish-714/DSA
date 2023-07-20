#include <iostream>
#include <math.h>
using namespace std;

int main (){
    int n,i =0,ans =0,d;
    cin>>n;
    while(n>0){
        d = n%10;
        ans = ans*10 + d;
        //ans = ans + d*pow(10,i); for same
        n = n/10;
        i++;
    }

    cout<<ans;
}