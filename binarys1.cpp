#include<iostream>
using namespace std;

int binarysearch(int arr[],int key){
    int s=0;
    int e=5;
    int mid = s+(e-s)/2;
    cout<<mid<<endl;

    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e = mid-1;
        }
        else{
            s=mid+1; 
        }
        mid = s+(e-s)/2;
        
    }
    return -1;
}

int main(){

    int arr[6],key;
    cout<<"enter value"<<endl;
    for(int i=0;i<6;i++){
        cin>>arr[i];
    }

    cout<<"enter key"<<endl;
    cin>>key;
    int x= binarysearch(arr,key);
    cout<<x;
    return 0;
}


// 10 se 5 se 2 se 1 sizeof array hua jaha search kia
// sirf 4 bar loop chala  n/2^k=1  here 1 is size of array
// complexity = O(log n)
