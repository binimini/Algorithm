#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, S, D, cnt = 0, dist = 0;
vector<int> e[100001];
bool visited[100001] = { 0 };
bool promising(int node, int d, int p) {
    bool flag = false;

    if (!visited[node]) {
        visited[node] = 1;
        cnt++;
        flag = true;
    }
    if (d == 0)
        return flag;
    for (int i = 0; i < e[node].size(); i++) {
        if (p == e[node][i]) continue; //부모 예외 처리 안할 시 TLE
        if (promising(e[node][i], d-1, node))
            flag = true;
    }
    
    return flag;
}

void dfs(int node) {
    promising(node, D, 0);
    if (cnt == N)
        return;

    for (int i = 0; i < e[node].size(); i++) {
        int next = e[node][i];
        if (promising(next, D, node)) {
            dist++;
            dfs(next);
        }
    }

    dist++;
}
int main() {
    FASTIO;
    cin >> N >> S >> D;
    int x, y;
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    visited[S] = 1;
    cnt++;
    dfs(S);
    cout << dist;
    return 0;
}