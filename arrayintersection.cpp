#include <iostream>
#include <math.h>
using namespace std;
//one value should intersect only one time
void intersection(int arr1[],int arr2[]){
    //  for(int i =0 ; i<7 ;i++){


    //     for(int j =0 ; j<7 ;j++){

    //         if(arr1[i]<arr2[j]){
    //             break;
    //         }
    //         if(arr1[i]==arr2[j]){
    //             cout<<arr1[i];
    //             arr2[j]=-1;//so that it should not mapagain
    //             break;
    //         }

    //     }
    //  }
int i =0,j=0;

while((i<7)&&(j<7)){
            if(arr1[i]<arr2[j]){
            i++;
            }
            else if(arr1[i]==arr2[j]){
                cout<<arr1[i];
                i++;
                j++;

            }
            else if(arr1[i]>arr2[j]){
            
                j++;

            }
}

        
}

int main(){
    int arr1[7],arr2[7];

    for(int i =0 ; i<7 ;i++){
        cin>>arr1[i];
    }

    cout<<endl;
    cout<<endl;
    cout<<endl;

    for(int i =0 ; i<7 ;i++){
        cin>>arr2[i];
    }
    intersection(arr1,arr2);
}