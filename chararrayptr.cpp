#include <iostream>
using namespace std;

void print(int *add){
    cout<<add;
}
void update (int *add){
    *add = 8;
    cout<<*add<<endl;
}
void updateptr(int *p){
    p=p+1;
}

int getsum(int arr[]){//ye arr[] as apointer pass hua hai can write *arr bhi 
   // cout<<sizeof(arr);//8 dega kyuki as apointer pass hua hai
    int sum = 0;
    for(int i = 0 ;i< 3 ;i++){
        sum=sum+i[arr];
    }
return sum;

}
int main()
{

    // int arr[5] = {1, 2, 3, 4, 5};
    // char ch[7] = "aabcde";

    // cout << ch << endl; // address nai dega full string dega
    // char *chp = &ch[0];

    // cout << *chp << endl; // a dega
    // cout << chp << endl;  // abcde dega
    // cout <<"this is" <<*(chp++) << endl;
    // cout <<"this is" <<*(chp++) << endl;
    // cout <<"this is" <<*(chp)++<< endl;
    // cout <<"this is" <<*(chp)++<< endl;

    // char ch1 = 'z';
    // char *ptrch1 = &ch1;
    // cout << ptrch1<<endl;

    ///pointers with functions
    int val = 5;
    int *p = &val;
   // print(p);
   cout<<"before update "<<val<<endl;
    update(p);
    cout<<"after upadate "<<val<<endl;

    int b=6;
    int* ptr = &b;
    cout << "before update ptr " << ptr << endl;
    updateptr(ptr);
    cout << "after update ptr " << ptr << endl;//same value addrress dega

    int arr[5] = {1,2,3,4,5};

    cout<<"get sum "<<getsum(arr+2)<<endl;//can pass specific location to work on that part of array
    return 0;
}