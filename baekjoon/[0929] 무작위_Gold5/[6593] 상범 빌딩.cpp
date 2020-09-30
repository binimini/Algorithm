#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
int L, R, C, d[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
char map[30][30][30];
int visited[30][30][30] = { 0 };
queue<tuple<int, int, int>> q;
void BFS() {
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        FOR(i, 0, 6) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            int nz = z + d[i][2];
            if (nx<0 || nx>L - 1 || ny<0 || ny>R - 1 || nz<0 || nz>C - 1) continue;
            if (map[nx][ny][nz] == '#') continue;
            if (visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            if (map[nx][ny][nz] == 'E') return;
            q.push(make_tuple(nx, ny, nz));
        }
    }
}
int main() {
    while (1) {
        cin >> L >> R >> C;
        if (!L && !R && !C)
            break;
        tuple<int, int, int> exit;
        FOR(l, 0, L) {
            FOR(r, 0, R) {
                FOR(c, 0, C) {
                    visited[l][r][c] = 0;
                    cin >> map[l][r][c];
                    if (map[l][r][c] == 'S') {
                        q.push(make_tuple(l, r, c));
                        visited[l][r][c];
                    }
                    else if (map[l][r][c] == 'E')
                        exit = { l,r,c };
                }
            }
        }
        BFS();
        int result = visited[get<0>(exit)][get<1>(exit)][get<2>(exit)];
        if (result != 0)
            cout << "Escaped in " << result << " minute(s).\n";
        else
            cout << "Trapped!\n";
        while (!q.empty())
            q.pop();
        
    }
    return 0;
}