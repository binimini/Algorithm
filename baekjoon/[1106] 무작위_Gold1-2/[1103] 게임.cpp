#include <bits/stdc++.h>
using namespace std;
int N, M;
int board[50][50], d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int dp[50][50];
bool visited[50][50] = { 0 }, flag = 0;
int solution(int n, int m) {
    if (n<0 || n>N - 1 || m<0 || m>M - 1)
        return 0;
    if (board[n][m] == 0)
        return 0;
    if (visited[n][m]) {
        flag = 1;
        return 0;
    }
    if (dp[n][m] != -1)
        return dp[n][m];
    int& r = dp[n][m];
    visited[n][m] = 1;
    r = 0;
    for (int i = 0; i < 4; i++) {
        int nx = n + d[i][0] * board[n][m];
        int ny = m + d[i][1] * board[n][m];
        r = max(r, solution(nx, ny) + 1);
    }
    visited[n][m] = 0;
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    char temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            if (temp == 'H')
                board[i][j] = 0;
            else
                board[i][j] = temp - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    int result = solution(0, 0);
    if (flag)
        cout << -1;
    else
        cout << result;
    return 0;
}