#include<iostream>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int data;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
};


node* buildTree(node* root){
    cout<<"enter data for node"<<endl;
    int data ;
    cin>>data;
    root = new node(data);
    if (data==-1){
        return NULL;
    }

    cout<<"enter data for left of "<<data;

    root->left = buildTree(root->left);

    cout<<"enter data for right of "<<data;

    root->right = buildTree(root->right);

    return root;
}

int height(node* node){

    if(node==NULL){
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left,right)+1;
    return ans;
}

//diameter == longest path bw two node(leaf / root)

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left)+1+height(root->right);

    int ans = max(op1,max(op2,op3));
    return ans;
}

pair<int,int> diameterFast(node* root){//returns two values diameter and height 
    //base case
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int>right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int>ans;
    ans.first = max(op1,max(op2,op3));//first is diameter
    ans.second = max(left.second,right.second)+1;//second is height
    return ans;
}

//check for balance tree---height of left and right subtree is not more that 1 for all node

bool isBalanced(node * root){
    //base case
    if(root == NULL){
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left)-height(root->right)<=1);

    if(left && right && diff){//check wether tree is balanced or not
        return true;
    }else{
        return false;
    }
}

pair<bool,int> isBalancedFast (node* root){//balanced and height
    if(root = NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int>left = isBalancedFast(root->left);
    pair<bool,int>right = isBalancedFast(root->right);

    bool leftb = left.first;
    bool rightb = right.first;
    int lefth = left.second;
    int righth = right.second;

    bool diff = abs(lefth-righth<=1);

    pair<bool,int>ans;
    ans.second = max(left.second,right.second)+1;

    if(leftb && rightb && diff){//check wether tree is balanced or not
        ans.first = 1;
    }else{
        ans.first = false;
    }
    return ans;
}

//identical tree

bool identicalTree(node* r1 , node* r2){
    if(r1==NULL && r2==NULL){
        return true;
    }
    if(r1!=NULL && r2==NULL){
        return false;
    }
    if(r1==NULL && r2!=NULL){
        return false;
    }

    bool left = identicalTree(r1->left,r2->left);
    bool right = identicalTree(r1->right,r2->right);

    bool data = r1->data==r2->data;

    if(left && right && data){
        return true;
    }else{
        return false;
    }
    
}

//check sumtree or not

// node ki value = sum of left tree + right tree
//check first left and right are sumtree or not



pair<bool,int> isSumTree(node* root){
    //issumtree,sum
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL && root ->right==NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> left = isSumTree(root->left);
    pair<bool,int> right = isSumTree(root->right);

    bool leftb = left.first;//sumtree h ya nahi
    bool rightb = right.first;

    bool condn = root->data ==left.second + right.second;

    pair<bool,int> ans;

    if(leftb && rightb && condn){
        ans.first = true;
        ans.second = root->data + left.second + right.second; // or 2*root ->data (ek khud root aur ek sum of there left right roots)
    }else{
        ans.first = false;
    }

    return ans;




}





