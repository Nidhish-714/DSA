#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node (int d){
        this ->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node*& head , int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        newNode->next = NULL;
        head = newNode;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void display(Node*& head){
    
    Node* temp = head;
    while(temp!=NULL){
       cout<< temp->data<<" ";
       temp = temp->next;
    }cout<<endl;

    cout<<"head is "<<head->data<<endl;
   
}


void reverse(Node* &head){
    Node * prev = NULL;
    Node* curr = head; 
    Node* next = curr->next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Node* reverseINk(Node* head,int k){
    if(head==NULL){
        return NULL;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    int count = 0;

    while(curr!=NULL && count<k){
        count++;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if(next!=NULL){
        head->next = reverseINk(curr,k);
    }

    return prev;

}

void removeDuplicatesSorted(Node * &head){

    Node*ptr1 = head;
    Node*ptr2 = ptr1->next;

    while(ptr2!=NULL){
        if((ptr2->next!=NULL)&&(ptr2->data == ptr2->next->data)){
            ptr2=ptr2->next;
            ptr1->next = ptr2;
        }
        else{
            ptr1->next=ptr2;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
}



void uniqueSortedList(Node *& head) {
   	//empty List
    
    //non empty list
    Node* curr = head;
    
    while(curr != NULL) {


        if( (curr -> next == NULL) ){
            curr = curr->next;
        }else
        if(curr -> data == curr -> next -> data) {
            Node* next_next = curr ->next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else //not equal
        {
            curr = curr -> next;
        }   
    }
    


    
}

Node*  sortzeoonetwo(Node*& head){
    Node* zeroTail; 
    Node* zeroHead = new Node(-1);
    Node* oneTail; 
    Node* oneHead = new Node(-1);
    Node* twoTail; 
    Node* twoHead = new Node(-1);

   zeroTail = zeroHead;
   oneTail = oneHead;
   twoTail = twoHead;

    Node* curr = head;

    while(curr!=NULL){
        if(curr->data == 0){
            zeroTail->next = curr;
            zeroTail=curr;
        }
        else if(curr->data == 1){
            oneTail->next = curr;
            oneTail = curr ;
        }
        else{
            twoTail->next = curr;
            twoTail=curr;
        }
        curr=curr->next;
    }

    zeroTail->next = oneHead->next;
    oneTail->next = twoHead->next;
    twoTail->next=NULL;

    head = zeroHead->next;

}

int main(){
    Node* head = NULL;
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,1);
    insertAtHead(head,0);
    insertAtHead(head,2);
    insertAtHead(head,0);
    insertAtHead(head,0);
    display(head);

    //reverse(head);
    //display(head);

    // Node* ans = reverseINk(head,2);
   
    // display(ans);

    // uniqueSortedList(head);

   sortzeoonetwo(head);
   display(head);
}