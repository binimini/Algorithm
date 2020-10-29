#include <bits/stdc++.h>
using namespace std;
int N, M, K, visited[1000][1000][11] = { 0 }, d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool mapp[1000][1000];
queue<tuple<int, int, int>> q;
void bfs() {
    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            int nz = z;
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
            if (nx == N - 1 && ny == M - 1) {
                visited[nx][ny][nz] = visited[x][y][z] + 1;
                return;
            }
            if (nz == K && mapp[nx][ny]) continue;
            else if (mapp[nx][ny]) {
                if (visited[nx][ny][nz + 1]) continue;
                q.push({ nx, ny, nz+1 });
                visited[nx][ny][nz + 1] = visited[x][y][z] + 1;
            }
            else {
                if (visited[nx][ny][nz]) continue;
                q.push({ nx, ny, nz });
                visited[nx][ny][nz] = visited[x][y][z] + 1;
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    char temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            if (temp == '1')
                mapp[i][j] = 1;
            else
                mapp[i][j] = 0;
        }
    }
    q.push({ 0,0,0 });
    visited[0][0][0] = 1;
    bfs();
    int result = 2000000;
    for (int i = 0; i <= K; i++) {
        if (visited[N - 1][M - 1][i] != 0)
            result = min(visited[N - 1][M - 1][i], result);
    }
    if (result == 2000000)
        cout << -1;
    else
        cout << result;
    return 0;

}