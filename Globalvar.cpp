#include <iostream>
using namespace std;

int score =99;

void a( int& i){//pass by refrence
    cout<<i<<endl;
    cout<<score<<endl;//global
    score = 101;// bad practice as it can be changed anywhere and will be changes for all fxns
    cout<<score<<endl;
}

int main(){
    int i = 5;
    cout << score << endl;
    a(i);
    cout << score << endl;
}