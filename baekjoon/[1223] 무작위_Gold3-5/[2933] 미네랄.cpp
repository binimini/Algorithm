#include <bits/stdc++.h>
using namespace std;
int R, C, N, cnt = 0;
int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool mineral[100][100] = { 0 };
bool ch[100][100] = { 0 };
int row_per_col[100];
void check() {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    bool flag = 0;
    for (int j = 0; j<C; j++)
        row_per_col[j] = -1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ch[i][j] = 0;
        }
    }
    int t_cnt = 0;
    for (int i = 0; i < R; i++) {
        if (flag) break;
        for (int j = 0; j < C; j++) {
            if (mineral[i][j]) {
                q.push(make_pair(i, j));
                flag = 1;
                ch[i][j] = 1;
                row_per_col[j] = i;
                v.push_back(make_pair(i, j));
                t_cnt = 1;
                break;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>R - 1 || ny>C - 1) continue;
            if (ch[nx][ny]) continue;
            if (mineral[nx][ny]) {
                t_cnt++;
                ch[nx][ny] = 1;
                v.push_back(make_pair(nx, ny));
                row_per_col[ny] = max(row_per_col[ny], nx);
                q.push(make_pair(nx, ny));
            }
        }
    }
    int m = 0;
    for (int i = 0; i < v.size(); i++) {
            m = max(v[i].first, m);
    }
    if (t_cnt == cnt) {
        if (m == R - 1)
            return;
        m = R - 1 - m;
        for (int i = R - 1; i >= 0; i--) {
            for (int j = 0; j < C; j++) {
                if (ch[i][j]) {
                    mineral[i + m][j] = mineral[i][j];
                    mineral[i][j] = 0;
                }
            }
        }
        return;
    }
    else {
        vector<pair<int, int>> nv;
        if (m == R - 1) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (mineral[i][j]) {
                        if (!ch[i][j] && i == R - 1)
                            return;
                        nv.push_back(make_pair(i, j));
                    }
                }
            }
            v.clear();
            while (!nv.empty()) {
                int nvx = nv.back().first;
                int nvy = nv.back().second;
                if (ch[nvx][nvy])
                    ch[nvx][nvy] = 0;
                else
                    v.push_back(make_pair(nvx, nvy));
                nv.pop_back();
            }
            for (int i = 0; i < v.size(); i++) {
                ch[v[i].first][v[i].second] = 1;
            }
        }
    }
    bool quit = 0;
    int down = 0;
    while (1) {
        down++;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].first + down >= R - 1 || (mineral[v[i].first + down+1][v[i].second]&&!ch[v[i].first+down+1][v[i].second])) {
                quit = 1;
                break;
            }
        }
        if (quit)
            break;
    }
    for (int i = R - 1; i >= 0; i--) {
        for (int j = 0; j < C; j++) {
            if (ch[i][j]) {
                mineral[i + down][j] = mineral[i][j];
                mineral[i][j] = 0;
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    char temp;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> temp;
            if (temp == 'x') {
                mineral[i][j] = 1;
                cnt++;
            }
        }
    }
    cin >> N;
    int row;
    for (int i = 0; i < N; i++) {
        cin >> row;
        row = R - row;
        if (i % 2 == 0) {
            for (int i = 0; i < C; i++) {
                if (mineral[row][i]) {
                    mineral[row][i] = 0;
                    cnt--;
                    break;
                }
            }
        }
        else {
            for (int i = C-1; i >=0; i--) {
                if (mineral[row][i]) {
                    mineral[row][i] = 0;
                    cnt--;
                    break;
                }
            }
        }
        check();
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mineral[i][j])
                cout << 'x';
            else
                cout << '.';
        }
        cout << '\n';
    }
    return 0;
}