#include <iostream>
#include <algorithm>
using namespace std;
int N, dp[1001][3], arr[1001][3], INF = 1000001;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = INF;
        dp[i][1] = INF;
        dp[i][2] = INF;
    }
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for (int n = 0; n < 3; n++) {//N의 RGB값 미리 지정
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i <= N-1; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
            if (i == 1||i==N-1)
                dp[i][n] = INF;//인접 집 색 불가능한 경우 INF처리
        }
        dp[N][n] = min(dp[N - 1][2], min(dp[N - 1][0], dp[N - 1][1]))+ arr[N][n];//최종 dp[N][n]
    }
    cout << min(dp[N][0], min(dp[N][1], dp[N][2])) << '\n';
    return 0;
}