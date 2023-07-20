#include<iostream>
using namespace std;

int main(){
    // int num =5;
    // int *ptr = &num;//pointer ptr is pointing to int datatype 
    // cout<<&num<<endl;
    // cout<<ptr<<endl;
    // num++;
    // cout<<*ptr<<endl;
    // cout<<(*ptr)++<<endl;
    // cout<<(*ptr)++<<endl;

    // cout<<endl;
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;

    // int arr[3] = {1,2,3};
    // cout<<*(arr+2)<<endl;
    // cout<<2[arr];
    // cout<<sizeof(ptr);//8

    int temp[10] = {1,2};

    cout<<sizeof(temp)<<endl;
    cout<<sizeof(*temp)<<"   "<<(*temp)<<endl;
    cout<<sizeof(&temp)<<"   "<<&temp<<endl;

    int *ptr =&temp[0];
    cout<<sizeof(ptr);



    return 0;
}