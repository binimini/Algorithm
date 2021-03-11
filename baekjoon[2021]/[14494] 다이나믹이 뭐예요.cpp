#include <bits/stdc++.h>
using namespace std;
int N, M;
long long int dp[1001][1001] = { 0 }, MOD = 1000000007;
int main() {
    cin >> N >> M;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = (dp[i - 1][j]%MOD + dp[i][j - 1]%MOD + dp[i - 1][j - 1]%MOD)%MOD;
        }
    }
    cout << dp[N][M]%MOD;
    return 0;
}