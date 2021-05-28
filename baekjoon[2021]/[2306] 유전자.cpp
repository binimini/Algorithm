#include <bits/stdc++.h>
using namespace std;
int N, dp[501][501];
string S;
int solve(int i , int j) {
    if (i + 1 > j)
        return 0;
    if (i + 1 == j) {
        if (S[i] == 'a' && S[j] == 't' || S[i] == 'g' && S[j] == 'c')
            return 2;
        else
            return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int& r = dp[i][j];
    r = 0;
    int temp1 = 0, temp2 = 0;
    if (i >= N || j >= N || i < 0 || j < 0)
        return 0;
    if (S[i] == 'a' && S[j] == 't' || S[i] == 'g' && S[j] == 'c') {
        r = max(r, 2 + solve(i + 1, j - 1));
    }
    for (int x = i; x < j; x++) {
        r = max(r, solve(i, x) + solve(x + 1, j));
    }
    return r;
}
int main() {
    cin >> S;
    N = S.size();
    memset(dp, -1, sizeof(dp));
    cout << solve(0,N-1);
    return 0;
}