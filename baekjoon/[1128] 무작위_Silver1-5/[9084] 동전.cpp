#include <bits/stdc++.h>
using namespace std;
int T, N, M;
int arr[20];
long long int dp[20][10001];
long long int solution(int n,int m) {
    if (m == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    long long int& r = dp[n][m];
    r = 0;
    for (int i = 0; i <= m / arr[n]; i++) {
        r += solution(n - 1, m - i * arr[n]);
    }
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= M; j++) {
                dp[i][j] = -1;
            }
        }
        cout << solution(N-1,M)<<'\n';
    }
    return 0;
}