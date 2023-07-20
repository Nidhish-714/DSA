//FIFO DATA STRUCTURES
//front ---------rear 
//push from rear
//pop from front
//if(front==rear(no elem))front=0,rear=0 to save space

#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;
    q.push(11);
    q.push(12);
    q.push(13);

    cout<<"size of queue is "<<q.size()<<endl;
    cout<<"front element is "<<q.front()<<endl; 
}