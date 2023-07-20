#include <iostream>
#include <queue>
using namespace std;

class Queue{
    int* arr;
    int qfront;
    int rear;
    int size;

    public:

    Queue(){
        size =10000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }


    void enqueue(int data){
        //check if full
        if(rear==size){
            cout<<"size is full"<<endl;
        }
        else{
            arr[rear] = data;//points to place where it should insert
            rear++;
        }
    }

    int dequeue(){

        if(qfront==rear){
            cout<<"no elements"<<endl;
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront]=-1;
            qfront++;
            //no element now after delte
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }

    }

    int front(){
        if(qfront==rear){
            return -1;
        }else{
            return arr[qfront];
        }
    }

    bool isEmpty(){
        if(rear==qfront){
            return 1;
        }
        else{
            return 0;
        }

    }
};

//circular queue

//jab queue k end m aye tab ghum kar wapis front me agye

//full k liye (front==0 && rear == size-1) or rear==(front-1)%size-1(rear =front -1)
//if front==-1( do front=rear=0) first element enter

//if rear ==size-1 && front!=0 then rear = 0 kro (rear ko aege lao) rear++ and arr[rear]=data  ,else---- enquw

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    //initialise queue
    CircularQueue(int n){
        size=n;
        arr = new int[size];
        front = rear-1;
    }

    bool enqueue(int value){
        if(((front==0) && (rear==size-1)) || (rear = (front-1)%(size-1))){
            cout<<"queue is full"<<endl;
            return false;
        }
        else if(front==-1 ){
            //firs elem
            front=rear=0;
           
        }
        else if(rear = size-1 && front != 0 ){//age se insert kroo ab
            rear = 0;
       
        }else{
            rear++;
            
        }
        arr[rear] = value;
        return true;
    }

    int dequeue(){
        if(front==-1){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){//single element
        front =rear=-1;

        }else if(front = size-1){
            front = 0;// to maintain cyclic nature
        }else{
            front++;
        }
        return ans;
    }
};

//doubly ended queue
//start me front and rear -1
//yaha push front se hga and front piche ayega

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // check full or not
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;//pele posn specify then insert kia
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;//for cyclic nature
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty())
        { // to check queue is empty
            // cout << "Queue is Empty " << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty())
        { // to check queue is empty
            // cout << "Queue is Empty " << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1; // to maintain cyclic nature
        }
        else
        { // normal flow
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};