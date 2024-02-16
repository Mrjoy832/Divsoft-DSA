#include<bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    vector<pair<int, int>>* adj;//nide,wt
public:
    Graph(int v) {
        this->v = v;
        adj = new vector<pair<int, int>>[v];
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // prims algo to find MST:
    void spanningTree() {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        //priority queue where each element is = pair<int, pair<int, int> , container vector = vector<pair<int, pair<int, int>>>
        // greater<pair<int, pair<int, int>>> for min heap.
        vector<int> vis(v, 0);
        // {wt, {node, parent}}
        pq.push({0, {0, -1}});
        vector<pair<int, int>> edges; // to store MST edges
        int sum = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second.first;
            int parent = it.second.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue;
            else {
                vis[node] = 1;
                sum += wt;
                if (parent != -1) {//if parent is not the sourve node
                    edges.push_back({parent, node});
                    cout << "Edge: " << parent << " - " << node << " Weight: " << wt << "\n";
                }
                for (auto it : adj[node]) {
                    int adjNode = it.first;
                    int edw = it.second;
                    if (!vis[adjNode]) {
                        pq.push({edw, {adjNode, node}});
                    }
                }
            }
        }
        cout << "Weight of Minimum Spanning Tree: " << sum << endl;
    }
};

int main() {
    int v = 5;
    Graph g(v);
    // Adding edges to the graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    // Finding and printing the MST and the edges
    g.spanningTree();
    return 0;
}
