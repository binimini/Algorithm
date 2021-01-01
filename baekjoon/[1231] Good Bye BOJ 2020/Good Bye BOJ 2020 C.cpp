#include <bits/stdc++.h>
using namespace std;
int N, Q;
vector<int> e[200001];
stack<int> s;
int visited[200001] = { 0 };
bool cycle[200001] = { 0 };
void bfs(int node, int cnt) {
    queue<int> q;
    q.push(node);
    visited[node] = cnt;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size(); i++) {
            if (cycle[e[x][i]]) continue;
            if (visited[e[x][i]] == cnt) continue;
            visited[e[x][i]] = cnt;
            q.push(e[x][i]);
        }
    }
}
void dfs(int parent, int node) {
    if (visited[node]) {
        while (!s.empty()&&s.top() != node) {
            cycle[s.top()] = 1;
            s.pop();
        }
        cycle[node] = 1;
        return;
    }

    visited[node] = 1;
    s.push(node);
    for (int i = 0; i < e[node].size(); i++) {
        if (e[node][i] == parent) continue;
        dfs(node, e[node][i]);
        while (!s.empty() && s.top() != node) {
            s.pop();
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(-1, 1);
    int cnt = 2;
    for (int i = 1; i <= N; i++) {
        if (cycle[i]) {
            bfs(i, cnt);
            cnt++;
        }
    }
    int u, v;
    for (int i = 0; i < Q; i++) {
        cin >> u >> v;
        if (cycle[u]  && cycle[v] )
            cout << 2 << "\n";
        else {
            if (visited[u] == visited[v])
                cout << 1 << "\n";
            else
                cout << 2 << "\n";
        }
    }
    return 0;
}