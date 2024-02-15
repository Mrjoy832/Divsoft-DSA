#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<pair<int,int>>*adj;
    public:
    Graph(int v){
        this->v=v;
        adj=new vector<pair<int,int>>[v];//node,wt
    }
   ~Graph() {
        delete[] adj;
    }
    void addEdge(int u,int v,int wt){
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }



   void dijkstra(int source){
    set<pair<int,int>> pq; // dist, node
    vector<int> dist(v, INT_MAX);

    pq.insert({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;

            if (dist[u] + weight < dist[v]) {
                if (dist[v] != INT_MAX) {
                    pq.erase(pq.find({dist[v], v}));
                }
                dist[v] = dist[u] + weight;
                pq.insert({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < v; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << ": Not Reachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }
}

};

int main(){
 int v = 6;
    Graph g(v);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int source = 1;
    g.dijkstra(source);
}