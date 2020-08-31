#include <iostream>
using namespace std;
int R, C, cnt = 0, ch = 0, arr[10000][500], visited[10000][500] = { 0 }, d[3][2] = { {-1,1},{0,1}, {1,1} };
void DFS(int x, int y) {
    if (y == C - 1) {
        cnt++;
        ch = 1;
        return;
    }
    for (int i = 0; i < 3; i++) {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (nx<0 || ny<0 || nx>R - 1 || ny>C - 1) continue;
        if (visited[nx][ny]) continue;
        if (arr[nx][ny] == -1) continue;
        visited[nx][ny] = 1;
        DFS(nx, ny);
        if (ch == 1)
            return;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    char temp;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> temp;
            if (temp == '.')
                arr[i][j] = 0;
            else if (temp == 'x')
                arr[i][j] = -1;
        }
    }
    for (int i = 0; i < R; i++) {
        ch = 0;
        DFS(i, 0);
    }
    cout << cnt;
    return 0;
}