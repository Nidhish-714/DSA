#include <iostream>
using namespace std;


//inline fxns are used to reduce the functions calls
//overhead

inline int getmax(int& a , int& b){
    return (a>b)?a:b;
}
//jabbi function call hga vo bar bar stack me
//chedega 
//islie do inline(only for one line functions)

//compile hone k pehle hi inline function ki vo line
//uthke udr ayegi jaha fxn call hua

//good prefromance and no extra memory usage 
//no function overhead

int main(){
    int a = 1 , b = 2;
    int ans = 0;

    (a>b)? ans = a : ans = b;
    cout << ans << endl;

    a = a+3;
    b = b+1;

    ans = (a > b) ? a : b;//bar bar check kree not good
    cout << ans << endl;
    ans = getmax(a, b); // return (a>b)?a:b; same to same idr agya

    cout<<ans<<endl;
}