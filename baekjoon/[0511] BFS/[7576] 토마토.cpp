#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int M, N, cnt0 = 0, cnt1, visited[1000][1000] = { 0 }, arr[1000][1000] = { 0 }, d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
queue<pair<int, int>> q;
void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) continue;
            if (visited[nx][ny]) continue;
            if (!arr[nx][ny]) {
                cnt0--;
                visited[nx][ny] = visited[x][y] + 1;
                cnt1 = visited[nx][ny];
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int main() {
    cin.tie(NULL);
    cin >> M >> N;
    pair<int, int> s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
            if (!arr[i][j])
                cnt0++;
        }
    }
    BFS();
    if (cnt0)
        cout << -1 << "\n";
    else if (!cnt1)
        cout << 0 << "\n";
    else
        cout << cnt1 - 1 << "\n";
    return 0;
}