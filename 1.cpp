#include <iostream>
using namespace std;

int distinctval(int arr[], int n)
{
    int cnt = 1;
    int i = 0;
    while (i < n-1)
    {
        if (arr[i] == arr[i + 1])
        {
            i++;
        }
        else
        {
            cnt++;
            i++;
        }
    }

    return cnt;
}

int main(){
    int arr[5]={2,2,3,4,5};
    cout<<distinctval(arr,5);
}