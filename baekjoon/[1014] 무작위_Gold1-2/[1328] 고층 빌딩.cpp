#include <bits/stdc++.h>
using namespace std;
int N, L, R, MOD = 1000000007;
int dp[101][101][101];
long long int find_dp(int n, int l, int r) {
    if ((l == 1 && r == n) || (r == 1 && l == n))
        return 1;
    if (n == 0 || l == 0 || r == 0)
        return 0;
    if (dp[n][l][r] != -1) 
        return dp[n][l][r];
    
    int& result = dp[n][l][r];
    long long int n_ = n;
    n_ -= 2;
    return result = (find_dp(n - 1, l - 1, r) + find_dp(n - 1, l, r - 1) + n_ * find_dp(n - 1, l, r)) % MOD;
}
int main() {
    cin >> N>>L>>R;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= N; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << find_dp(N, L, R);
    return 0;
}