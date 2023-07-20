//heap is complete binary tree with heap order property
//complete binary tree  -- ever level is filled completely except last level
//and nodes are added from left only
//two types -- max heap and min heap
//max heap -- value of child node is less than parent node for every node
//min heap -- value of every node is less than its child nodes

//array form me deko
//insertion in max heap
//no 0th idx ..........every node at i ka left child is at 2*i idx and right child is at 2*i+1
//node ka parent is at i/2 


//priority queue is a max heap always


#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
    int arr[20];
    int size;

    heap(){
        arr[0] = -1;
        size=0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while (index>1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;

            }
        }
        
    }

    void print(){
        for(int i = 1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deleteFromHeap(){//O(log n)--complexity
        if(size == 0){
            cout<<"nothing to delete"<<endl;//root node ko delete krna hai
            return;
        }
//put last element into first index
        arr[1]==arr[size];
        size--;//last node hatao

        //take root node to its correct posn
        int i =1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
        if(arr[i]<arr[leftIndex] && leftIndex<size){
            swap(arr[i],arr[leftIndex]);
            i = leftIndex;//niche utr gya
        }else if(arr[i]<arr[rightIndex] && rightIndex<size){
            swap(arr[i],arr[rightIndex]);
            i = rightIndex;

        }
        else{
            return;
        }
        }
    }
};

//heapify algorithm
//convert array into heap
//in CBT leaf nodes are from n/2 + 1 to n nodes (n == sizeofarray)
//all leaf nodes are heap in itself therefore just process nodes from 1 to n/2

void heapify(int arr[],int n,int i){//n is size of array , i is index first, i ko  sahi jgah paucha dega
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);//largest sahi jgah point kar raha hai
        heapify(arr,n,largest);
    }

}
//heap sort
//swap i with last
//and size--
//root node ko correct posn pr lao


void heapSort(int arr[],int n){//O(nlogn)
    int size = n;
    while(size>1){
        //step 1
        swap(arr[n],arr[1]);
        //step 2
        size--;

        //step 3
//correct jgh laao first elem ko after swapping (last element in real)
        heapify(arr,size,1);
    }
}


int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    int arr[6]={-1,54,53,55,52,50};
    int n = 5 ;
    for(int i =n/2;i>0;i--){
        heapify(arr,n,i);//har node se check kro niche tak for each node
    }
    cout<<"printing"<<endl;
    for(int i =1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"printing"<<endl;


    h.print();


//a type of max heap only
    priority_queue<int>p;
    p.push(4);
    p.push(2);
    p.push(5);
    p.push(3);

    //min heap
    priority_queue<int , vector<int>,greater<int>>minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
}