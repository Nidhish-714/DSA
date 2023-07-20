// adj list banao
// dist wla vector banao
// set banao of type pair of dist and node
// and for all front node ke neighbours k liye deko weight and if
// weight kam h dist node me then update krdo
#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <limits.h>

vector<int> dijkstra(vector<vector<int>>&vec , int vertices , int edges ,int source){
    unordered_map<int,list<pair<int,int>>>adj;

    for(int i = 0;i<edges ; i++){
        int u = vec[i][0];
        int v = vec[i][1];

        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int>dist(vertices);

    for(int i =0;i<vertices;i++){
        dist[i] = INT_MAX;

    }

    set<pair<int,int>>st;

    dist[source] =0;
    st.insert(make_pair(0,source));

    while(!st.empty()){


        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());


        for (auto n : adj[topNode]){
            if(nodeDistance+n.second<dist[n.first]){//n.first is node

            auto record = st.find(make_pair(dist[n.first],n.first));



            if(record!=st.end()){

                st.erase(record);

            }


            dist[n.first] = nodeDistance+n.second;
            st.insert(make_pair(dist[n.first],n.first));

            }
        }


    }

    return dist;
}