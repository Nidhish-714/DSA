#include <iostream>

using namespace std;

void mergetwoarray(int arr1[],int s1, int arr2[],int s2){

    int arr[11];

    int p1=0 , p2=0, p=0;

    while(p1<s1 && p2<s2){

        if(arr1[p1]<=arr2[p2]){
            arr[p] = arr1[p1];
            p++;
            p1++;
        }else if(arr1[p1]>arr2[p2]){
            arr[p]=arr2[p2];
            p++;
            p2++;
        }
    }

    while(p1<s1){

        arr[p]=arr1[p1];
        p++;
        p1++;
    }
    while(p2<s2){

        arr[p]=arr2[p2];
        p++;
        p2++;
    }

    for(int k : arr){
        cout<<k<<" ";
    }


}

int main(){

    int arr1[4]={1,3,5,8};
    int arr2[7]={2,4,5,8,9,10,11};

    int s1,s2;
    s1 = 4;
    s2 = 7;

    mergetwoarray(arr1 , s1 , arr2, s2);

    return 0;
}
