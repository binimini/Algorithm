#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, CNT = 1, R = 10001, d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int map[100][100];
int visited[100][100] = { 0 };
queue<pair<int,int>> q;
void grouping() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;
            if (!map[nx][ny]) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            map[nx][ny] = CNT;
            q.push(make_pair(nx, ny));
        }
    }
}
void bfs(int g) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (visited[x][y] >= R) {
            while (!q.empty())
                q.pop();
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] != 0) {
                R = min(visited[x][y], R);
                while (!q.empty())
                    q.pop();
                return;
            }
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
            
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] && !visited[i][j]) {
                CNT++;
                map[i][j] = CNT;
                visited[i][j] = 1;
                q.push({ i,j });
                grouping();
           }
        }
    }
    for (int i = 2; i <= CNT; i++) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (map[x][y] == i) {
                    visited[x][y] = 1;
                    q.push(make_pair(x, y));
                }
                else
                    visited[x][y] = 0;
            }
        }
        bfs(i);
    }
    cout << R-1 << "\n";
    return 0;
}