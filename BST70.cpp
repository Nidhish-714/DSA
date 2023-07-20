// LEFT SUBTREE ME DATA ROOT SE CHOTA HOGA FOR EVERY NODE
// RIGHT SUBTREE ME DATA ROOT SE BADA HOGA FOR EVERY NODE
#include<iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertInToBST(node*root, int d){
    //base case
    if(root == NULL){//kuch tha hi nahi first time
    root = new node(d);
    return root ;
    }

    if(d>root->data){
        //root ke right part me insert kro
        root->right = insertInToBST(root->right,d);//ek ek right root node se compare hkr ayega
    }else{
        root->left = insertInToBST(root->left,d);
    }
    return root;


}

void levelOrderTraversal(node* root){
//     1
//   3   5
// 7   9   8 
// 1 3 5 7 9 8----level k order me traverse krege

     queue<node*> q;//this queue consist of all node* here 1 3 5 all are a type of node
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
        node* temp = q.front();
        
        q.pop();

        if(temp==NULL){//purana level is traversed completely
            cout<<endl;
            if(!q.empty()){//has some child nodes left in queue
                q.push(NULL);
            }
        }else{
            cout<< temp->data <<" "<<endl;
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
            q.push(temp->right);
        }
        }

     }
}

void takeInput(node* & root){
    int data;
    cin>>data;
    while(data !=-1){
        insertInToBST(root,data);
        cin>>data;
    }

}

bool searchInBST(node* root,int d){
    if(root==NULL){
        cout<<"not present"<<endl;
        return false;
    }
    if(root->data == d){
        cout<<"yes present"<<endl;
        return true;
    }
    if(d>root->data){
        return searchInBST(root->right,d);
    }else{
        return searchInBST(root->left,d);
    }
}


// inorder of bst is sorted

int minInBST(node* root ){
    node* temp = root;

    while(temp->left!=NULL){
        temp = temp->left;

    }

    return temp->data;
}
int maxInBST(node* root ){
    node* temp = root;

    while(temp->right!=NULL){
        temp = temp->right;

    }

    return temp->data;
}
//delete node
//search that node
//if  node to delte == leaf node then just do null 

node* deletefromBST(node* root , int val){
    //base case
    if(root==NULL){
        return root;
    }
    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right != NULL && root->left == NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->right != NULL && root->left != NULL){
            int mini = minInBST(root->right);//get mini value from root ka right
            root->data = mini; ///replace mini
            root->right = deletefromBST(root->right,mini);//mini vali value deleted
            return root;
        }

    }
    else if(root->data > val){
        root->left = deletefromBST(root->left , val);//root ke left me delete k bad wala node lagado
        return root;
    }else{
         root->right = deletefromBST(root->right , val);
        return root;

    }
}

//validate BST
//inorder traversal is sorted 
//approach 1 -- take inorder traversal and check if sorted
//approach 2 -- har node k lie deko left me chota and right me bada
bool validateBST(node* root , int min , int max){
    if(root == NULL){
        return true;
    }
    if(root->data>min && root->data<max){
        bool left = validateBST(root->left,min,root->data);//range changes here
        bool right = validateBST(root->right,root->data,max);//range changes here
        return left&&right;
    }else{
        return false;
    }
}

//kth smallest element 
//inorder traversal is sorted
//use inorder traversal and jo k th == i node hgi 

int solve(node* root , int &i,int k ){
    if(root==NULL){
        return -1;
    }
//l
    int left = solve(root->left , i , k);

    if(left!=-1){
        return left;
    }
    //n
    i++;
    if(i==k){
        return root->data;
    }
    //r
    return solve(root->right , i , k);
}


//inorder precceder and succedor
//preceedor is us node se just chota element -- left subtree ka max element
//succedor is us node ka just bada element -- right ka sabse bada chota element
//first get that node and then find succedor preccedor
pair<int,int> precsucc(node* root , int key){
    node* temp = root;
    while(temp->data!=key){
        if(temp->data<key){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }

    pair<int,int> ans;
    ans.first = maxInBST(temp->left);//left ki tree me max element
    ans.second = minInBST(temp->right); //right tree ka sabse chota element
    return ans;

    /*
    pred = maxInBST();
    succ = minInBST();
    pair<int,int>ans = make_pair(pred,succ);
    return ans
    */


}

// 2 sum in BST
// target - node ko search krlia and node ko traverse krlia
// complexity - o(n^2)
// for O(N)
// in order is sorted -- always
// inorder travser save krlo and 2 pointer approach se sum nikalo
// sum>target j--
// sum< target i++


void inorder(node* root , vector<int>&in){
    if(root == NULL){
        return;
    }
    inorder(root->left , in);
    in.push_back(root->data);
    inorder(root->right,in);
}//inorder save krlia

bool twoSumBST(node* root , int target){
    vector<int> inorderVal;
    inorder(root,inorderVal);
    int i = 0 ; 
    int j = inorderVal.size()-1;
    while(i<j){
        int sum = inorderVal[i]+inorderVal[j];
        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}


//flatten a BST tree is linear sorted
//inorder traverse save
//sabka left null kreke right age lagao
//last ka left right nulll krdena

node* flatten(node* root){
    vector<int> inorderVal;
    inorder(root,inorderVal);
    node* newRoot = new node(inorderVal[0]);
    node* curr = newRoot;

    for(int i = 1 ; i< inorderVal.size();i++){
        node* temp = new node(inorderVal[i]);//age ka node banaya
        curr->left =NULL;
        curr->right = temp;
        curr = temp;

    }

    curr->left = NULL;//curr == temp hgya n akhri loop me 
    curr->right = NULL;

}

// BST to balancedBST
//har node pr check kro height and height ka diff <-1 hai ky (height , true/false) dekho

//inorder  save krlo (sorted)

//tree banalo rec se

node* inorderToBST(int s , int e, vector<int>&inorderVal){
    if(s>e){//base case
        return NULL;
     }

     int mid = (s+e)/2;
     node* root = new node(inorderVal[mid]);
     root->left = inorderToBST(s , mid-1 , inorderVal);
     root->right = inorderToBST(mid+1 , e , inorderVal);

}//inorder se bst banake dedega


node* balancedBST(node* root){
    vector<int> inorderVal;
    inorder(root,inorderVal);//vector of sorted tree
    return inorderToBST(0,inorderVal.size()-1,inorderVal);//tree banade iska


}


//MERGE 2 BST
//*********VERY IMP************
//INORDER SE BST BANANA ATA HAI
//BST SE INORDER BANANA ATA HAI
//BST 1  SE INORDER 1 BANAO 
//BST 2  SE INORDER 2 BANAO 
//MERGE  BOTH INORDERS 
//RSEULT INORDER SE BST BANAO


// void inorder(node* root , vector<int>&in){
//     if(root == NULL){
//         return;
//     }
//     inorder(root->left , in);//left ka inorder save krlo 
//     in.push_back(root->data);//node ka data push kro 
//     inorder(root->right,in);//right ka inorder save krlo
// }//inorder save krlia

vector<int> mergedArray(vector<int> a,vector<int> b){
    vector<int> ans(a.size()+b.size());

    int i = 0; 
    int j = 0;
    int k = 0;

    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }

    while(i<a.size()){
        ans[k++] = a[i];
        i++;
    }
    while(j<b.size()){
        ans[k++] = a[j];
        j++;
    }
}

node* mergeTwoBST(node* root1 , node* root2){
    //STEP 1 STORE INORDER
    vector<int>bst1;
    vector<int>bst2;
    inorder(root1,bst1);
    inorder(root1,bst2);

    vector<int>mergeArray = mergedArray(bst1,bst2);
    int s=0,e=mergeArray.size()-1;//index
    return inorderToBST(s,e,mergeArray);
}


//APPROACH 2 ---SPACE COMPLEXITY AND TIME COMPLEXITY KAM LAGE
//CONVERT BST INTO SORTED LL OR FLATTEN SORETED (WILL REDUCE SPACE) (JUST CHANGE POINTER --O(1))
//MEREGE 2 SORETD LL
//MAKE BST FROM SORETD LL

//BST TO DOUBLY LL CONVERSION

//ROOT ->RIGHT KA DLL ME CONVER KRO && RETURN ITS HEAD of dll
//ROOT ->LEFT KA DLL ME CONVER KRO && RETURN ITS HEAD of dll
//ROOT = HEAD KRDO
//RETURN HEAD

void convertIntoSortedDLL(node* root,node*&head){
    if(root == NULL){
        return ;
    }
//solve onlyu 1 case (right ka)
    convertIntoSortedDLL(root->right,head);
    root->right = head;//head of dll of right as passed by ref
    if(head!=NULL){
        head->left = root;//dono way connected
    }
    head = root;//head update krdia
    convertIntoSortedDLL(root->left,head);//right bhi convert krdo
    
}

node* mergeLL(node* head1 , node*head2){
//main ll ka head tail
    node* head = NULL;
    node* tail = NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data <head2->data){
            if(head==NULL){//first condn
                head=head1;
                tail = head1;
                head1 = head->right;

            }else{
                tail->right = head1;
                head1->left  = tail;
                tail = head1;
                head1 = head->right;

            }

        }else{
            if(head == NULL){
                head=head2;
                tail = head1;
                head1 = head2->right;

            }else{
                tail->right = head2;
                head2->left  = tail;
                tail = head2;
                head2 = head2->right;
                
            }

        }
    }
    while(head1 !=NULL){
        tail ->right = head1;
        head1 ->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 !=NULL){
        tail ->right = head2;
        head2 ->left = tail;
        tail = head2;
        head2 = head2->right;
    }

}
//make bst from sorted dll

//make tree from n/2 linked list
//left* = n/2 nodes ka tree banao
//create root 
//root ->left = left
//head->next
//righr subtree bnao
int countNodes(node* head){
    int cnt =0;
    node* temp = head;
    while(temp!=NULL){
        temp = temp->right;
        cnt ++;
    }
    return cnt;
}

node* sortedllToBST(node*&head , int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    node* left = sortedllToBST(head,n/2);//adhe ka tree bana pele
    node* root = head;//head is passed by refrence islie line 495 se head change hga
    root ->left = left;//attach left subtree
    head = head->next;
    root->right = sortedllToBST(head,n-n/2-1);
    return root;
}
//sum up
node* mergeTwoBST2(node* root1,node* root2){

    //conver bst into sorted dll
    node* head1 = NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL;

    node* head2 = NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL;

    //merge them

    node* head = mergeTwoBST2(head1,head2);//head of both dll passed and made one common head

    //convert sorted dll into tree
    return sortedllToBST(head , countNodes(head));

}

//largest BST
//har node pr jao aur deko wether its valis BST or node //app1


//app2
//leftsubtree--valid??
//rightsubtree--valid??
//maxleft<root->data<right min

class info{
    public:
    int max;
    int min;
    bool isBST;
    int size;
};

info solve(node* root , int&ans){
    //base case
    if(root==NULL){
        return{INT_MIN,INT_MAX,true,0};
    }
    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currNode;

    currNode.size = left.size+right.size+1;
    currNode.max = max(root->data , right.max);
    currNode.min = max(root->data , left.min);

    if(left.isBST && right.isBST && (root->data>left.max && root->data<right.min)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    //answer update
    if(currNode.isBST){
        ans = max(ans,currNode.size);
    }
    return currNode;
}





int main(){
    node* root = NULL;
    cout<<"enter data to create BST"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
}