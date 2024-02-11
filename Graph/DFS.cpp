#include<bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int>adj[], int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(int node, vector<int>vis, vector<int>adj[], vector<int>ans){
ans.push_back(node);
vis[node]=1;

for(auto it:adj[node]){
    if(!vis[it]){
        DFS(it,vis,adj,ans);
    }
}
}

vector<int>DFSgraph(int v, vector<int>adj[]){
    vector<int>ans;
    vector<int>vis(v+1,0);

    for(int i=1;i<=v;i++){
    if(!vis[i])DFS(i,vis,adj,ans);

    }
    return ans;


}

int main(){
    int v=6;
vector<int>adj[v+1];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);

    vector<int>ans=DFSgraph(v,adj);
    for(auto it:ans)cout<<it<<" ";
}