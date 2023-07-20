#include<iostream>
using namespace std;

int peakelem(int arr[]){
    int s=0;
    int e=6;
    int m;
    m=s+ (e-s)/2;
    while(s<e){
        if((arr[m]>arr[m+1])&&(arr[m]>arr[m-1])){
            return m;
        }
        else if(arr[m]>arr[m+1]){
            e=m;
        }
        else if(arr[m]<arr[m+1]){
            s=m+1;
        }
        m=s+ (e-s)/2;

    }

    return -1;
}

int main(){
    int arr[7];

    cout<<"enter elements "<<endl;
    for(int i=0;i<7;i++){
        cin>>arr[i];
    }

    int x = peakelem(arr);
    cout<<x;
}
