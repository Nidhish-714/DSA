#include <iostream>
using namespace std;

void print(int arr[], int n ,int start = 3){
    for(int i =start;i<n ; i++){
        cout<<arr[i]<<" ";
    }
}//giving default values ,start giving it from right most side
//pele start then n only ( right to left)
int main(){

    int arr[5] = {1,2,3,4,5};
    int size = 5;
    print(arr,size,0);
    cout<<endl;
    print(arr,size);

}