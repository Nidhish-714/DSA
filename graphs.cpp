#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>
template <typename T>


// graph is datastructure which is a combination of verticed and edges

// u------v ==v-----u same edge in undirected graph
// degree of vertices is number of edges from it
// in directed graph indegree is number of arrow coming towards me
// in directed graph outdegree is number of arrow coming outwards from me
// assume weight to be 1 if not given
// path is sequence of node u--v--p , p--q--z, (p--q--z--p is not a path as p do bar)
// cyclic graph a--b--c--d--a (if weighted and directed then weighted directed cyclic graph)
// a-->d
// |   | acyclic graph
// b-->c

// adjacency matrix indexes are nodes // For loop se nested se krlo
// adjacency list consist of a list of nodes through which it is connected
// adjacency list can be implement by map<int,list<int>>;


class graph {

    public:

    unordered_map<T,list<T>>adj;

    void addEdge(T u , T v , bool direction){
        // direction 1 -- directed graph
        // direction 0 -- undirected graph

        //create an edge from u to v

        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);//adjaceny list
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<< j << " ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"enter number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<" enter number of edges"<<endl;
    cin>>m;

    graph <int> g;

    for(int i = 0;i<m ; i++){
        int u,v;
        cin>>u>>v;
        // creating a undirected graph
        g.addEdge(u,v,0);
    }
    g.printAdjList();
}
