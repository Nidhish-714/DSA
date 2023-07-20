#include <iostream>
#include <math.h>
using namespace std;

void findduplicate(int arr[],int n){
    // int arr2[7];
    // for(int i= 0;i<n;i++){
    //     arr2[i]=i+1;
    // }

    // for(int j= 0;j<n;j++){
    //     if(arr[j]==arr2[j]){
    //         j++;
    //     }
    //     else{
    //         cout<<arr[j];
    //     }
    // }
    int ans = 0;
    
    for(int i =0 ; i<7 ;i++){
        ans = ans^arr[i];
   

    }



    for(int i =0 ; i<7 ;i++){
        ans = ans^i;

    }

    cout<<ans;




}

int main(){
    int n;
    // cout<<"enter size of array"<<endl;
    // cin>>n;


    int arr[7];

    for(int i =0 ; i<7 ;i++){
        cin>>arr[i];
    }

    findduplicate(arr,7);
}