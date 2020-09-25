#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, CH = 1;
bool map[100][100] = { 0 };
bool zero[100][100] = { 0 };
int visited[100][100] = { 0 }, d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
queue<pair<int,int>> q;
queue < pair<int, int>> z;
void Zero(int n) {
    while (!z.empty()) {
        int x = z.front().first;
        int y = z.front().second;
        z.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
            if (map[nx][ny]) continue;
            if (zero[nx][ny]) continue;
            zero[nx][ny] = 1;
            visited[nx][ny] = n;
            q.push(make_pair(nx, ny));
            z.push(make_pair(nx, ny));
        }
    }
}
void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
            if (visited[nx][ny]) continue;

            if (map[nx][ny]) {
                visited[nx][ny] = visited[x][y]+1;
                CH = max(CH, visited[nx][ny]);
                z.push(make_pair(nx, ny));
                Zero(visited[nx][ny]);
            }
            q.push(make_pair(nx, ny));

        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
                if (!map[i][j]) {
                    visited[i][j] = 1;
                    zero[i][j] = 1;
                    z.push(make_pair(i, j));
                }
                else {
                    visited[i][j] = 2;

                }
                q.push(make_pair(i, j));
            }
        }
    }
    Zero(1);
    BFS();
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == CH&&map[i][j]==1)
                cnt++;
        }
    }
    cout << CH-1 << "\n" << cnt << "\n";
    return 0;
}