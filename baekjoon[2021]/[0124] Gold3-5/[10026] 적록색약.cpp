#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, cnt = 0, cnt_rg = 0;
char mapp[101][101];
bool visited[101][101] = { 0 };
queue<pair<int, int>> q;
void bfs(int x, int y) {
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1) continue;
            if (visited[nx][ny]) continue;
            if (mapp[x][y] != mapp[nx][ny]) continue;
            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
}
void count_group(int& cnt) {//pass by reference!! (value changes)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }
}
int main() {
    FASTIO;
    cin >> N;
    char temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            mapp[i][j] = temp;
        }
    }
    count_group(cnt);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
            if (mapp[i][j] == 'G')//green equals red
                mapp[i][j] = 'R';
        }
    }
    count_group(cnt_rg);
    cout << cnt << " " << cnt_rg << "\n";
    return 0;
}