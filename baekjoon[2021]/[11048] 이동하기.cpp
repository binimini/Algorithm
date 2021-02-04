#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N, M, mapp[1000][1000], dp[1000][1000], INF = -100000000;
int solve(int x, int y) {
    if (x == 0 && y == 0)//base case 1
        return mapp[0][0];
    if (x < 0 || y < 0)//base case 2
        return INF;//max is best, INF = -max
    if (dp[x][y] != -1)//memorization
        return dp[x][y];
    int &r =dp[x][y];
    r = 0;
    r = max(solve(x - 1, y - 1), max(solve(x - 1, y), solve(x, y - 1)))+mapp[x][y];
    return r;
}
int main() {
    FASTIO;
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mapp[i][j];
        }
    }
    cout <<solve(N-1, M-1);
    return 0;
}