#include<iostream>
#include <vector>
#include <queue>
using namespace std;
//#include<stdlib.h>

class node{
    public:
    node* left;
    node* right;
    int data;

    node(int data){
        this->data = data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){

    cout<<"enter data for node "<<endl;
    int data;
    cin>>data;

    root = new node(data);

    cout<<"enter data for left side of node"<< data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter data for right of "<<data;
    root->right = buildTree(root->right);
    return root;

}

vector <int> zigZagTraversal(node* root){

  vector<int> result;
    	if(root == NULL)
    	    return result;

    	queue<node*> q;
    	q.push(root);

    	bool leftToRight = true;

    	while(!q.empty()) {

    	    int size = q.size();
    	    vector<int> ans(size);

    	    //Level Process
    	    for(int i=0; i<size; i++) {

    	        node* frontNode = q.front();
    	        q.pop();

    	        //normal insert or reverse insert 
    	        int index = leftToRight ? i : size - i - 1;
    	        ans[index] = frontNode -> data;

    	        if(frontNode->left)
    	            q.push(frontNode -> left);

    	        if(frontNode->right)
    	            q.push(frontNode -> right);
    	    }

    	    //direction change karni h
    	    leftToRight = !leftToRight;

    	  for(auto i: ans) {
    	      result.push_back(i);
    	  }  
    	}
    	    return result;
    
}








