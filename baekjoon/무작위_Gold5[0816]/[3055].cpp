#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int R, C, CH = 0;
int map[50][50] = { 0 }, visited[50][50] = { 0 }, d[4][2] = { { -1,0 },{1,0},{0,-1},{0,1} };
tuple<int, int, int> start;
queue<tuple<int, int, int>> q;
void BFS() {
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (z == 1) {//고슴도치
                if (nx<0 || nx>R - 1 || ny<0 || ny>C - 1) continue;
                if (map[nx][ny] == -1) continue;
                if (visited[nx][ny]) continue;
                visited[nx][ny] = visited[x][y] + 1;
                if (map[nx][ny] == 1) {
                    CH = 1;
                    cout << visited[nx][ny] - 1;
                    return;
                }
                q.push(make_tuple(nx, ny, 1));
            }
            else if (z == -1) {//물
                if (nx<0 || nx>R - 1 || ny<0 || ny>C - 1) continue;
                if (map[nx][ny]) continue;
                map[nx][ny] = -1;
                q.push(make_tuple(nx, ny, -1));
                

            }
        }
    }
    if (CH == 0)
        cout << "KAKTUS";
}
int main() {//탈출
    cin >> R >> C;
    char temp;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> temp;
            if (temp == 'S')
                start = make_tuple(i, j, 1);
            else if (temp == '*')
                q.push(make_tuple(i, j,-1));
            else if (temp == 'D')
                map[i][j] = 1;
            else if (temp == 'X')
                map[i][j] = -1;
        }
    }
    q.push(start);
    visited[get<0>(start)][get<1>(start)] = 1;
    BFS();
    return 0;
}