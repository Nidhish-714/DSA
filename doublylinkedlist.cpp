#include <iostream>
using namespace std;



class node
{
public:
    int data;
    node *prev;
    node *next;

    // constructor
    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
};

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }

    cout << endl;
}

int getLength(node* head){
    int len =0;
    node *temp = head;
    while (temp != NULL)
    {
        
        temp = temp->next;
        len++;
    }

    return len;
}

void insertAthead(node *&head, int data){

    if(head==NULL){
        node*temp = new node(data);
        head = temp;
    }
    //create a node
    node *temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;//update head

}
void insertAttail(node *&tail, int data){
    if (tail == NULL)
    {
        node *temp = new node(data);
        tail = temp;
    }

    //create a node
    node *temp = new node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;//update tail

}

void insertAtposition(node *&tail,node *&head,int position , int data){

    if(position==1){
        insertAthead(head,data);
        return;
    }
    node *temp = head;

    //create a node
    node* nodetoinsert = new node(data);
    int cnt =1;

    while(cnt<position-1){
        temp = temp->next;
    }

    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp -> next = nodetoinsert ;
    nodetoinsert ->prev =  temp;

    

    if(temp->next==NULL){
        insertAttail(tail,data);
        return;
    }

}

void deleteAt(int position,node *&head){

    // deleting starting node
    if (position == 1)
    {
        node *temp = head;

        temp->next->prev=NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting last or middle node
        node *curr = head;
        node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {

            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr ->prev =NULL;
        prev -> next = curr ->next;
        curr ->next = NULL;
        delete curr;
    }
}

int main()
{

    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    print(head);

    cout<<"length is : "<<getLength(head);
    cout<<endl;
    insertAthead(head,11);
    print(head);

    insertAttail(tail,7);
    print(head);
    insertAtposition(tail,head,2,100);
    print(head);
}