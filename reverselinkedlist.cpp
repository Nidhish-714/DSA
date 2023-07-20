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

void insertAtHead(Node*& head , int data,Node*& tail){

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void display(Node* head){
    cout<<"hello";
    Node* temp = head;
    while(temp!=NULL){
       cout<< temp->data<<" ";
       temp = temp->next;
    }cout<<endl;

    cout<<"head is "<<head->data<<endl;
    // cout<<"tail is "<<tail->data<<endl;
}

void reverse(Node*& head){
    Node* curr = head ;
    Node* NEXT = NULL;
    Node* prev = NULL ;
    
    

    while(curr!=NULL){
        NEXT =curr->next;
        curr->next=prev;
        prev = curr;
        curr = NEXT;     
    }
 
}

// Node* recrev(Node*& head){
//     if(head->next == NULL){
//         return head ;
//     }

//     Node* chotahead = recrev(head->next);
//     head->next->next = head;
//     head->next = NULL;
// }

int getMiddle(Node*& head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast ->next;
        }

        slow = slow->next;
    }
    return slow->data;
}

int getLength(Node*& head){
    int cnt = 0 ;

    Node* temp = head;

    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

Node* kReverse(Node* head, int k) {
    //base call
    if(head == NULL) {
        return NULL;
    }
    
    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(next != NULL) {
        head -> next = kReverse(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
}

Node* myReverse(Node*&head){

    if(head->next == NULL){
        return head;
    }

    else{

        Node* newHead = myReverse(head->next);
        head->next->next = head;
        head->next=NULL;
        return newHead;
    }
}

void Reverse(Node* &head){
    Node * prev = NULL;
    Node*  curr = head;
    Node* next = curr->next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        head = curr;
        curr = next;

    }

    head = prev;
}

int main(){
    Node * node1 = new Node(3);
    Node* head = node1;
    
    Node* tail = node1;
 
    

    insertAtHead(head ,4,tail);
    insertAtHead(head ,5,tail);
    insertAtHead(head ,6,tail);
    insertAtHead(head ,7,tail);
    insertAtHead(head ,8,tail);

    //display(head);
    Node* ans = myReverse(head);
    display(ans);

    reverse(head);
    display(head);




  
   

//    reverse(head,tail);

//     display(head,tail);

//     // recrev(head);
//     // display(head,tail);

//     cout<<getMiddle(head)<<endl;
//     cout<<"length is "<<getLength(head);
    
   

    


}