#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[100][100], visited[100][100] = { 0 }, d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }, arr_M = 0, M = 0;
void DFS(int x, int y, int key) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1) continue;
        if (visited[nx][ny] == 1 || arr[nx][ny] <= key) continue;
        DFS(nx, ny, key);
    }
}
int main() {
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
            arr_M = max(arr_M, temp);
        }
    }
    for (int x = 0; x < arr_M; x++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] == 1) continue;
                if (arr[i][j] <= x) continue;
                cnt++;
                DFS(i, j, x);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = 0;
            }
        }
        M = max(cnt, M);
    }
    cout << M << "\n";
    return 0;
}