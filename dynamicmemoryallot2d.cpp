#include <iostream>
using namespace std;

int main()
{
    int n, m;//rows ,columns
    cin >> n >> m;

    int **arr = new int *[n];//creating n number of arrays

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m]; //adding m numbers of element in each array
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
    }

    //deleting memory

    for (int i = 0; i < n; i++)
    {
        delete [] arr[i];
    }

    delete []arr;
}