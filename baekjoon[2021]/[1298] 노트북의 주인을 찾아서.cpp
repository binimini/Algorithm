#include <bits/stdc++.h>
using namespace std;
int N, M;
bool visited[101] = { 0 };
int B[101] = { 0 };//연결할 i번째 노드가 연결 되어있는 A그룹 정보
vector<int> edge[101];
bool dfs(int node) {
    if (visited[node]) return false;
    visited[node] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        if (B[edge[node][i]] == 0 || dfs(B[edge[node][i]])) {
            B[edge[node][i]] = node;
            return true;
        }
    }
    return false;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            visited[j] = 0;
        if (dfs(i))
            res++;
    }
    cout << res;
    return 0;
}