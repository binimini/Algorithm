#include <bits/stdc++.h>
using namespace std;
int N, M, s[3], e[3], d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int visited[101][101][4] = { 0 };
bool mapp[101][101];
queue<tuple<int, int, int>> q;
int bfs() {
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        if (x == e[0] && y == e[1] && z == e[2])
            return visited[x][y][z] - 1;
        if (visited[x][y][(z + 1) % 4] == 0) {
            visited[x][y][(z + 1) % 4] = visited[x][y][z] + 1;
            if (x == e[0] && y == e[1] && ((z + 1) % 4 )== e[2])
                return visited[x][y][(z + 1) % 4] - 1;
            q.push(make_tuple(x, y, (z + 1) % 4));
        }
        if (z != 0 && visited[x][y][z - 1] == 0) {
            visited[x][y][z-1] = visited[x][y][z] + 1;
            if (x == e[0] && y == e[1] && (z-1) == e[2])
                return visited[x][y][z-1] - 1;
            q.push(make_tuple(x, y, z - 1));
        }
        if (z == 0 && visited[x][y][3] == 0) {
            visited[x][y][3] = visited[x][y][z] + 1;
            if (x == e[0] && y == e[1] && 3 == e[2])
                return visited[x][y][3] - 1;
            q.push(make_tuple(x, y, 3));
        }
        for (int i = 1; i <= 3; i++) {
            int nx = x + d[z][0] * i;
            int ny = y + d[z][1] * i;
            if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
            if (mapp[nx][ny])
                break;
            if (visited[nx][ny][z]) continue;
            visited[nx][ny][z] = visited[x][y][z] + 1;
            if (nx == e[0] && ny == e[1] && z == e[2])
                return visited[nx][ny][z] - 1;
            q.push(make_tuple(nx, ny, z));
        }

    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> mapp[i][j];
        }
    }
    cin >> s[0] >> s[1] >> s[2];
    cin >> e[0] >> e[1] >> e[2];
    if (s[2] == 4)
        s[2] = 0;
    else if (s[2] == 3)
        s[2] = 2;
    else if (s[2] == 2)
        s[2] = 3;
    if (e[2] == 4)
        e[2] = 0;
    else if (e[2] == 3)
        e[2] = 2;
    else if (e[2] == 2)
        e[2] = 3;
    visited[s[0]][s[1]][s[2]] = 1;
    q.push(make_tuple(s[0], s[1], s[2]));
    cout <<bfs();
    return 0;
}