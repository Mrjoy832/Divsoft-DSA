
#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int v;
    int* visited;
    vector<int>* adj;

public:
    Graph(int v) {
        this->v = v;
        adj = new vector<int>[v + 1];
        visited = new int[v + 1]{0};
    }

    ~Graph() {
        delete[] adj;
        delete[] visited;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

// without any STL 
    bool checkForCycle(int s, int parent) {
        visited[s] = 1;

        for (int i : adj[s]) {
            if (!visited[i]) {
                if (checkForCycle(i, s))
                    return true;
            } else if (i != parent) {
                return true;
            }
        }

        return false;
    }
    bool isCycle() {
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                if (checkForCycle(i, -1))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int v = 6;
    Graph g(v);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    if (g.isCycle())
        cout << "Graph contains a cycle.\n";
    else
        cout << "Graph doesn't contain a cycle.\n";

    return 0;
}
