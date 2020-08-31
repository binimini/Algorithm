#include <iostream>
#include <algorithm>
using namespace std;
int cost[1001], dp[1001], N;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }
    for (int i = 1; i <= N; i++) {
        int M = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] = cost[j] + dp[i - j];
            M = max(M, dp[i]);
        }
        dp[i] = M;
    }
    cout << dp[N] << "\n";
    return 0;
}