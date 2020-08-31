#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int arr[100][100], visited[100][100] = { 0 }, d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }, N, M;
queue<pair<int, int>> q;
void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == N - 1 && y == M - 1)
            break;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) continue;
            if (visited[nx][ny]) continue;
            if (!arr[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++) {
            arr[i][j] = temp[j] - '0';
        }
    }
    visited[0][0] = 1;
    q.push(make_pair(0, 0));
    BFS();
    cout << visited[N - 1][M - 1] << "\n";
    return 0;
}