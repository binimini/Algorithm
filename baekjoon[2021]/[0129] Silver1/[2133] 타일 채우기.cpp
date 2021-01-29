#include <bits/stdc++.h>
using namespace std;
int N, dp[31][1<<3];
int solve(int n, int status) {
    if (n == N + 1 && status == 0)
        return 1;
    if (n > N)
        return 0;
    if (dp[n][status] != -1)
        return dp[n][status];
    int& r = dp[n][status];
    r = 0;
    if (status == 0) {
        r += solve(n + 1, 4);
        r += solve(n + 1, 1);
        r += solve(n + 2, 0);
    }
    else if (status==4||status==1) {
        r += solve(n + 1, status ^ 7);
        r += solve(n + 1, 0);
    }
    else if (status == 3 || status == 6) {
        r += solve(n + 1, status ^ 7);
    }
    return r;
}
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N;
    cout << solve(1,0);
    return 0;
}