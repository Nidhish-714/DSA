#include <iostream>
#include <map>
using namespace std;



class node
{
public:
    int data;
    node *next;

    // constructor

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor

    ~node(){
        int value = this -> data;

        if(this->next != NULL){
            delete next;
            this -> next =NULL;
        }
        cout<<"memory freed"<<endl;
    }
};

void insertAtHead(node *&head, int d)
{ // to cretae and change node in previous node

    // create new node
    node *temp = new node(d);

    temp->next = head;
    head = temp;
}

bool detectloop(node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<node *, bool> visited; // map banaya jo traverse krega and true true krega jaha bhi jaye
    // if pele se koi true then loop is present
    node *temp = head;

    while (temp != NULL)
    {

        if (visited[temp] = true)
        {
            cout<<"cycle is present at "<<temp->data<<endl;
            // loop is present
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

void inserAttail(node *&tail,int d){

    //create a node
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next; // tail changed here
    //tail = temp; // tail changed here ye bhi chlega
}

void insertAtPosition(node *&tail,node *&head, int position, int data)
{

    if(position==1){
        insertAtHead(head,data);
        return;
    }//for 1st position

    

    //go to position wala node

    node* temp = head;
    int cnt =1;
    while(cnt<position -1){//2 k age dalna hai to ekbar loop
        temp = temp -> next;
        cnt++;
    }

    if(temp->next==NULL){//inserting at last position
       inserAttail(tail,data);//cannot do with loop as then tail needs to be updated
       return ;

    }

    //node created
    node *nodetoinsert = new node(data);

    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

// floyds detection loop algo---
// ek fast node ek slow node and traverse kro loop me if kabi fast == slow
//  ajaye then loop is present
// fast is == null then no loop

node *floydDetectLoop(node *head)
{
    if (head == NULL)
    {
       return NULL;
    }

    node *slow = head;
    node *fast = head;

    while (slow != NULL && fast != NULL)
    {
       fast = fast->next;
       if (fast = NULL)
       {
            fast = fast->next;
       }

       slow = slow->next;

       if (slow == fast)
       {

            cout << "present at " << slow->data << endl;
            return slow;
       }
    }

    return NULL;
}

void deleteNode(int position,node* &head){

    //deleting starting node
    if(position==1){
        node*temp = head;

        head = head->next;
        //memory free

        temp ->next = NULL;//so that it should not point to anyother address

        delete temp;

    }
    else{
        //deleting last or middle node
        node* curr =  head;
        node* prev = NULL;

        int cnt =1;
        while(cnt<position){

            prev = curr;
             curr=curr->next;
             cnt++;

        }

        prev->next = curr->next;
        curr->next = NULL; // so that it should not point to anyother address
         delete curr;
    }
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    node *node1 = new node(10);

    cout << node1->data << endl;
    cout << node1->next << endl;

    // head pointing to node 1

    node *head = node1;
    node *tail = node1;//single node hai

    print(head);

    insertAtHead(head, 12);
    insertAtHead(head, 15);
    cout << endl;
    cout << endl;
    cout << endl;
    print(head);
    cout << endl;
    cout << endl;
    cout << endl;
    inserAttail(tail, 99);
    print(head);
    cout << endl;
    cout << endl;
    cout << endl;
    insertAtPosition(tail,head,3, 88);
    print(head);

    deleteNode(3,head);
    print(head);

    tail->next = head->next;
   // print(head);

   if(detectloop(head)){
    cout<<"cycle is detected"<<endl;
   }
   else{
    cout<<"not detected"<<endl;
   }
}