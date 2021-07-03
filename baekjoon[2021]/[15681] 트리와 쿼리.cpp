#include <iostream>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, R, Q, solution[100001];
vector<int> edge[100001];
bool visited[100001] = { 0 };

void dfs(int node) {
    visited[node] = 1;
    int cnt = 0;
    for (int i = 0; i < edge[node].size(); i++) {
        int next = edge[node][i];
        if (visited[next]) continue;
        dfs(next);
        cnt += solution[next];
    }
    solution[node] = cnt + 1;
}
int main() {
    FASTIO;
    cin >> N >> R >> Q;
    int u, v;
    for (int n = 0; n < N - 1; n++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(R);
    int root;
    for (int q = 0; q < Q; q++) {
        cin >> root;
        cout << solution[root] << "\n";
    }
    return 0;
}