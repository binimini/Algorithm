#include <bits/stdc++.h>
using namespace std;
int N, M, dp[101][41], INF = 1000001;
bool arr[101] = { 0 };
int solution(int n, int c) {
    if (n > N)
        return 0;
    if (dp[n][c] != -1)
        return dp[n][c];
    int& r = dp[n][c];
    r = INF;
    if (arr[n])
        return r = min(r,solution(n + 1, c));
    else {
        if (c >= 3)
            r = min(r, solution(n + 1, c - 3));
        else
            r = min(r, solution(n + 1, c) + 10000);
        r = min(r, solution(n + 3, c + 1) + 25000);
        r = min(r, solution(n + 5, c + 2) + 37000);
    }
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    int temp;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        arr[temp] = 1;
    }
    cout <<solution(1, 0);
}