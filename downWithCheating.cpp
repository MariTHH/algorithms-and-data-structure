#include <iostream>
#include <vector>

using namespace std;

bool bipartiting(int v, int color, vector<vector<int>>& adj, vector<int>& colors) {
    colors[v] = color;

    for (int u : adj[v]) {
        if (colors[u] == color) {
            return false;
        }

        if (colors[u] == 0 && !bipartiting(u, -color, adj, colors)) {
            return false;
        }
    }

    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> colors(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        if (colors[i] == 0 && !bipartiting(i, 1, adj, colors)) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
