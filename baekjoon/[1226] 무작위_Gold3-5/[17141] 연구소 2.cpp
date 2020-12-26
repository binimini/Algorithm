#include <bits/stdc++.h>
using namespace std;
#define FASTIO     std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, two_cnt = 0, result = 1000000, total = 0;
int mapp[50][50], visited[50][50], arr[10], d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
pair<int, int> info[10];
vector<pair<int, int>> v;
queue<pair<int, int>> q;
void bfs() {
    int cnt = 0, m = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
    while (!v.empty()) {
        visited[v.back().first][v.back().second] = 1;
        v.pop_back();
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;
            if (visited[nx][ny]) continue;
            if (mapp[nx][ny] == 1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            m = max(m, visited[nx][ny]);
            cnt++;
            q.push(make_pair(nx, ny));
        }
    }
    if (cnt == total)
        result = min(result, m-1);
}
void dfs(int node, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < cnt; i++) {
            q.push(info[arr[i]]);
            v.push_back(info[arr[i]]);
        }
        bfs();
        return;
    }
    for (int i = node; i < two_cnt; i++) {
        arr[cnt] = i;
        dfs(i + 1, cnt + 1);
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mapp[i][j];
            if (mapp[i][j] == 2) {
                info[two_cnt].first = i, info[two_cnt++].second = j;
                mapp[i][j] = 0;
            }
            else if (!mapp[i][j])
                total++;
        }
    }
    total += (two_cnt - M);
    dfs(0,0);
    if (result == 1000000)
        cout << -1;
    else
        cout << result;
    return 0;
}