#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N, dp[10001], tt[10001];
int twothree(int n) {
    if (tt[n] != -1)
        return tt[n];
    else
        return tt[n] = (n % 3 == 0) ? twothree(n-2) + 1 : twothree(n-2);
}
int solve(int N) {
    if (dp[N] != -1)
        return dp[N];
    else
        return dp[N] = solve(N-1)+twothree(N);
}
int main() {
    FASTIO;
    memset(dp, -1, sizeof(dp));
    memset(tt, -1, sizeof(tt));
    cin >> T;
    dp[1] = 1;
    tt[1] = 0; tt[2] = 1, tt[3] = 1;
    for (int i = 2; i <= 10000; i++) {
        solve(i);
    }
    for (int t = 0; t < T; t++) {
        cin >> N;  
        cout << dp[N] << "\n";
    }
    return 0;
}