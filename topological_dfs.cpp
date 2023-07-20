// applied only on DAG - directed acyclic graph
// it is a linear ordering of vertices such that for ever for every edge u->v 
// u always appears before v in that linear ordering

#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>

void topoSort(int node,unordered_map<int,bool>&visited,stack<int>&s, unordered_map<int,list<int>>adj){
    visited[node]=true;

    for(auto n : adj[node]){
        if(!visited[n]){
            topoSort(n,visited,s,adj);
        }
    }
    s.push(node);
}


vector<int> topologicalSort(vector<vector<int>>&edges ,int v, int e){
     unordered_map<int,list<int>>adj;

        for(int i = 0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
     
    }
stack<int>s;
unordered_map<int,bool>visited;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,visited,s,adj);
        }
    }

    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();

    }
    return ans;
}
