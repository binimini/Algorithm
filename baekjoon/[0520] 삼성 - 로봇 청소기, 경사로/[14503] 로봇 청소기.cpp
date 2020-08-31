#include <iostream>
#include <queue>
using namespace std;
int N, M, X, Y, D, map[50][50] = { 0 }, visited[50][50] = { 0 }, d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }, cnt = 1;
queue<pair<int, int>> q;
void move(int fail) {
    while (1) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (fail == 4) {
            int temp;
            if (D >= 2)
                temp = D - 2;
            else
                temp = D + 2;
            int dx = x + d[temp][0];
            int dy = y + d[temp][1];
            if (map[dx][dy])
                break;
            else {
                x += d[temp][0], y += d[temp][1];
                q.push(make_pair(x, y));
                fail = 0;
                continue;
            }
        }
        if (D == 0)
            D = 3;
        else
            D--;
        int nx = x + d[D][0];
        int ny = y + d[D][1];
        if (map[nx][ny] || visited[nx][ny]) {
            fail++;
            q.push(make_pair(x, y));
            continue;
        }
        visited[nx][ny] = 1;
        cnt++;
        q.push(make_pair(nx, ny));
        fail = 0;
    }
}
int main() {
    cin >> N >> M;
    cin >> X >> Y >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    visited[X][Y] = 1;
    q.push(make_pair(X, Y));
    move(0);
    cout << cnt << '\n';
    return 0;
}