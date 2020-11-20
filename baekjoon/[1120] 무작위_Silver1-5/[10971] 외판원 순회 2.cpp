#include <bits/stdc++.h>
using namespace std;
int N, w[10][10], INF = 987654321;
int dp[10][1 << 10];
int dfs(int n, int st) {
    if (st == (1 << N) - 1) {
        if (w[n][0] == 0)//못 돌아감
            return INF;
        else
            return w[n][0];//돌아가는 비용
    }
    if (dp[n][st] != 0)
        return dp[n][st];
    int& r = dp[n][st];
    r = INF;
    for (int i = 0; i < N; i++) {
        if (w[n][i] == 0) continue;// 못 감
        if (st & (1 << i)) continue;
        r = min(r, dfs(i, st | 1 << i) + w[n][i]);
    }
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> w[i][j];
        }
    }
    cout<< dfs(0, 1);
    return 0;
}