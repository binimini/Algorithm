#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N, INF = 200001;
int dp[200001][2];
bool hard[200001] = { 0 };
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> hard[i];
        }
        for (int i = 1; i <= N; i++) {
            dp[i][0] = INF;
            dp[i][1] = INF;
        }
        if (hard[1])
            dp[1][0] = 1;
        else
            dp[1][0] = 0;
        if (hard[2])
            dp[2][0] = dp[1][0] + 1;
        else dp[2][0] = dp[1][0];
        dp[2][1] = dp[1][0];
        dp[3][1] = dp[1][0];
        for (int i = 3; i <= N; i++) {
            if (hard[i] == 1) {
                if (hard[i - 1] == 1) {
                    dp[i][0] = min(dp[i - 2][1] + 2, dp[i][0]);
                }
                else dp[i][0] = min(dp[i - 2][1] + 1, dp[i][0]);
                dp[i][0] = min(dp[i - 1][1] + 1, dp[i][0]);
            }
            else {
                if (hard[i - 1] == 1) {
                    dp[i][0] = min(dp[i - 2][1] + 1, dp[i][0]);
                }
                else dp[i][0] = min(dp[i - 2][1], dp[i][0]);
                dp[i][0] = min(dp[i - 1][1], dp[i][0]);
            }
            dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
        }
        cout << min(dp[N][1], dp[N][0]) << "\n";
    }
    return 0;
}