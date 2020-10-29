#include <bits/stdc++.h>
using namespace std;
int R, C, d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
char lake[1500][1500];
int ice[1500][1500] = { 0 };
bool v[1500][1500] = { 0 };
vector<pair<int,int>> water;
pair<int, int> s, e;
queue<pair<int, int>> q;
queue < pair<int, int>> sw;
bool Swan(int k) {
    sw.push(s);
    v[s.first][s.second] = 1;
    while (!sw.empty()) {
        int x = sw.front().first;
        int y = sw.front().second;
        sw.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (lake[nx][ny] == 'X' && ice[nx][ny] > k + 1) {
                continue;
            }
            if (v[nx][ny]) continue;
            if (nx == e.first && ny == e.second) {
                while (!sw.empty()) {
                    sw.pop();
                }
                return true;
            }
            v[nx][ny] = 1;
            sw.push(make_pair(nx, ny));
        }
    }
    return false;
}
void Water() {
    while (!water.empty()) {
        int x = water.back().first;
        int y = water.back().second;
        water.pop_back();
        ice[x][y] = 1;
        bool flag = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (ice[nx][ny]) continue;
            if (lake[nx][ny] == 'X') {
                ice[nx][ny] = ice[x][y]+1;//첫 X 2
                q.push(make_pair(nx, ny));
            }
        }
    }
}
void bfs() {
    int cnt = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (ice[nx][ny]) continue;
            if (lake[nx][ny] == 'X') {
                ice[nx][ny] = ice[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    bool flag = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> lake[i][j];
            if (!flag && lake[i][j] == 'L') {
                s = { i,j };
                lake[i][j] = '.';
                flag = 1;
            }
            else if (flag && lake[i][j] == 'L') {
                e = { i,j };
                lake[i][j] = '.';
            }
            if (lake[i][j] == '.')
                water.push_back(make_pair(i, j));
        }
    }
    Water();
    bfs();
    int l = 0, r = 3000, m, cnt = 3000;
    while (r - l >= 0) {
        m = (r + l) / 2;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (v[i][j]) v[i][j] = 0;
            }
        }
        if (Swan(m)) {
            cnt = min(cnt, m);
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << cnt;
    return 0;
}