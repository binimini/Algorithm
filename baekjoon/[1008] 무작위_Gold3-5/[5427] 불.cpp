#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int T, H, W, R = -1, d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
tuple<int, int, bool> start = { 0,0,1 };
char map[1001][1001];
int visited[1000][1000] = { 0 };
queue<tuple<int, int, int>> q;
void bfs() {
    while (!q.empty()) {
        bool flag = get<2>(q.front());
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>H - 1 || ny<0 || ny>W - 1) {
                if (flag) {
                    R = visited[x][y];
                    while (!q.empty())
                        q.pop();
                    return;
                }
                else
                    continue;
            }
            if (map[nx][ny] == '#') continue;
            if (flag) {//사람
                if (map[nx][ny] == '*') continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = visited[x][y] + 1;
                q.push(make_tuple(nx, ny, 1));
            }
            else {
                if (map[nx][ny] == '*') continue;
                map[nx][ny] = '*';
                q.push(make_tuple(nx, ny, 0));
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        R = -1;
        cin >> W >> H;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> map[i][j];
                visited[i][j] = 0;
                if (map[i][j] == '@') {
                    get<0>(start) = i, get<1>(start) = j;
                    map[i][j] = '.';
                    visited[i][j] = 1;
                }
                else if (map[i][j] == '*')
                    q.push(make_tuple(i, j,0));
            }
        }
        q.push(start);
        bfs();
        if (R != -1)
            cout << R << "\n";
        else
            cout << "IMPOSSIBLE\n";
    }
    return 0;
}