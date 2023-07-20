// ek char pakdo vo agar mila to age bado aur nahi mila to banao and age badao
// har ek node ke 26 child ho skte hai
// last node of each child is terminal node
// if last letter ==terminal node then word is found ,if no then no found
#include <iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0 ; i<26 ; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertAtUtil(TrieNode* root , string word){
        //base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

       

        int index = word[0]-'A';
        TrieNode* child;
        //present to age bado
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            //absent to banao aur vo insert krke age bado

            child= new TrieNode(word[0]);
            root->children[index] = child;
        }
        //recursion
        insertAtUtil(child,word.substr(1));
    }

     void insertWord(string word){
            insertAtUtil(root ,word);
    }

    bool searchUtil(TrieNode* root,string word){

        //base case
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            //absent
            return false;
        }
        //recursion
        return searchUtil(root,word.substr(1));




    }
    bool search(string word){
       return searchUtil(root,word);
        
    }
};

int main(){
    Trie *t = new Trie();
    t->insertWord("ABCD");

    cout<<"present or not "<<t->search("ABCD")<<endl;
}