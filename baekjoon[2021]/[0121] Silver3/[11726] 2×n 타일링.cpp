#include <bits/stdc++.h>
using namespace std;
#define mod 10007
int N, dp[1001];
int solve(int n) {
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (solve(n - 1) + solve(n - 2))%mod;
}
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N;
    cout <<solve(N)%mod;
    return 0;
}