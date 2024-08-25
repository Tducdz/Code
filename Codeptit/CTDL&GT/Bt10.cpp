#include<bits/stdc++.h>

using namespace std;

bool vs[1001];
vector<int> adj[1001];
int e[1001];
int n, m;

void BFS(int u) {
    queue<int> q;
    q.push(u);
    vs[u] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto x : adj[v]) {
            if (!vs[x]) {
                e[x] = v;
                vs[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(vs, false, sizeof(vs));
        memset(adj, 0, sizeof(adj));
        memset(e, 0, sizeof(e));
        cin >> n >> m;
        int u, v;
        cin >> u >> v;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        BFS(u);
        if (!vs[v]) cout << "-1" << endl;
        else {
            vector<int> k;
            while (v != u) {
                k.push_back(v);
                v = e[v];
            }
            k.push_back(u);
            reverse(k.begin(), k.end());
            for (auto x : k) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}