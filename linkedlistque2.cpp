#include <iostream>
#include <map>
using namespace std;

//reverse linked list in k groups
// 3 2 7 8 9 11    k=2  
// 2 3 8 7 11 9
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
};

node *kReverse(node *head, int k){
    //base case
    if(head = NULL){
        return NULL;
    }
    //step 1: rever first k nodes
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;
    int count = 0;
    while(curr!=NULL && count< k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }//first k nodes reverse hgai

    //age rec dklega
    if(next!=NULL){
        head ->next = kReverse(next,k);//prev return hga idhr
    }

    //step 3 return head of rev list 
    return prev;


}

bool circularornot(node *head){

    if(head ==NULL){
        return true;//empty list always circularlist
    }

    node *temp = head->next;

    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }

    if(temp=head){//loop se konsi condition par bahar aya wo dekho
        return true;//circular list hai
    }
    return false;//loop se temp = NULL ki condition par  bahar aya

}

bool detectloop(node* head){
    if(head==NULL){
        
        return false;
    }

    map<node*,bool>visited; //map banaya jo traverse krega and true true krega jaha bhi jaye
//if pele se koi true then loop is present
    node *temp = head;

    while(temp !=NULL){

        if(visited[temp] == true){
            //loop is present
            cout << "cycle is present at " << temp->data << endl;
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

//floyds detection loop algo---
//ek fast node ek slow node and traverse kro loop me if kabi fast == slow
// ajaye then loop is present
//fast is == null then no loop

node* floydDetectLoop(node *head){
    if(head==NULL){
        return NULL;
    }

    node* slow = head;
    node* fast = head;

    while(slow != NULL && fast !=NULL){
        fast = fast->next ;
        if (fast = NULL){
            fast = fast->next;
        }

        slow=slow->next;

        if(slow == fast){

            cout<<"present at "<<slow->data<<endl;
            return slow;
        }
    }

    return NULL;
}
//to find first node where loop starts
//  _________
//      |   |
//      |___|


// jaha slow and fast mile udr fast lagao and slow ko head m dalo phir same speed 
// se traverse  kro and jaha vo milege vo hga starting node

node* getStartingNode(node* head){
    if(head==NULL){
        return NULL;
    }

    node* intersection = floydDetectLoop(head);

    node * slow = head;

    while(intersection!=slow){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;//starting node dedia using floyd
}

//to remove the loop --->> if we pointed a node to null which is just previous to
//node where loops starts

void removeLoop(node *head){
    if(head == NULL){
        return;
    }

    node* startOfLoop = getStartingNode(head);
    node* temp = startOfLoop;
    while(temp ->next !=startOfLoop){
        temp = temp->next;
    }

    temp->next=NULL;
}

//clone a linkedlist with random pointers

