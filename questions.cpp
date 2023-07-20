#include <iostream>
using namespace std;

bool linearSearch(int *arr,int size,int k){

    //base case

    if(size==1){
        if(arr[0]==k){
            return true;
        }
        else{
            return false;
        }
    }

    //rec call
    else{
        if(arr[0]==k){
            return true;
        }
        else{
            bool ans = linearSearch(arr+1,size-1,k);
            return ans;
        }
    }


}

int main(){
    int arr[6]={3,6,1,2,5,7};

    bool ans = linearSearch(arr,6,6);
    cout<<ans;
}