#include <iostream>
using namespace std;

//last node points to first node rather than null

class node {
    public:
    int data;
    node* next;

    //constructor
    node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~node(){
        int val = this->data;
        if (this ->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"memory is freed"<<endl;
    }
};

void insertNode(node *&tail,int element , int d){

    //empty list
    if(tail = NULL){
        node* newnode = new node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else{
        //nonemptylist
        node* curr = tail;
        while(curr->data = element){//traversing till we not get that particular element
        curr = curr->next;
        }
//element found -> curr is representing element wala node
        node *temp = new node(d);
        temp->next = curr ->next;
        curr->next = temp;
    }



}

void deleteNode(node *&tail,int value){
    if(tail == NULL){
        cout<<"list is empty please check again"<<endl;
        return ;
    }

    else{
        node *prev = tail;
        node *curr = prev ->next;

        while(curr -> data!=value){
            prev = curr;
            curr = curr->next;
        }
        prev -> next = curr->next;

        //one node linkedlist

        if(curr == prev){
            tail = NULL;

        }
        else if(tail = curr){
            tail = prev;
        }
        curr ->next = NULL;
        delete curr;
    }
}

void print(node* tail){
    node* temp  =  tail;

    // cout<< tail->data<<" ";
    // while(tail ->next != temp){
    //     cout<< tail->data <<" ";
    //     tail = tail ->next;
    // }//can do with dowhile loop
    // cout<<" ";

    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

int main(){

    node *tail = NULL; 

    //empty
    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    return 0;

}