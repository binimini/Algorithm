#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
int N, M, R = 0, d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
char map[1001][1001];
int visited[1001][1001] = { 0 };
queue < tuple<int, int, bool >> q;
void bfs() {
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (map[nx][ny] == '#') continue;
            if (z) {
                if (nx<0 || nx>=N || ny<0 || ny>=M) {
                    R = visited[x][y] + 1;
                    return;
                }
                if (map[nx][ny] == 'F') continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = visited[x][y] + 1;
                q.push({ nx,ny,1 });
            }
            else {
                if (nx<0 || nx>=N || ny<0 || ny>=M) continue;
                if (map[nx][ny] == 'F') continue;
                map[nx][ny] = 'F';
                q.push({ nx,ny,0 });
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    tuple<int, int, int> start;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'J') {
                visited[i][j] = 1;
                map[i][j] = '.';
                start = { i,j,1 };
            }
            else if (map[i][j] == 'F')
                q.push({ i,j,0 });
        }
    }
    q.push(start);
    bfs();
    if (R)
        cout << R - 1;
    else
        cout << "IMPOSSIBLE";
    return 0;
}