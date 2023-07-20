#include<iostream>
using namespace std;

//have 2 names but having same memory block

void updatep( int *a){
    *a=10;
}

void updater(int& a){
    a =99;
}

// int& updatereturnrefrence(int n){
//     int a = n;
//     int& ans =a ;
//     return ans;

// }  //badpractice



int main(){
    int i =5;

    int& j =i;//refrence variable

    cout<<j<<" "<<i<<" "<<endl;

    j++;
    i++;

    cout<<j<<" "<<i<<" "<<endl;

    int a = 5;
    updatep(&a);//pass by pointer
    cout<<a<<endl;

    updater(a);
    cout<<a;
int k =88;
   // cout<<"updatereturnrefrence "<<updatereturnrefrence(k);

    return 0;
}

//there are two types of memory stack and heap
//stack is of less size and is static memory allocation
//heap is for dynamic memory allocation, new char or new int  is from heap,
//heap gives address