#include <bits/stdc++.h>
using namespace std;
int N, M, R = 0;
vector<int> result;
int profit[21][301] = { 0 }, dp[21][301] = { 0 }, p[21][301];
void pre(int m, int n) {
    if (m == 0)
        return;
    pre(m - 1, n - p[m][n]);
    cout << p[m][n] << " ";
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        for (int j = 1; j <= M; j++) {
            cin >> profit[j][i];
        }
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= j; k++) {//k투자 금액
                if (dp[i][j] < dp[i - 1][j - k] + profit[i][k]) {
                    dp[i][j] = dp[i - 1][j - k] + profit[i][k];
                    p[i][j] = k;
               }
            }
        }
    }
    cout << dp[M][N]<<"\n";
    pre(M, N);
    return 0;
}