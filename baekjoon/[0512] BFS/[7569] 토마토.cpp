#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int M, N, H, arr[100][100][100] = { 0 }, visited[100][100][100] = { 0 }, cnt = 0, day = 0, d[6][3] = { {0,0,1},{0,0,-1},{-1,0,0},{0,1,0},{1,0,0},{0,-1,0} };
queue<vector<int>> q;
void BFS() {
    while (!q.empty()) {
        int x = q.front()[1], y = q.front()[2], z = q.front()[0];
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = x + d[i][1], ny = y + d[i][2], nz = z + d[i][0];
            if (nx<0 || ny<0 || nz<0 || nx>N - 1 || ny>M - 1 || nz>H - 1) continue;
            if (visited[nz][nx][ny]) continue;
            if (!arr[nz][nx][ny]) {
                arr[nz][nx][ny] = 1;
                cnt--;
                vector<int> temp = { nz,nx,ny };
                q.push(temp);
                visited[nz][nx][ny] = visited[z][x][y] + 1;
                day = visited[nz][nx][ny];
            }
        }
    }
}
int main() {
    cin.tie(NULL);
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) {
                    vector<int> temp = { i,j,k };
                    q.push(temp);
                    visited[i][j][k] = 1;
                }
                else if (!arr[i][j][k])
                    cnt++;
            }
        }
    }
    if (!cnt) {
        cout << 0 << "\n";
        return 0;
    }
    BFS();
    if (cnt)
        cout << -1 << "\n";
    else if (!day)
        cout << 0 << "\n";
    else
        cout << day - 1 << "\n";
    return 0;
}