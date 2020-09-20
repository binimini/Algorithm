#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
int N, M, MAXP;
int p[100001][21] = { 0 };
int level[100001] = { 0 };
bool visited[100001] = { 0 };
vector<int> tree[100001];
void dfs(int node, int depth) {
    for (int i = 0; i < tree[node].size(); i++) {
        if (visited[tree[node][i]]) continue;
        p[tree[node][i]][0] = node;
        level[tree[node][i]] = depth;
        visited[tree[node][i]] = 1;
        dfs(tree[node][i], depth + 1);
    }
}
int lca(int x, int y) {
    int temp;
    if (level[y] > level[x]) {
        temp = x;
        x = y;
        y = temp;
    }
    for (int i = MAXP; i >= 0; i--) {
        if (level[x] - level[y] >= (1 << i)) {
            x = p[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = MAXP; i >= 0; i--) {
        if (p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}
int main() {
    FASTIO;
    cin >> N;
    MAXP = (int)floor(log2(N));
    int a, b;
    FOR(i, 0, N-1) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    visited[1] = 1;
    dfs(1, 1);

    FOR(i, 1, MAXP+1) {
        FOR(j, 1, N+1) {
            p[j][i] = p[p[j][i - 1]][i - 1];
        }
    }
    cin >> M;
    FOR(i, 0, M) {
        cin >> a >> b;
        cout <<lca(a, b)<<"\n";
    }
    return 0;
}