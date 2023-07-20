#include <iostream>

using namespace std;

void movezeroes(int arr[]){
int count = 0;
int p =0;
int arrans[8] = {0};

for(int i=0 ; i<8 ; i++){
    if(arr[i]!=0){
        arrans[p]=arr[i];
        count++;
        p++;
    }
}

for(int k:arrans){
    cout<<k<<" ";
}



}

int main(){

    int arr[8]={1,0,3,0,0,5,0,8};


    movezeroes(arr);

    return 0;
}
