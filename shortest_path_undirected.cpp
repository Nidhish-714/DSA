#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

// adj list banao
// parents ko track krna hai
// bfs algo jaisa level wise visited mark kro and parent dalo and queue me push kro--for parenrt

// parent se shortest path nikalo --destination node pakad ke backtrack krege till we get source node


#include<unordered_map>
#include<queue>
#include<list>


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){


	unordered_map<int,list<int>>adj;
	
	for(int i = 0;i<edges.size();i++){

		int u = edges[i].first;
		int v = edges[i].second;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//do bfs

	unordered_map<int,bool>visited;
	unordered_map<int,int> parent;

	queue<int>q;

	q.push(s);
	parent[s]=-1;

	visited[s]=true;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto i:adj[front]){
			if(!visited[i]){
				
				visited[i]=true;
				parent[i]=front;
				q.push(i);
			}
		}
		 
	}

	vector<int>ans;

	int currNode = t;

	while(currNode != s){
		currNode = parent[currNode];
		ans.push_back(currNode);
	}

	reverse(ans.begin(),ans.end());

	return ans;

	
}
