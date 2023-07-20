#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }
}