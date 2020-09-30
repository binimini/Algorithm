#include <iostream>
#include <queue>
using namespace std;
int N, M, cnt = 0;
int map[300][300] = { 0 }, d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool visited[300][300] = { 0 };
queue<pair<int,int>> q;
vector<pair<pair<int,int>,int>> next_q;
int bfs() {
    int progress = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        progress++;
        int sea = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
            if (!map[nx][ny]) sea++;
            if (visited[nx][ny]) continue;
            else if (map[nx][ny]&&!visited[nx][ny]) {
                visited[nx][ny] = 1;
                q.push(make_pair(nx,ny));
            }
        }
        next_q.push_back(make_pair(make_pair(x, y), map[x][y]-sea));
    }
    return progress;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    bool first = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0){
                if (first) {
                    visited[i][j] = 1;
                    q.push(make_pair(i, j));
                    first = 0;
                }
                cnt++;
            }
        }
    }
    int pro, year = 0;
    bool flag = 1;
    while (1) {
        year++;
        pro = bfs();
        if (cnt != pro) {
            flag = 0;
            break;
        }
        if (cnt == 0)
            break;
        bool firstflag = 1;
        while (!next_q.empty()) {
            int x = next_q.back().first.first;
            int y = next_q.back().first.second;
            int v = next_q.back().second;
            if (v <= 0) {
                cnt--;
                map[x][y] = 0;
            }
            else {
                map[x][y] = v;
                visited[x][y] = 0;
                if (firstflag) {
                    visited[x][y] = 1;
                    q.push(make_pair(x, y));
                    firstflag = 0;
                }
            }
            next_q.pop_back();
        }

    }
    if (flag)
        cout << 0;
    else
        cout << year-1;
    return 0;
}