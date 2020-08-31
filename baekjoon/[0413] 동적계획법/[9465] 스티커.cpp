#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001][2], dp[100001][3], T, N, c0 = 1, c1 = 0;
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i][0];
        }
        for (int i = 1; i <= N; i++) {
            cin >> arr[i][1];
        }
        dp[1][1] = arr[1][0];
        dp[1][2] = arr[1][1];
        for (int i = 2; i <= N; i++) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i][0];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][1];
        }
        cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << "\n";
    }
    return 0;
}