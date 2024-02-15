#include<bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    vector<int>* adj;

public:
    Graph(int v) {
        this->v = v;
        adj = new vector<int>[v];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Topological sorting using DFS
    void topologicalSortUtil(int node, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, st);
            }
        }
        st.push(node);
    }

    void topologicalSort() {
        vector<bool> visited(v, false);
        stack<int> st;

        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, st);
            }
        }

        cout << "Topological Order: ";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};

int main() {
    int v = 6;
    Graph g(v);

    // Adding edges to the graph
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // Finding and printing the topological order
    g.topologicalSort();

    return 0;
}
