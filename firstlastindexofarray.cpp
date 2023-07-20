#include<iostream>
using namespace std;

int firstidx(int arr[],int key){
    int s=0;
    int e=6;
    int mid = s+(e-s)/2;
    int ans;

    while(s<e){
        if(arr[mid]==key){
            ans=mid;
            e=mid;//as stored in ans
        }
        else if(arr[mid]>key){
            e = mid-1;
        }
        else{
            s=mid+1; 
        }
        mid = s+(e-s)/2;
    }
    
    return ans;
}

int main(){

    int arr[7],key;
    cout<<"enter value"<<endl;
    for(int i=0;i<7;i++){
        cin>>arr[i];
    }

    cout<<"enter key"<<endl;
    cin>>key;
    int x= firstidx(arr,key);
    cout<<x;
    return 0;
}