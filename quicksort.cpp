#include<iostream>
using namespace std;
int partition(int arr[],int s , int e);
void quicksort(int arr[],int s, int e){

    if(s>=e){
        return ;
    }
    int p=partition(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);


}

int partition(int arr[],int s , int e){//returns correct index of piviot column and us index
//k right me piviot se bade and left me piviot se chote

int piviot = arr[s];
int cnt =0;

for(int i =s+1;i<=e;i++){
    if(arr[i]<=piviot){
        cnt++ ;
    }
}

int pivotindex = s +cnt;

swap(arr[pivotindex],arr[s]);

int i = s , j=e;

while(i<pivotindex && j>pivotindex){
    while(arr[i]<piviot){
        i++;
    }

    while(arr[j]>piviot){
        j--;
    }

    if(i<pivotindex && j>pivotindex){
        swap(arr[i++],arr[j--]);
    }
}

return pivotindex;


}

int main(){
    int arr[5] = {2,4,1,6,8};
    int n =5;
    quicksort(arr,0,n-1);

    for(int i=0 ;i<n;i++){
        cout<<arr[i]<<"  ";
    }cout<<endl;
    return 0;
}