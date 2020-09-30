#include <iostream>
#include <algorithm>
using namespace std;
int N, INF = -100000001;
int arr[100001];
int dp[100001][3][2];
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i][0][0] = dp[i - 1][0][0];
        dp[i][0][1] = dp[i - 1][0][0];
        
        dp[i][1][0] = max(dp[i - 1][1][0]+arr[i], dp[i-1][0][0]+arr[i]);
        
        dp[i][1][1] = max(dp[i - 1][0][1]+arr[i], dp[i][1][1]);
        dp[i][1][1] = max(dp[i - 1][1][0], dp[i][1][1]);
        dp[i][1][1] = max(dp[i - 1][1][1]+arr[i], dp[i][1][1]);
        
        dp[i][2][0] = max(dp[i - 1][2][0], dp[i-1][1][0]);
        
        dp[i][2][1] = max(dp[i - 1][2][1], dp[i][2][1]);
        dp[i][2][1] = max(dp[i - 1][2][0], dp[i][2][1]);
        dp[i][2][1] = max(dp[i - 1][1][1], dp[i][2][1]);
        dp[i][2][1] = max(dp[i - 1][1][0], dp[i][2][1]);
    }
    int result = INF;
    result = max(result, dp[N][1][0]);
    result = max(result, dp[N][1][1]);
    result = max(result, dp[N][2][0]);
    result = max(result, dp[N][2][1]);
    cout << result << "\n";
    return 0;
}