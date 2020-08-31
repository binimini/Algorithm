#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, A[21][21], visited[21][21] = { 0 }, _max, _min, mini = 40000, d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
pair<int, int> p[400];
queue<pair<int, int>> q;
void count(int x, int y, int d1, int d2) {
    int arr[5] = { 0 };
    if (x + d1 + d2 > N || y + d2 > N || y - d1 < 1) return;
    for (int i = 0; i <= d1; i++) {
        visited[x + i][y - i] = 1;
        if (i != 0) q.push(make_pair(x + i, y - i));
        visited[x + d2 + i][y + d2 - i] = 1;
    }
    for (int i = 0; i <= d2; i++) {
        visited[x + i][y + i] = 1;
        visited[x + d1 + i][y - d1 + i] = 1;
        if (i != 0 && i != d2) q.push(make_pair(x + d1 + i, y - d1 + i));
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        while (1) {
            y++;
            if (visited[x][y] == 1) break;
            else visited[x][y] = 1;
        }
    }
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (visited[r][c]) { arr[4] += A[r][c]; visited[r][c] = 0; continue; }
            if (r < x + d1 && c <= y) arr[0] += A[r][c];
            else if (r <= x + d2 && c > y) arr[1] += A[r][c];
            else if (x + d1 <= r && c < y - d1 + d2) arr[2] += A[r][c];
            else arr[3] += A[r][c];
        }
    }
    _max = arr[0]; _min = arr[0];
    for (int i = 1; i < 5; i++) {
        _max = max(arr[i], _max);
        _min = min(arr[i], _min);
    }
    mini = min(mini, _max - _min);
}
void check_case(int x, int y) {
    for (int i = 0; i < N * N; i++) {
        int d1 = p[i].first;
        int d2 = p[i].second;
        count(x, y, d1, d2);
    }

}
int main() {
    cin >> N;
    int temp = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            p[temp] = make_pair(i, j);
            temp++;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            check_case(i, j);
        }
    }
    cout << mini << "\n";
    return 0;
}