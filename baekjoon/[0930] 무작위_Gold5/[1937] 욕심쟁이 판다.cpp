#include <iostream>
#include <algorithm>
using namespace std;
int N,K = 0;
int memo[500][500];
int map[500][500], d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool visited[500][500] = { 0 };
int dfs(int x, int y) {
    if (memo[x][y] != -1)
        return memo[x][y];
    int m = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;
        if (visited[nx][ny]) continue;
        if (map[nx][ny] <= map[x][y]) continue;
        visited[nx][ny] = 1;
        m = max(m,dfs(nx, ny)+1);
        visited[nx][ny] = 0;
    }
    return memo[x][y] = m;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            memo[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            K = max(K,dfs(i, j));
        }
    }
    cout << K;
    return 0;
}