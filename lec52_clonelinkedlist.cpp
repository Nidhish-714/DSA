// clone a linkedlist with random pointers
// this ll has a data , next ptr and random ptr
// o/p give same linkedlist

// approach 1)
// create a clone list in serial manner
// for random ptr copy
// org ll se deko random ptr kitna dur hai ( count deko) ,uske hisab se clone ll me random
// ptr copy krwao

// approach 2)
// create a clone ll using next ptr
// mapping banao old node ki new node k sath

// clone->random = mapping[orgnode->random]
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *random;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(node *&head, node *&tail, int d)
{ // e head and tail clone wale ko point krre
    node *newNode = new node(d);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode; // update tail
    }
}

node *copyList(node *head)
{
    // step 1 create a clone list
    node *cloneHead = NULL;
    node *cloneTail = NULL;

    node *temp = head; // org ka h

    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 create a map

    unordered_map<node *, node *> oldToNewNode;

    node *orginalNode = head;
    node *cloneNode = cloneHead;
    // create mappings
    while (orginalNode != NULL && cloneNode != NULL)
    {
        oldToNewNode[orginalNode] = cloneNode; // mappings banao
        orginalNode = orginalNode->next;
        cloneNode = cloneNode->next;
    }

    orginalNode = head;
    cloneNode = cloneHead;

    while (orginalNode != NULL)
    {
        cloneNode->random = oldToNewNode[orginalNode->random];
        orginalNode = orginalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
} // tc and sc is O(n)

// approach 3
// changing links
// step 1 create a clone list
// step 2 clone nodes ko add kro between orginal list (two orginal node k bich ek clone node)
// temp head (org ka)
// set random
// temp->next->(clone m agye)random = temp->random->next
// revert changes done in step 2
// return clone ka head---------- O(1 )sc and tc

node *copyList1(node *head)
{
    // step 1 create a clone list
    node *cloneHead = NULL;
    node *cloneTail = NULL;

    node *temp = head; // org ka h

    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 clone nodes ko add kro between orginal list (two orginal node k bich ek clone node)
    node *orginalNode = head;
    node *cloneNode = cloneHead;
    while (orginalNode != NULL && cloneHead != NULL)
    {
        node *next = orginalNode->next;
        orginalNode->next = cloneNode;
        orginalNode = next;

        next = cloneNode->next;
        cloneNode->next = orginalNode;
        cloneNode = next;
    }

    // step 3 random ptr copy temp->next->(clone m agye)random = temp->random->next
    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            if (temp->random != NULL)
            {
                head->next->random = head->random->next;
            }
            else
            {
                temp->next = temp->random;
            }
        }

        temp = temp->next->next;
    }

    // step 4 revert changes done in step 2
    orginalNode = head;
    cloneNode = cloneHead;
    while (orginalNode != NULL && cloneHead != NULL)
    {
        orginalNode->next = cloneNode->next;
        orginalNode = orginalNode->next;
if(orginalNode!=NULL)
        {cloneNode->next = orginalNode->next;}
        cloneNode = cloneNode->next;
    }

    // step 5 return ans
    return cloneHead;
}
