#include <bits/stdc++.h>
using namespace std;
long long int dp[101][101] = { 0 };
int N, M, K;
long long int MAX = 1000000000;
string R = "";
void find_dp(int n, int m, int k) {
    if (!n) {
        for (int i = 0; i < m; i++) {
            R += 'z';
        }
        return;
    }
    else if (!m) {
        for (int i = 0; i < n; i++) {
            R += 'a';
        }
        return;
    }
    if (dp[n-1][m] >= k) {
        R += 'a';
        find_dp(n-1, m , k);
    }
    else {
        R += 'z';
        find_dp(n, m - 1, k - dp[n - 1][m]);
    }
}
int main() {
    cin >> N >> M >> K;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if (dp[i][j] > MAX)
                dp[i][j] = MAX+1;
        }
    }
    find_dp(N, M, K);
    if (dp[N][M] < K)
        cout << -1;
    else
        cout << R;
    return 0;
}