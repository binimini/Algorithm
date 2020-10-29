#include <bits/stdc++.h>
using namespace std;
int N,dp[1000001][2];
bool visited[1000001] = { 0 };
vector<int> edge[1000001];
int find_dp(int node, bool early) {
    if (dp[node][early] != -1)
        return dp[node][early];
    visited[node] = 1;
    int& r = dp[node][early];
    r = 0;
    bool flag = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        if (!visited[edge[node][i]]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        visited[node] = 0;
        if (early)
            return r = 1;
        else
            return r = 0;
    }
    if (!early) {
        for (int i = 0; i < edge[node].size(); i++) {
            if (visited[edge[node][i]]) continue;
            r += find_dp(edge[node][i], 1);
        }
    }
    else {
        for (int i = 0; i < edge[node].size(); i++) {
            if (visited[edge[node][i]]) continue;
            r += min(find_dp(edge[node][i], 0), find_dp(edge[node][i], 1));
        }
        r += 1;
    }
    visited[node] = 0;
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    int u, v;
    for (int i = 1; i < N; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    cout << min(find_dp(1,0), find_dp(1,1));
    return 0;
}