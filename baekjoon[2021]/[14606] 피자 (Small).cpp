#include <bits/stdc++.h>
using namespace std;
int N, dp[11];
int main() {
    cin >> N;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        dp[i] = 0;
        for (int j = 1; j <= N / 2; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i - j] + j * (i - j));
        }
    }
    cout << dp[N];
    return 0;
}