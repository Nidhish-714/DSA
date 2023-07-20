#include <iostream>
using namespace std;

int binaryrecursion(int arr[], int k, int s, int e)
{
    

    if (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m]==k)
        {
            return m;
        }
        else if (arr[m] > k)
        {
            return binaryrecursion(arr, k, s, m - 1);
        }
        else
        {
            return binaryrecursion(arr, k, m + 1, e);
        }
    }
    return -1;
}

bool issorted(int arr[], int i)
{
    if (i == 5)
    {
        return 1;
    }
    else if (arr[i] < arr[i + 1])
    {
        return issorted(arr, i + 1);
    }
    else
    {
        return 0;
    }
}

bool issorted1(int arr[], int size)
{
    if(size == 1  || size == 0 )
    {
        return 1;
    }
    else if (arr[0] < arr[ 1])
    {
        bool rem =  issorted(arr+1, size-1);
        return rem;
    }
    else
    {
        return 0;
    }
}

int sum(int arr[],int i,int s){
    if(i==5){
        s = s + arr[i];
        return s;
    }
    else{
        s = s + arr[i];
        return sum(arr,i+1,s);
    }
}

int linearsearchrec(int arr[], int k, int i)
{
    if (arr[i] == k)
    {
        return i;
    }
    else if (i == 5)
    {
        return -1;
    }
    else
    {
        linearsearchrec(arr, k, i + 1);
    }
}

int main()
{
    int n, k;
    // cout<<"enter size of array"<<endl;

    // int *arr = new int[n];

    // for(int i=0 ; i<n ; i++){
    //     cin>>arr[i];
    // }
    // int arr[6] = {2, 3, 4, 5, 6, 8};
    int arr1[6] = {4, 6, 2, 5, 7, 2};
    // cout << endl
    //      << "enter key" << endl;
    // cin >> k;

    // cout << binaryrecursion(arr, k, 0, 5) << endl;
    // cout << issorted(arr1, 0) << endl;

    // cout << linearsearchrec(arr1, k, 0)<<endl;
    cout<<"sum is "<<sum(arr1,0,0);
}