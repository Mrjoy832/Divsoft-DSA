#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    int v;
    vector<int>* adj;

    Graph(int v) {
        this->v = v;
        adj = new vector<int>[v];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBipartite() {
        vector<int> color(v, -1); // -1 represents uncolored, 0 and 1 represent the two colors
        queue<int> q;

        for (int i = 0; i < v; ++i) {
            if (color[i] == -1) {
                color[i] = 0;//1st node coloured with 0
                q.push(i);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (auto it : adj[u]) {
                        if (color[it] == -1) {
                            color[it] = 1 - color[u]; // Assign the opposite color
                            q.push(it);
                        } else if (color[it] == color[u]) {
                            return false; // If adjacent nodes have the same color, the graph is not bipartite
                        }
                    }
                }
            }
        }

        return true; // If all components are bipartite
    }
};

int main() {
    int v = 5;
    Graph g(v);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // g.addEdge(4, 5);

    if (g.isBipartite()) {
        cout << "The graph is bipartite.\n";
    } else {
        cout << "The graph is not bipartite.\n";
    }

    return 0;
}
