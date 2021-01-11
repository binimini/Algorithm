#include <bits/stdc++.h>
using namespace std;
int R, C, d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, res = 0;
char mapp[21][21];
bool alpha[26] = { 0 };
queue<pair<int, int>> q;
void dfs(int x, int y,int cnt) {//bfs 방문체크 못하기때문에 중복 발생 많다 -> case는 적어도 memory over 가능 => dfs??
    res = max(res, cnt);
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (nx<0 || nx>R - 1 || ny<0 || ny>C - 1) continue;
        if (alpha[mapp[nx][ny] - 'A']) continue;
        alpha[mapp[nx][ny] - 'A'] = 1;
        dfs(nx, ny, cnt+1);
        alpha[mapp[nx][ny] - 'A'] = 0;
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mapp[i][j];
        }
    }
    alpha[mapp[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << res;
    return 0;
}