#include <bits/stdc++.h>
using namespace std;
int dp[2][10001], arr[101];
int N, K;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i%2][j] = 0;
            for (int k = 0; k <= j / arr[i]; k++) {
                if (dp[(i - 1)%2][j - arr[i] * k] != -1)
                    dp[i%2][j] += dp[(i - 1)%2][j - arr[i] * k];
            }
        }
    }
    cout << dp[N%2][K];
    return 0;
}