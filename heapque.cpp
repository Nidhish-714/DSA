#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    struct Node* left;
    struct Node* right;
};

//kth smallest element 

//approach 1 -- sorted(heap sort ) krke lalo and arr[k-1]
//approach 2 -- first k elements ka max heap for rest element ka 
// if elem <heap.top then heap.pop and heap . push
// k smallest ka max heap banega and root pr ans hga

int kthSmallest(int arr[],int l, int r , int k){

    priority_queue<int> pq;

    //step 1
    for(int i=0;i<k;i++){
        pq.push(arr[i]);//max heap bana dia
    }
    //step 2
    for(int i = k ; i<=r ; i++){
        if(pq.top()>arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;

}//for k th largest use min heap

//IS BINARY TREE  A  HEAP
//should be complete ..wether is max heap or not and  completed
//for cbt -- if index is greater than total count then it is not a cbt

int countNode(struct Node* root){
    if(root==NULL){
        return 0;
    }

    int ans = countNode(root->left)+countNode(root->right)+1;
    return ans;
}

bool isCBT(struct Node* root , int index ,int cnt){
    //base case
    if(root==NULL){
        return true;
    }
    if(index>=cnt){// 0 based indexing (for 1 based indexing only > )
        return false;
    }

    else{
        bool left = isCBT(root->left , 2*index+1,cnt);
        bool left = isCBT(root->right , 2*index+2,cnt);

        return (left&&right);
    }
}


bool isMaxOrder(struct Node* root){
    if(root->left ==NULL && root->right == NULL){
        return true;
    }
    if(root->right == NULL){
        return (root->data>root->left->data);//sir fleft wala node hai right nai hai
    }
    //if(root->left->data < root->data &&  root->right->data < root->data)

    else{
        bool left  = isMaxOrder(root->left);
        bool right  = isMaxOrder(root->right);

        if(left && right && (root->left->data < root->data &&  root->right->data < root->data)){
            return true;
        }
        else{
            return false;
        }
    }
}


bool isHeap(struct Node* root){
    int index = 0;
    int totalCount=countNode(root);
    if(isCBT(root,index,totalCount)&& isMaxOrder(root)){
        return true;
    }else{
        return false;
    }
}

//merege 2 binary max heap
void heapify(vector <int> &arr,int n,int i){//n is size of array , i is index first, i ko  sahi jgah paucha dega
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);//largest sahi jgah point kar raha hai
        heapify(arr,n,largest);
    }

}


vector<int> mergeHeaps(vector<int> &a , vector<int>&b , int n , int m){
    vector<int>ans ; 
    
    //merge both into one
    for(auto i:a){
        ans.push_back(i);
    }
    for(auto i:b){
        ans.push_back(i);
    }

    int size = ans.size();
//heapify krdena
    for(int i = size/2-1 ; i>=0 ; i--){//int i = size/2-1 leafnodes hai iske bad
        heapify(ans,size,i);
    }


}



//Min cost of ropes

long long minCost(long long arr[],long long n){
    //create a min heap
    priority_queue<long long,vector<long long>,greater<long long>>pq;

    long long cost =0;

    for(int i =0;i<n ;i++){
        pq.push(arr[i]);
    }

    while(pq.size()>1){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long sum  =a+b;

        cost+=sum;
        pq.push(sum);

    }

    return cost;
}

// kth largest sum subarray

// do for loop se subka sum nikalo ...vector me dalo ...sort kro vector ko and k th largest ans dedo


int getKthLargest(vector<int>&arr , int k){

    vector<int> sumStore;

    for(int i = 0 ; i<arr.size();i++){
        int sum = 0;
        for (int j = i ; j<arr.size();j++){
            sum = sum +arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(),sumStore.end());

    return sumStore[sumStore.size()-k];
}

//another approach -- use kth largest using min heap nikalo

int getKthLargestGood(vector<int>&arr , int k){

    priority_queue<int ,vector<int>,greater<int>>mini;

    for(int i = 0 ; i<arr.size();i++){
        int sum = 0;
        for (int j = i ; j<arr.size();j++){
            sum = sum +arr[j];
            if(mini.size()<k){
                mini.push(sum);//pele k elements daldo
            }
            else{
                if(sum>mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

//merge k sorted arrays
//merge k linked list





