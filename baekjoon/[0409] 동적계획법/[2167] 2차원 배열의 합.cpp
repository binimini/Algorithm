#include <iostream>
using namespace std;
int arr[301][301], dp[301][301], N, M, T;
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    for (int t = 0; t < T; t++) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1] << "\n";

    }
    return 0;
}