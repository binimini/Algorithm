#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N, MOD = 1000000009;
int dp[100001][2] = { 0 };//홀수, 짝수
int main() {
    FASTIO;
    dp[0][0] = 0, dp[0][1] = 0;
    dp[1][0] = 1, dp[1][1] = 0;
    dp[2][0] = 1, dp[2][1] = 1;
    dp[3][0] = 2, dp[3][1] = 2;
    for (int i = 4; i <= 100000; i++) {
        dp[i][0] = (dp[i][0] + dp[i - 1][1])%MOD;
        dp[i][1] = (dp[i][1] + dp[i - 1][0])%MOD;
        dp[i][0] = (dp[i][0] + dp[i - 2][1]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i - 2][0]) % MOD;
        dp[i][0] = (dp[i][0] + dp[i - 3][1]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i - 3][0]) % MOD;
    }
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        cout << dp[N][0] << " " << dp[N][1] << "\n";
    }
    return 0;
}