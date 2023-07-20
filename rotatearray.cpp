#include <iostream>

using namespace std;

void rotatearray(int arr[],int k){
    int ans[7];
    for(int i=0;i<7;i++){
        ans[(i+k)%7]=arr[i];
    }

    for( int a : ans){
        cout<<a<<" ";
    }




}

int main(){


    int arr[7]={2,4,5,8,9,10,11};

    int n;
    cout<<endl;
    for( int a : arr){
        cout<<a<<" ";
    }
    cout<<"enter key"<<endl;
    cin>>n;
    rotatearray(arr,n);

 

    return 0;
}