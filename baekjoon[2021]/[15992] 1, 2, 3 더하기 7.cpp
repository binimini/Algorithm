#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T,N,M, MOD = 1000000009;
int dp[1001][1001] = { 0 };
int main() {
    FASTIO;
    cin >> T;
    dp[1][1] = 1;
    dp[2][1] = 1, dp[2][2] = 1;
    dp[3][1] = 1, dp[3][2] = 2, dp[3][3] = 1;
    for (int i = 4; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1])%MOD;
            dp[i][j] = (dp[i][j] + dp[i - 2][j - 1])%MOD;
            dp[i][j] =  (dp[i][j] + dp[i - 3][j - 1])%MOD;
        }
    }
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        cout << dp[N][M]%MOD << "\n";
    }
    return 0;
}