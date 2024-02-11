#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<pair<int,int>>*adj;

    public:
Graph(int v){
    this->v=v;
    adj=new vector<pair<int,int>>[v];
}

void addEdge(int u,int v, int wt){
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}

//prims algo to find MST:
int spanningTree(){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>vis(v,0);
// {wt,node}
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;

            if(vis[node]==1)continue;
            else{
                vis[node]=1;
                sum+=wt;
                for(auto it:adj[node]){
                    int adjNode=it.first;
                    int edw=it.second;
                    if(!vis[adjNode]){
                        pq.push({edw,adjNode});
                    }
                }
            }
        }
    return sum;
}
};

int main(){
    int v=5;
    Graph g(v);
 // Adding edges to the graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    // Finding and printing the weight of the MST
    cout << "Weight of Minimum Spanning Tree: " << g.spanningTree() << endl;
}