//when node is visited and not its parent
#include <iostream>
using namespace std;
#include <unordered_map>
#include <queue>
#include <list>

bool isCycleBFS(int src ,unordered_map<int,bool>&visited,unordered_map<int,list<int>> &adj ){
    unordered_map<int,int>parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int>q;
    q.push(src);


    while(!q.empty()){
        int front = q.front();
        q.pop();


        for(auto n:adj[front]){
            if(visited[n]==1 && n !=parent[front]){
                return true;
            }
            else if(!visited[n]){
                q.push(n);
                visited[n]=1;
                parent[n]=front;
            }
        }
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;

    for(int i =0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconneted components
    unordered_map<int,bool>visited;

    for(int i = 0; i<n ;i++){
        if(!visited[i]){
            bool ans = isCycleBFS(i,visited,adj);
            if(ans==1){
                return "Yes";
            }
        }

    }

    return "No";

    
}
