#include <iostream>
#include <math.h>
using namespace std;

void uniquelement(int arr[]){
    int ans =0;
    for(int i =0 ; i<7 ;i++){
        ans = ans^arr[i];
    }
    cout<<ans;
}

int main(){
    int arr[7];
    for(int i =0 ; i<7 ;i++){
        cin>>arr[i];
    }
    uniquelement(arr);
}
