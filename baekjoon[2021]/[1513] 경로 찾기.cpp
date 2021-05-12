#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, C, MOD = 1000007;
int dp[51][51][51][51];
int mapp[51][51] = { 0 };
int solve(int i, int j, int k, int l) {
    if (k < 0) return 0;
    if (i > N || j > M) return 0;
    if (i == N && j == M) {
        if (mapp[i][j] > l&& k == 1)
            return 1;
        if (!mapp[i][j]&&k == 0)
            return 1;
        else
            return 0;
    }
    if (dp[i][j][k][l] != -1)
        return dp[i][j][k][l]%MOD;

    dp[i][j][k][l] = 0;
    if (mapp[i][j] && mapp[i][j] > l)
        dp[i][j][k][l] = (solve(i + 1, j, k - 1, mapp[i][j]) + solve(i, j + 1, k - 1, mapp[i][j])) % MOD;
    else if (mapp[i][j] && mapp[i][j] <= l)
        dp[i][j][k][l] = 0;
    else if (!mapp[i][j])
        dp[i][j][k][l] = (solve(i + 1, j, k, l) + solve(i, j + 1, k, l))%MOD;
    return dp[i][j][k][l]%MOD;
}
int main() {
    FASTIO;
    cin >> N >> M >> C;
    int x, y;
    for (int i = 1; i <= C; i++) {
        cin >> x >> y;
        mapp[x][y] = i;
    }
    memset(dp, -1, sizeof(dp));
    for (int k = 0; k <= C; k++) {
        cout << solve(1, 1, k, 0)<<" ";
    }
    cout << '\n';
    return 0;
}