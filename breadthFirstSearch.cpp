// traversal technique

// keep a ds tht will keep track of what is printed already
// unourder_map<node,bool>;

// create adjacency list or neighbour list
// if(!visited){
//   bfs()
// }

// step 1 frontnode push in queue 
// step 2 delete frontnode  
// step 3 mark visited for frontnode
// step 4 cout<<frontnode
// step 5 push neighbour node of frontnode in queue from adjacency list which are not visited
 

#include <iostream>
using namespace std;
#include <unordered_map>
#include <set>

#include <unordered_map>
#include <queue>
void prepareAdj(unordered_map<int,set<int>>&adjList , vector<pair<int, int>>&edges ){

    for(int i = 0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>>&adjList,unordered_map<int,bool>&visited,
        vector<int>&ans , int node){
            queue<int>q;
            q.push(node);
            visited[node] = 1;
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                ans.push_back(frontNode);
                // traverse all nodes from adjacentlist
                for (auto i : adjList[frontNode]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
            }
        }
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
   unordered_map<int,set<int>>adjList;
   vector<int>ans;
   unordered_map<int,bool>visited;

   prepareAdj(adjList , edges);

   //traverse all components of graph

   for(int i = 0 ; i<vertex;i++){
       if(!visited[i]){
           bfs(adjList , visited , ans , i );
       }
   }
   return ans;
}

