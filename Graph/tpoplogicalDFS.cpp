#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>adj[], vector<int>&vis, stack<int>&st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it])dfs(it,adj,vis,st);
    }st.push(node);
}

vector<int>topo(int v,vector<int>adj[]){
    stack<int>st;
    vector<int>vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i])dfs(i,adj,vis,st);
    }

    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int>ans=topo(n,adj);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}