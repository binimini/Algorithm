#include <bits/stdc++.h>
using namespace std;
int N, M, d[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int parent[1000000], cost[1000000] = { 0 };
int mapp[1000][1000];
queue<pair<int, int>> q;
queue<pair<int, int>> w;
int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (cost[x] > cost[y])
        parent[y] = x;
    else
        parent[x] = y;
}
void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
            if (cost[nx * M + ny]) continue;
            if (mapp[nx][ny]) continue;
            uni(x * M + y, nx * M + ny);
        }
    }
}

void check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!mapp[i][j]) {
                cost[find(i * M + j)]++;
            }
        }
    }
}
void plus_mapp() {
    while (!w.empty()) {
        int x = w.front().first;
        int y = w.front().second;
        w.pop();
        int c[4] = { -1,-1,-1,-1 };
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
            if (mapp[nx][ny] == 1) continue;
            c[i] = find(nx * M + ny);
        }
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (c[i] == c[j])
                    c[i] = -1;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (c[i] != -1)
                mapp[x][y] = (mapp[x][y] + cost[c[i]]) % 10;
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N * M; i++) {
        parent[i] = i;
    }
    char temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            mapp[i][j] = temp-'0';
            if (!mapp[i][j]) {
                q.push(make_pair(i, j));
            }
            else {
                w.push(make_pair(i, j));
            }
        }
    }
    BFS();
    check();
    plus_mapp();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mapp[i][j];
        }
        cout << '\n';
    }
    return 0;
}