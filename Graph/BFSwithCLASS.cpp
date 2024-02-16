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

// BFS for single componenet
    void BFS(int start){
        bool visited[v+1]={false};
        queue<int>q;
        visited[start]=true;
        q.push(start);

        while(!q.empty()){
            int top=q.front();
            q.pop();
            cout<<top<<" ";
            for(auto it:adj[top]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
        
    }

    // DFS for single Component
    
};

int main(){
    int v=5;
    Graph g(v+1);

    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(4,2);
    g.addEdge(3,5);
    g.addEdge(5,4);

    g.BFS(1);
}