#include<iostream>
using namespace std;

void update(int **p){
    **p = **p+1;

}

int main(){
    int i =5;
    int *ptr = &i;
    int **ptr2 = &ptr;

    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    cout<<**ptr2<<endl;
    
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << *ptr2 << endl;

    //printing address of i

    cout << "printing address of i"<<endl;
    cout<<&i<<endl;
    cout<<ptr<<endl;
    cout<<*ptr2<<endl;

cout<<"before update"<<endl;
cout << i << endl;
cout << ptr << endl;
cout << ptr2 << endl;
update(ptr2);
cout<<"after update"<<endl;
cout << i << endl;
cout << ptr << endl;
cout << ptr2 << endl;
}