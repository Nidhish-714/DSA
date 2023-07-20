#include<iostream>
using namespace std;

int piviotelem(int arr[]){
    int s=0;
    int e=4;
    int m;
    m=s+ (e-s)/2;

    while(s<e){
        if((arr[m]>arr[m-1])&&(arr[m]>arr[m+1])){
            return m;
        }
        else if(arr[m]>arr[0]){
            s=m+1;
        }
        else if(arr[m]<arr[0]){
            e=m;
        }
        m=s+ (e-s)/2;

    }
    return -1;
}

int main(){
    int arr[5];

    cout<<"enter elements "<<endl;
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }

    int x = piviotelem(arr);
    cout<<x;
}
