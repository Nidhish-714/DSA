// reverse a linked list
//  swapping will not work here , we have to reverse the address
//  using 2 pointer approach , we will make prev curr forward pointers
//  curr ka next is forward , so that when we changing address back we should not loose
//  baki k nodes ka link.... curr ka next ko prev m store ,prev = curr and curr = forward
// do till curr is not equal to null
// my prev will point to head now....return prev

#include <iostream>
#include <vector>
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
};

node *reverseLinkedList1(node *head)
{ // approach 1  (iterative)

    if (head->next = NULL)
    {
        return head; // empty or single node//empty -> head = NULL;
    }

    node *prev = NULL;
    node *curr = head;
    node *forward = curr->next;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
}

void reverse(node *&head, node *&curr, node *&prev)
{
    // base case
    if (curr = NULL)
    {
        head = prev; // head piche agyaa
        return;
    }

    else
    {
        node *forward = curr->next;
        reverse(head, forward, curr); // yahase bas age age jare
        curr->next = prev;
    }
}

node *reverse1(node *head)
{ // will return head of reverse list ( and will reverse)
    // base case
    if (head->next = NULL)
    {
        return head;
    }

    node *chotahead = reverse1(head->next); // here head of rev list ayega
    head->next->next = head;
    head->next = NULL;

    return chotahead;
}

node *reverseLinkedListrec(node *head)
{ // approach 2 (recursive)

    node *prev = NULL;
    node *curr = head;
    node *forward = curr->next;

    reverse(head, curr, prev);
    return reverse1(head); // another function
}

int getlength(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

node *findmiddle(node *head)
{
    int len = getlength(head);
    int ans = (len / 2); // no +1 as temp->next krke return kra hai
    node *temp = head;
    int cnt = 0;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

// do node ek dfast ek slow  fast ->next->next krega and slow ek bar next
//  fast jab n traverse kia hga tab slow n/2 traverse kia hga

node *getmiddle(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    if (head->next->next == NULL)
    {
        return head->next;
    }

    node *slow = head;
    node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}

// remove duplicates  1) sorted ND 2)unsorted

// 1) sorted linkedlist
// 12245667 if duplicate is present then it is just after that element ( sorted )

// if next element is different do curr=curr->next
// if next element is same then delete that node and curr-> next = curr-> next -> next node

node *uniqueSortedList(node *head)
{
    // empty list

    if (head == NULL)
    {
        return NULL;
    }

    // nonempty list

    node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {                                       // equal cond
            node *next_next = curr->next->next; // store in variable ,kyuki delte hone k bad uska record nai hga
            node *nodeToDelete = curr->next;    // next wala duplicate hai to usk delete krdo
            delete (nodeToDelete);              // pele delete krna hga
            curr->next = next_next;             // phir ye step ,vrna node to delte ehich is curr->next uska koi address nai hga ,kyuki vo is line me update ho chuka hai
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

// 2) remove duplicates from unsorted linked list
// 21425762  approach 1)  curr node lo and temp node lo jo curr se lkr null tak traverse krega
// if same aya then delete then curr ka next and same loop

// approach 2) step1 - sort the linkedlist and step2 - is remove duplicate from sorted ll (upper ka que)

// map <node*  , bool > = node* <key , value>
// approach 3) using map --> map se traverse kro if different data the mark true  if same data encounter hua ya visited[]==true mila
// then delete krdo

// map<node *, bool> visited;
// node *temp = head;

// while (temp != NULL)
// {

//     if (visited[temp->data] == true)
//     {
//        delete kro
//     } nahi to ye kro
//     visited[temp->data] = true;
//     temp = temp->next;
// }

// sort 0s and 1s and 2s in LL

// approach
// no of 0s  1s 2s count kro
//  then insert till count

node *sortlist012app1(node *head)
{
    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;

    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zerocount++;
        }
        else if (temp->data == 1)
        {
            onecount++;
        }
        else if (temp->data == 2)
        {
            twocount++;
        }

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (zerocount != 0)
        {
            temp->data = 0;
            zerocount--;
        }
        else if (onecount != 0)
        {
            temp->data = 1;
            onecount--;
        }
        else if (twocount != 0)
        {
            temp->data = 2;
            twocount--;
        }

        temp = temp->next;
    }
    return head;
}

// approach2 -- no data replacement,
//-----> change links
// create 3 linked list then merge

void insertAtTail(node *&tail, node *curr)
{
    tail->next = curr;
    tail = curr; // tail updated
}
// created a list seperate for 0 1 2
node *sortlist012app2(node *head)
{
    node *zerohead = new node(-1);
    node *zerotail = zerohead; // tail pr hi dalna h values
    node *onehead = new node(-1);
    node *onetail = onehead;
    node *twohead = new node(-1);
    node *twotail = twohead;

    node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertAtTail(zerotail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(onetail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twotail, curr);
        }

        curr = curr->next;
    }

    // merge3 list

    if (onehead->next != NULL)
    { // nonemptylist of 1
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next; // list of 1 is empty
    }

    onetail->next = twohead->next;
    twotail->next = NULL;

    // setup head

    head = zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;
}

// merege 2 sorted linkedlist
// we have 2 heads , insert nodes from head 2 to in head 1

node *solve(node *first, node *second)
{

    // if only one element is present in first list

    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }
    node *curr1 = first;
    node *next1 = curr1->next;
    node *curr2 = second;
    node *next2 = curr2->next; // so that 2nd ll ka data lost na ho

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next; // so that 2nd ll ka data lost na ho
            curr2->next = next1;
            // updating pointers
            curr1 = curr2; // curr1 inserted value ko point karra hai
            curr2 = next2; // curr2 updated
        }

        else
        { // if cannot insert
            // curr1 and next1 ko age badaye
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
            }
        }
    }
}

node *sortTwoLists(node *first, node *second)
{

    if (first == NULL)
    {
        return second;
    }
    else if (second == NULL)
    {
        return first;
    }

    if (first->data <= second->data)
    {
        return solve(first, second); // jo chota usme nodes dalo
    }
    else
    {
        return solve(second, first); // second ko as a first use kro
    }
}


//if palindrom linkedlist or not ---both side same

// approach 1) array banao and copy kro content and check palindrome in array


bool checkPalindrome(vector<int> arr){
    int n =arr.size();
    int s=0;
    int e = n-1;

    while(s<=e){
        if(arr[s]!=arr[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}//O(n) --time and space complexity

bool isPalindrome(node * head){
    vector <int> arr;

    node* temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);
}


//approach 2)

// middel of ll tak traverse kro then middle +1 se akhri tak reverse kro 
// and compare head and middle while traversing


node* getMid(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast!= NULL && fast->next!=NULL){
        fast = fast ->next->next;
        slow = slow->next;
    }

    return slow;
}

node* reverseforpalindrome(node* head){
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;

    while (curr!=NULL){
        next = curr->next;//save krke rkhodo
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;//akhri element jayega
    
}

bool isPalindrome( node* head){
    if(head->next == NULL){
        return true;//empty list or single list
    }

    //step 1-> find middle

    node* middle = getmiddle(head);

    node* temp = middle->next;
// step 2-- reverse kro half ko
    middle->next = reverseforpalindrome(temp);//middle k next ka part return krega

    //step 3 -- compare both halves

    node* head1 = head ;
    node* head2 = middle ->next;

    while(head2 !=NULL){
        if(head1->data!=head2->data){
            return false;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    //step 4 --- repeat step 2 ( wapis reverse for org ll)
    temp = middle ->next;
    middle->next = reverseforpalindrome( temp );//nahi  bhi kroge to bhi chalega

    return true;
}

//add 2 numbers using linkedlist

//    3--4--NULL
// 2--3--0--NULL
// ____________
// 2--6--4--NULL -- ans 

// approach 1) both ll ko reverse kro then head se add kro then jo ans aya usko reverse kro
// reverse kyuki hame left se add krna hta hai

node *reverseforaddtwolist(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next; // save krke rkhodo
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev; // akhri element jayega
}

void insertAtTailforadd(node* &head , node* &tail , int val){//anshead , anstail ka dusra nam
    // create node and add in answer linked list
node* temp = new node(val);
    if(head== NULL){
        head = temp;
        tail = temp;
        return ;
    }

    else{//anstail k last me add krte rho
        tail ->next = temp;
        tail = temp;
    }
}

node *add(node *first, node *second)
{
    //step 1 carry is 0
    //step 2 sum nikalo
    //step 3 digit nikalo by sum%10 -- node hga
    //step 4 carry nikalo sum/10 se
    //step 5 create node for digit
    //step 6 again carry nikalo

    node* ansHead = NULL;
    node* ansTail = NULL;

    int carry = 0;

    while(first!=NULL && second!=NULL){
        int sum = carry + first->data + second->data;
        int digit = sum%10;
        insertAtTailforadd(ansHead,ansTail,digit);
        carry = sum%10;
        first = first->next;
        second = second->next;

    }

    while(first!=NULL){//second wala null hgya
        int sum = carry+ first->data;
        int digit = sum % 10;
        insertAtTailforadd(ansHead, ansTail, digit);
        carry = sum % 10;
        first=first->next;
    }
    while(second!=NULL){//first wala null hgya
        int sum = carry+ second->data;
        int digit = sum % 10;
        insertAtTailforadd(ansHead, ansTail, digit);
        carry = sum % 10;
        second= second->next;
    }
    while(carry!=0){
        //same length ki list and uske bad bhi carry bacha hua hai
        int sum = carry;
        int digit = sum % 10;
        insertAtTailforadd(ansHead, ansTail, digit);
        carry = sum % 10;
    }

    return ansHead;
}
node* addTwoList(node* first , node* second){
    //step 1 reverse list
    first = reverseforaddtwolist(first);
    second = reverseforaddtwolist(second);

    //step 2 add list
    node* ans = add(first,second);

    //step 3 - reverse ans
    ans = reverseforaddtwolist(ans);

    return ans;
}

// merge sort in linked list ( no data replacement , only change links )


node* findMid(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    node* ans = new node(-1);//dummy node
    node*temp = ans;

    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next = left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left!=NULL){

        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right!=NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;//dummy node k samne ka
    return ans;
}
node* mergeSort(node* head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    //break ll into two halves

    node* mid= findMid(head);

    node*left = head;
    node*right = mid->next;
    mid->next = NULL;

    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both linkedlist

    node* result = merge(left,right);

    return result;
}
//flatten linkedlist