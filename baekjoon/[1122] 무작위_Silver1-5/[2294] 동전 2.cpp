#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int N,K,dp[100001], arr[101], INF = 987654321;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= 100000; i++)
        dp[i] = INF;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = arr[i]; j <= K; j++) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }
    if (dp[K] == INF)
        cout << -1;
    else
        cout << dp[K];
    return 0;
}