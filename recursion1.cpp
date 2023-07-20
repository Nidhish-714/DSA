#include<iostream>
using namespace std;
//complex problem or big problem ka soln
//depends on same type of small problem

int power(int a ,int n){
    if(n==0){
        return 1;//basecase
    }
    else {
        return power(a,n-1)*a;
    }
}

int fact(int n){
    if(n==0){
        return 1;//mandatory
    }else{
        return n*fact(n-1);
    }
}

void printcount(int n){
    if(n==0){
        return;
    }
        printcount(n-1);
    cout<<n<<" ";
    
    
    
}

int main(){

    cout<<power(4,3);
    cout<<endl;
    cout<<fact(4);
    cout<<endl;
    printcount(10);

}
