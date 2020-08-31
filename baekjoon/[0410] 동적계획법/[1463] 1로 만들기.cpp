#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001][3], N;
int return_min(int n) {
    int m = 999999999;
    if (dp[n][0] == 0 && dp[n][1] == 0 && dp[n][2] == 0)
        return 0;
    if (min(dp[n][0], dp[n][1]) != 0)
        m = min(dp[n][0], dp[n][1]);
    else if (max(dp[n][0], dp[n][1]) != 0)
        m = max(dp[n][0], dp[n][1]);
    if (min(dp[n][1], dp[n][2]) != 0)
        m = min(m, min(dp[n][1], dp[n][2]));
    else if (max(dp[n][1], dp[n][2]) != 0)
        m = min(m, max(dp[n][1], dp[n][2]));
    if (min(dp[n][0], dp[n][2]) != 0)
        m = min(m, min(dp[n][0], dp[n][2]));
    else if (max(dp[n][0], dp[n][2]) != 0)
        m = min(m, max(dp[n][0], dp[n][2]));
    return m;
}
int main() {
    cin >> N;
    dp[2][1] = 1, dp[2][2] = 1;
    for (int i = 3; i <= N; i++) {
        if (i % 3 == 0)
            dp[i][0] = return_min(i / 3) + 1;
        if (i % 2 == 0)
            dp[i][1] = return_min(i / 2) + 1;
        dp[i][2] = return_min(i - 1) + 1;

    }
    cout << return_min(N) << '\n';
    return 0;
}