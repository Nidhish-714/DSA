#include <iostream>
#include <math.h>
using namespace std;

void sort01(int arr[], int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<7;j++){
            if(arr[j]==1){
                swap(arr[j],arr[i]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}

int main()
{
    int n;
    // cout<<"enter size of array"<<endl;
    // cin>>n;

    int arr[7];

    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }

    sort01(arr, 7);
}