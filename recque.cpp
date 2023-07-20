#include<iostream>
using namespace std;

int recsum(int arr[] , int n,int sum){
    //base case
    if(n==6){
        sum=sum+arr[0];
        return sum;
    }
    else{

        sum = recsum(arr+1,n+1,sum);
        sum=sum+arr[0];
        return sum;
    }
}

int sumdigit(int n,int sum){
    if(n<10){
        return sum=sum+n;
    }
    else{
        sum = sumdigit(n/10,sum);
        sum=sum+(n%10);
        return sum;
    }

}

int main(){
    int arr[6]={2,4,6,8,4,6};
    int n = 6;
    int sum=0;

    cout<<recsum(arr,0,sum)<<endl;
    cout<<sumdigit(243,0)<<endl;
}