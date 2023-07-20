#include <iostream>
using namespace std;

void reverse(string &word,int i,int j){
    if(i>j){
        return  ;
    }
    else{
        swap(word[i],word[j]);
        i++;
        j--;
         reverse(word,i,j);
    }
}

bool checkpalindrome(string word,int i,int j){
        if(i==j){
            return true;
        }
         if(word[i]==word[j]){
            i++;
            j--;
          return checkpalindrome(word,  i, j);
        }
        else if (word[i] != word[j]){
            return false;
        }
 
}

void bubblesort(int arr[],int n){

    if(n==1){
        return;
    }

else{
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    bubblesort(arr,n-1);
}



}




int main(){
    string word = "nidhish";
    int arr[5]={3,5,1,8,0};
   
    //reverse(word,0,word.length()-1);
    cout<<checkpalindrome(word,0,word.length()-1);
    bubblesort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    //cout<<word;
}