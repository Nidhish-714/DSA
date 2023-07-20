#include <iostream>
#include <math.h>
using namespace std;

void print(int arr[],int n){
    for (int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    print(arr,6);
}