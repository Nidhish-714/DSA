#include <iostream>

using namespace std;

bool rotatandsortedarray(int arr[]){
    int count = 0;
    for (int i =1;i<7;i++){
        if(arr[i-1]>arr[i]){
            count++;
        }
    }

    if(arr[6]>arr[0]){
        count+=1;
    }

    return count<=1;//for{1,1,1} count should be 0 or only

}

int main(){


    int arr[7];
    cout<<"enter elements"<<endl;

    for (int i =0;i<7;i++){
cin>>arr[i];
    }
    cout<<rotatandsortedarray(arr);


 

    return 0;
}