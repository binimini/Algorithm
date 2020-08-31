#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int N, L, R, map[50][50][4] = { 0 }, visited[50][50] = { 0 }, A[50][50], cnt = 0, d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }, C = 0;
queue<pair<int, int>> q;
void check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 1 <= N - 1) {
                if (abs(A[i][j] - A[i + 1][j]) >= L && abs(A[i][j] - A[i + 1][j]) <= R)
                    map[i][j][2] = 1, map[i + 1][j][0] = 1, C = 1;
            }
            if (j + 1 <= N - 1) {
                if (abs(A[i][j] - A[i][j + 1]) >= L && abs(A[i][j] - A[i][j + 1]) <= R)
                    map[i][j][3] = 1, map[i][j + 1][1] = 1, C = 1;
            }
        }
    }
}
void BFS() {
    queue<pair<int, int>> uni;
    int area = 0, sum = 0, people;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        area++, sum += A[x][y];
        uni.push(make_pair(x, y));
        for (int i = 0; i < 4; i++) {
            if (!map[x][y][i]) continue;
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny]) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }
    people = sum / area;
    while (!uni.empty()) {
        A[uni.front().first][uni.front().second] = people;
        uni.pop();
    }

}
int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    while (1) {
        check();
        if (C == 0)
            break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j][0] == 1 || map[i][j][1] == 1 || map[i][j][2] == 1 || map[i][j][3] == 1) {
                    visited[i][j] = 1;
                    q.push(make_pair(i, j));
                    BFS();
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    map[i][j][k] = 0;
                }
            }
        }
        cnt++;
        C = 0;
    }
    cout << cnt << '\n';
    return 0;
}