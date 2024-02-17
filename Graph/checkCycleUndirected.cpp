// Using BFS:
#include<bits/stdc++.h>
using namespace std;

bool checkforCycle(int s, int v, vector<int> adj[], vector<int>& visited) {
    queue<pair<int,int>> q;
    visited[s] = true;
    q.push({s, -1});// {node, parent}

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push({it, node});
            } else if (parent != it) {// if kono node's adj node visited jeta parent o na 
            // tar mne already visited by someone else so cyle
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int v, vector<int> adj[]) {
    vector<int> visited(v + 1, 0);
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            if (checkforCycle(i, v, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int v, e;
        cin >> v >> e;
        vector<int> adj[v + 1];  // Corrected the size to v + 1
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool ans = isCycle(v, adj);

        if (ans) {
            cout << "1";
        } else {
            cout << "0";
        }
    }

    return 0;
}
