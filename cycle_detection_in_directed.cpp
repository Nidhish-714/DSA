#include <iostream>
using namespace std;
#include <unordered_map>



// ek map banao jo track rkhgea ki kis node k liye function call hua hai pehle
// agar koi function call dfs ka map pelese 1 ho and phirse uski call jaye then cycle is present


bool checkCycleDFS(int node , unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,unordered_map<int,list<int>>&adj){

    visited[node]=true;
    dfsVisited[node]=true;

    for(auto n :adj[node]){

        if(!visited[n]){
            bool cycleDetected = checkCycleDFS(n,visited,dfsVisited,adj);
            if(cycleDetected){
                return true;
            }


        }

                    else if(dfsVisited[n]){
                return true;
                //visited true
            }

    }
             dfsVisited[node]=false;
         return false;

   

}

int detectCycleInDirectedGraph(int n, vector<pair<int,int>>&edges){

      unordered_map<int,list<int>>adj;
    for(int i =0 ;i<edges.size();i++){

      

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        //adj[v].push_back(u); --as directed

    }

    //call  dfs for all components

    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;

    for(int i =0;i<=n;i++){
        if(!visited[i]){
            bool cyclefound = checkCycleDFS(i,visited,dfsVisited,adj);
            if(cyclefound){
                return true;
            }
        }
    }

    return false;

    
}