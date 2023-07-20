#include<iostream>
using namespace std;

int fibprint(int n){
    if(n<=1){
        
        return n ;
    }
    else{
        
        return fibprint(n-1)+fibprint(n-2);
        
       
    }
}

void reachhome(int src ,int dest){

    cout<<"source "<<src<<"destination "<<dest<<endl;
    //base case
    if(src==dest){
        cout<<"pahuch gya"<<" ";
        return ; 
    }
    //recursive call

    reachhome(src+1,dest);

}


void sayDigit(int n){
    //base case
    if(n<10){
        cout<<n<<" ";
        return;
    }
    else{
        sayDigit(n/10);
        int d = n%10;
        cout<<d<<" ";
    }
}
int summDigit(int n,int sum){
    //base case
    if(n<10){
        sum+=n;
        return sum;
    }
    else{
        sum = summDigit(n/10,sum);
        int d = n%10;
        sum+=d;
        return sum;
    }
}
int nstairs(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans  = nstairs(n-1)+nstairs(n-2);
    return ans;
}

int main(){
// int n = 6;
//      for(int i=0;i<n;i++){
//         cout<<fibprint(i)<<" ";
//      }
//      cout<<endl;
//      int dest = 10;
//      int src = 1;

//      reachhome(src,dest);
     //sayDigit(342)<<endl;
     cout<<summDigit(342,0);

}