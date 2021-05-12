#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int H, W, K, d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }, INF = 987654321;
bool mapp[200][200];
int visited[200][200][31] = { 0 };
queue<pair<pair<int, int>, int>> q;
void bfs() {
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int k = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (k > 0) {
                int nnx = x + d[i][0] * 2 + d[(i + 1) % 4][0];
                int nny = y + d[i][1] * 2 + d[(i + 1) % 4][1];
                if (nnx>=0&&nnx<H&&nny>=0&&nny<W&&mapp[nnx][nny]==0&&!visited[nnx][nny][k - 1]) {
                    q.push({ {nnx,nny},k - 1 });
                    visited[nnx][nny][k - 1] = visited[x][y][k] + 1;
                }
                nnx = x + d[i][0] * 2 + d[(i + 3) % 4][0];
                nny = y + d[i][1] * 2 + d[(i + 3) % 4][1];
                if (nnx >= 0 && nnx < H && nny >= 0 && nny < W && mapp[nnx][nny] == 0 && !visited[nnx][nny][k - 1]) {
                    q.push({ {nnx,nny},k - 1 });
                    visited[nnx][nny][k - 1] = visited[x][y][k] + 1;
                }
            }
            if (nx<0 || nx>H-1 || ny<0 || ny>W-1) continue;
            if (mapp[nx][ny]) continue;
            if (visited[nx][ny][k]) continue;
            visited[nx][ny][k] = visited[x][y][k] + 1;
            q.push({ {nx,ny},k });
        }
        
    }
}
int main() {
    FASTIO;
    cin >> K >>W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> mapp[i][j];
        }
    }
    q.push({ {0,0},K });
    visited[0][0][K] = 1;
    bfs();
    int res = INF;
    for (int i = 0; i <= K; i++) {
        if (visited[H-1][W-1][i])
            res = min(res, visited[H-1][W-1][i]-1);
    }
    if (res == INF)
        cout << -1;
    else
        cout << res;
    return 0;
}