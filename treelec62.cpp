#include<iostream>
#include<queue>
using namespace std;

// node --consist of data 
// binary tree -- consisit of 2 or less than two nodes
// root -- is top most node in tree
// sibling -- whose parents are same
// ancestors -- ek node k upper k sare nodes
// descendants -- ek node k sare nichhe node
// leafnode -- node that does not have any child


//-----Binary Tree Implemnetation-----
class node{
    public:
    int data;
    node* left;//for left node in binary tree
    node*right;//for right node in binary tree

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){//to build tree not a node;
    int data;
    cout<<"enter the data for node "<<endl;
    cin>>data;
    root = new node(data);

    if (data==-1){
        return NULL;
    }

    cout<<"enter node for left of " <<data <<endl;
    root->left = buildTree(root->left);

    cout<<"enter node for right  "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

void levelrOderTraversal(node* root){
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
//inOrder -- LNR
//preOrder -- NLR
//postOrder -- LRN

void inOrder(node* root){
    //basecase
    if(root==NULL){
        return;
    }

    inOrder(root->left);//L
    cout<<root->data<<" ";//N
    inOrder(root->right);//R
}
void preOrder(node* root){
    //basecase
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";//N
    preOrder(root->left);//L
    preOrder(root->right);//R
}
void postOrder(node* root){
    //basecase
    if(root==NULL){
        return;
    }

    postOrder(root->left);//L
    postOrder(root->right);//R
    cout<<root->data<<" ";//N
}
void buildFromLevelOrder(node*&root){
    queue<node*>q;

    int data;
    cout<<"enter data for root"<<endl;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"enter left node for"<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout<<"enter right node for"<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right = new node(leftData);
            q.push(temp->right);
        }//jab -1 dalege tab queue me kuch nahi jayega and hamesha pop bhi hora hai aislie while loop ki condn khtm hgi
    }
}


int main(){
    node* root = NULL;
    // create a tree
    root = buildTree(root);


    return 0;
}