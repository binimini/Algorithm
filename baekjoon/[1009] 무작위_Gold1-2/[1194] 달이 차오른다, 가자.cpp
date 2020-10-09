#include <iostream>
#include <queue>
using namespace std;
int N, M, R = 987654321;
bool flag;
char map[51][51];
int visited[50][50][64] = { 0 }, d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
queue<pair<pair<int, int>, int>> q;
void bfs() {
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int s = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
            if (map[nx][ny] == '#') continue;//벽
            if (visited[nx][ny][s]) continue;
            visited[nx][ny][s] = visited[x][y][s]+1;
            if (map[nx][ny] == '1') {//출구
                R = visited[nx][ny][s];
                flag = 1;
                return;
            }
            else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {//문
                if ((1 << (map[nx][ny] - 'A')) & s) {
                    q.push({ {nx,ny},s });
                }
                else continue;
            }
            else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z') {//열쇠
                visited[nx][ny][s | (1 << (map[nx][ny] - 'a'))] = visited[nx][ny][s];
                q.push({ { nx,ny }, s | (1 << (map[nx][ny] - 'a')) });
            }
            else if (map[nx][ny] == '.')
                q.push({ {nx,ny},s });
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
            if (map[i][j] == '0') {
                q.push({ { i,j },0 });
                map[i][j] = '.';
                visited[i][j][0] = 1;
            }
        }
    }
    bfs();
    if (flag)
        cout << R-1;
    else
        cout << -1;
    return 0;
}