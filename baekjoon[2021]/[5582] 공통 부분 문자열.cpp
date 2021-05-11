#include <bits/stdc++.h>
using namespace std;
int dp[4000][4000][2];
string A, B;
int solve(int i, int j, int use) {
    if (i >= A.size() || j >= B.size())
        return 0;
    if (dp[i][j][use] != -1)
        return dp[i][j][use];
    dp[i][j][use] = 0;
    if (use) {
        if (A[i] == B[j])
            return dp[i][j][1] = solve(i + 1, j + 1, 1) + 1;
        else
            return 0;
    }
    
    dp[i][j][0] = max(dp[i][j][0], solve(i, j + 1, 0));
    dp[i][j][0] = max(dp[i][j][0], solve(i+1, j, 0));
    if (A[i] == B[j])
        dp[i][j][0] = max(dp[i][j][0], solve(i, j, 1));
    return dp[i][j][0];
    
}
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> A >> B;
    solve(0, 0, 0);
    cout << dp[0][0][0];
    return 0;
}