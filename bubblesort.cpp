#include <iostream>
using namespace std;

void bubblesort(int arr[],int n){

    for(int j=1;j<n;j++){
        for(int k=0;k<n-j;k++){
            if(arr[k]>arr[k+1]){
                swap(arr[k],arr[k+1]);
            }
        }
    }

    for(int i=0;i<7;i++){
        cout<<arr[i];
    }
}

int main(){
    int arr[7];
    cout<<"enter elements"<<endl;
    for(int i=0;i<7;i++){
        cin>>arr[i];
    }
    int n=7;

    bubblesort(arr, n);
    return 0;
}