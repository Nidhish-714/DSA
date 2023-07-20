#include <iostream>
using namespace std;

void selectionsort(int arr[]){
    int i,j,key;

    for(int i=1;i<7;i++){
        key = arr[i];
        j = i - 1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;       
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

    selectionsort(arr);
    return 0;
}