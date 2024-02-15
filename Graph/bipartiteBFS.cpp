#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    vector<int>*adj;
    public:
    Graph(int v){
        this->v=v;
        adj= new vector<int>[v+1];
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

// check bipartite 
    bool bipartite(int s){
        queue<int>q;
        int color[v+1];
        for(int i=1;i<=v;i++)color[i]=-1;
        q.push(1);
        color[1]=1;//putting 1st node color =1

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                if(color[it]!=-1){color[it]=1-color[node];
                q.push(it);}
                else if(color[it]==color[node])return false;
            }
        }
        return true;
    }
};


int main(){
    int v, e;
        cin >> v >> e;

        Graph g(v+1);
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }

        bool ans = g.bipartite(1);// source node=1

        if (ans) {
            cout << "1";
        } else {
            cout << "0";
        }

}