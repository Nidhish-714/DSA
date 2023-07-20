#include <iostream>
using namespace std;

void maxrowsum(int arr[3][3])
{
    int sum[3];

    for (int row = 0; row < 3; row++)
    {
        int s = 0;
        for (int col = 0; col < 3; col++)
        {
            s += arr[row][col];
        }
        sum[row] = s;
    }

    int max = -1;
    for (int i = 0; i < 3; i++)
    {
        if (sum[i] > max)
        {
            max = sum[i];
        }
    }

    cout << max;
}

void spiralprint(int arr[3][3]){
    int dir = 0;
    int left = 0;
    int right = 2;
    int top = 0;
    int bottom = 2;
    int a =3;
    int total =9;
    int count =0;

    while(count<total){

        if(dir==0){
            for(int i = left ; i<=right ; i++){
                cout<<arr[top][i];
                count ++;
            }
            top++;
        }

        else if(dir==1){
            for(int i = top ; i<=bottom ; i++){
                cout<<arr[i][right];
                count ++;
            }
            right--;
        }

        else if(dir==2){
            for(int i = right ; i>=left; i--){
                cout<<arr[bottom][i];
                count ++;
            }
            bottom--;
        }

        else if(dir==3){
            for(int  i = left ;i<=right ;i++){
                cout<<arr[bottom][i];
                count ++;
            }
        }
        dir++;

        dir = dir%4;
        
    }


}

void waveprint(int arr[3][3])
{

    int nrows = 3;

    for (int col = 0; col < 3; col++)
    {
        if (col & 1)
        {
            for (int row = nrows - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }

        else
        {
            for (int row = 0; row < 3; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
    }
}


bool binarysearch2d(int arr[3][3],int target){
    int row = 3;
    int col = 3;
    int start = 0;
    int end = row*col - 1;

    int mid = start + (end - start)/2;

    while(start<=end){
        int midelem = arr[mid/col][mid%col]; 
        if(midelem == target){
            return 1;
        }

        else if(midelem<target ){
            start = mid +1;
        }
        else{
            end =mid -1;
        }
        mid = start + (end - start)/2;


    }
    return 0;


}
int main()
{
    int arr[3][3];

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cin >> arr[row][col];
        }
    }

    maxrowsum(arr);

    cout << endl;
    waveprint(arr);

    cout<<endl;

    spiralprint(arr);
}