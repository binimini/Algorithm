#include <bits/stdc++.h>
using namespace std;
int N, dp[501][501], INF = 2147483647;
pair<int, int> m[501];
int solve(int i, int j) {//i부터 j까지 연산 시 최소 연산 횟수
    if (i == j)//더 나눌 수 없다 i==j이면 연산횟수 0번
        return 0;
    int& r = dp[i][j];
    if (r != -1)
        return r;
    r = INF;
    for (int k = i; k < j; k++) {//[i-k], [k+1-j] 까지 두 그룹으로 나눠 접근한다. 
        //이때의 연산횟수 m[i]ROW(...)*m[k]COL(==m[k+1]ROW)(...)*m[j]COL (연산하고나면 l(*m m*)n => l*n이므로)
        r = min(r, solve(i, k) + solve(k + 1, j) + m[i].first * m[k].second * m[j].second);
    }
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
        cin >> m[i].first >> m[i].second;
    }
    cout << solve(0, N - 1);
    return 0;
}