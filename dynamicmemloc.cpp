#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int* arr = new int[n]; //dynamic memory allocated

    for(int i = 0;i <n ;i++){
        cin>>arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout<< arr[i];
    }

    delete []arr;
    return 0;


    // int arr[6] = {0};

    // int *p = arr;

    // for (int i = 0; i < 6; i++)
    // {
    //     cout<< p[i];
    //     cout<<*(p+i);
    // }
}