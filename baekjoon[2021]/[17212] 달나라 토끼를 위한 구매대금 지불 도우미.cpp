#include <bits/stdc++.h>
using namespace std;
int N, dp[100001], INF = 100001;
int main() {
    cin >> N;
    for (int i = 0; i <= N; i++)
        dp[i] = INF;
    dp[0] = 0;
    for (int i = 0; i <= N; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        dp[i + 2] = min(dp[i + 2], dp[i] + 1);
        dp[i + 5] = min(dp[i + 5], dp[i] + 1);
        dp[i + 7] = min(dp[i + 7], dp[i] + 1);
    }
    cout << dp[N];
    return 0;
}