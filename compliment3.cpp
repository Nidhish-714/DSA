#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[4],d;

    for(int i = 0 ; i<4 ;i++){
        int d = n&1;
        arr[i]=d;
        n = n>>1;
    }
    
    for(int j=0; j<4;j++){
        d = arr[j];
        if (d==0){
            arr[j]=1;
        }
        else{
            arr[j]=0;
        }
    }

    for(int i = 0 ; i<4 ;i++){
        cout<<arr[i];
    }
    

}   