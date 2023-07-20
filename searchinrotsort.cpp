#include<iostream>
using namespace std;

int peakelem(int arr[]){
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

int binsearch(int s, int e, int key,int arr[]){
    
    int mid = s+(e-s)/2;

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

int binsearch(int s, int e, int key,int arr[]);
int searchrotsort(int arr[],int key);
int peakelem(int arr[]);

int searchrotsort(int arr[],int key){

    if(arr[0]<key){
        return binsearch(0,peakelem(arr),key,arr);
    }
    else{
        return binsearch(peakelem(arr)+1,4,key,arr);
    }
    
}



int main(){
    int arr[5],key;

    cout<<"enter elements "<<endl;
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }

    cout<<"enter key"<<endl;
    cin>>key;

    int x = searchrotsort(arr,key);
    cout<<x;
}
