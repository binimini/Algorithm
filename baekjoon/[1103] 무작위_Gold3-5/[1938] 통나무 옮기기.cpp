#include <bits/stdc++.h>
using namespace std;
int N, d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool mapp[50][50] = { 0 };
int visited[50][50][2] = { 0 };
bool flag1 = 1, flag2 = 1;
queue<tuple<int, int, int>> q;
vector<pair<int, int>> s, e;
bool check(int i, int j, bool status, bool rotate) {
    if (rotate) {
        int x = i - 1;
        int y = j - 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int nx = x + i;
                int ny = y + j;
                if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) return false;
                if (mapp[nx][ny]) return false;
            }
        }
        return true;
    }
    else {
        if (status) {
            if (i< 0 || i > N - 1 || j<0 || j>N - 1||j-1<0||j-1>N-1||j+1<0||j+1>N-1)
                return false;
            if (mapp[i][j-1] || mapp[i][j] || mapp[i][j + 1])
                return false;
            return true;
        }
        else {
            if (j< 0 || j > N - 1 || i<0 || i>N - 1 || i - 1 < 0 || i - 1 > N - 1 || i + 1 < 0 || i + 1 > N - 1)
                return false;
            if (mapp[i-1][j] || mapp[i][j] || mapp[i+1][j])
                return false;
            return true;
        }
    }
}
void bfs() {
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 5; i++) {
            int nx = x, ny = y, nz = z;
            if (i == 4)
                nz = !z;
            else {
                nx = x + d[i][0];
                ny = y + d[i][1];
            }
            if (nx == e[1].first && ny == e[1].second && nz == flag2) {
                visited[nx][ny][nz] = visited[x][y][z] + 1;
                return;
            }
            if (!check(nx, ny, nz, (i == 4))) continue;
            if (visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push(make_tuple(nx, ny, nz));
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    char temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (temp == 'B')
                s.push_back({ i,j });
            else if (temp == 'E')
                e.push_back({ i,j });
            else if (temp == '1')
                mapp[i][j] = 1;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (s[i].first != s[i + 1].first)
            flag1 = 0;
        if (e[i].first != e[i + 1].first)
            flag2 = 0;
    }
    visited[s[1].first][s[1].second][flag1] = 1;
    q.push({ s[1].first,s[1].second,flag1 });
    bfs();
    if (!visited[e[1].first][e[1].second][flag2])
        cout << "0";
    else
        cout << visited[e[1].first][e[1].second][flag2] - 1;
    return 0;
}