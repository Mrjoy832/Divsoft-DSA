
// TC of BFS-- N+E  = N= no of vertices stored in array, E=edges

#include<bits/stdc++.h>
using namespace std;


// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int>adj[], int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}




void BFS(vector<int>adj[],int v){
    int  visited[v+1]={0}; // Mark all vertices not-visited initially
    queue<int>q;

    //marking 1st node visited and pushed to queue
    visited[1]=1;
    q.push(1);

    while(!q.empty()){
         // Pop element at front and print
        int node=q.front();
        q.pop();
        cout<<node<<" ";

  // Traverse the nodes adjacent to the currently
        // poped element and push those elements to the
        // queue which are not already visited
        for(auto it:adj[node]){
            if(!visited[it]){
                  // Mark it visited
                visited[it]=1;
                //push to queue
                q.push(it);
            }
        }
    }
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

    BFS(adj,v);
}