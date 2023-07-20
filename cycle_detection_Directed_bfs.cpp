// Kahns algorithm using bfs gives valid topological sort in directed acyclic grpah
// if we get invalid topological sort then we can say cycle exist (cyclic graph)




#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
// Kahns algorithms
// Find in degree of all nodes
// Queue me 0 indegree elements push kro
// Do BFS


// Jabbi ans me number dalre tab uska arrow nikalo and uske karan jiska bhi in degree  0 hua use push krdo queue me
// Aur jo queue se pop hua usko ans me dalo
// Aur jo next front hai uske sath same
// Aur jo arrow nikala uske karan uske neighbour ki degree jo kam hui vo bhi update kro

bool topologicalSort(vector<vector<int>>&edges ,int v, int e){
     unordered_map<int,list<int>>adj;

        for(int i = 0;i<e;i++){
        int u = edges[i][0]-1;//ye algo 0 nodes se start hone k liye kam karega but given hamne first nodes hai
        int v = edges[i][1]-1;

        adj[u].push_back(v);
     
    }

//indegree batao
    vector<int> indegree(v);

    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    queue<int>q;
// 0 indegree wale push
    for (int i =0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //bfs kro
int cnt=0;
    vector<int>ans;

    while(q.empty()){
        int front =q.front();
        q.pop();

        //inc cnt
        cnt++;

        ans.push_back(front);

        for(auto n: adj[front]){

            indegree[n]--;

            if(indegree[n]==0){
                q.push(n);
            }

        }

     
    }

    if(cnt ==v){
        return false;//valid toplogical sort therefore no cycle is present
    }else{
        return true;
    }
       //return ans;


}    