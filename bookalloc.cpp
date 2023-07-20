// 10 20 30 40  no of students is 2 islie 2 partition

// 10 203040    (10,90) = 90 max values
// 1020 3040    (30,70)=70
// 102030 40    (60,40)=60 ans  max of all is min
// max of all book pages is min

//min is = 0 and max it can be sum of all i.e = 100 for search space


#include<iostream>
using namespace std;

int allotbook(int arr[],int n,int m){
    int s =0;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e = sum ;

    int mid = s +(e-s)/2;
    int ans =-1;


    while(s<=e){
        if(ispossible(arr,n,m,mid)){
            ans =mid;
            e =mid -1;
        }
        else{
            s =mid+1;
        }
        mid = s +(e-s)/2;
    }

    return ans;

}

bool ispossible(int arr[],int n,int m,int mid){
    int studentcount =1;
    int pagesum =0;

    for(int i=0;i<n;i++){
        if(pagesum + arr[i] <=mid){
            pagesum+=arr[i];
        }
        else{
            studentcount++;
            if(studentcount>m||arr[i]>mid){
                    return false;
            }
            pagesum=arr[i]; //for new student as we have done studentcount ++

        }
    }
    return true;
}




int main(){
   
}