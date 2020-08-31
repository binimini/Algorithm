#include <iostream>
#include <vector>
using namespace std;
int T, M, N, K, d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }, cnt = 0;
int map[50][50] = { 0 }, visited[50][50] = { 0 };
vector<int> cnt_arr;
void DFS(int x, int y) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if (map[nx][ny] == 0) continue;
        if (visited[nx][ny] == 1) continue;
        if (nx<0 || nx>M - 1 || ny<0 || ny>N - 1) continue;
        DFS(nx, ny);
    }
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        cnt = 0;
        for (int x = 0; x < M; x++) {
            for (int y = 0; y < N; y++) {
                map[x][y] = 0;
                visited[x][y] = 0;
            }
        }
        for (int i = 0; i < K; i++) {
            int m, n;
            cin >> m >> n;
            map[m][n] = 1;
        }
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (map[j][k] == 1 && visited[j][k] == 0) {
                    DFS(j, k);
                    cnt++;
                }
            }
        }
        cnt_arr.push_back(cnt);
    }
    for (int i = 0; i < cnt_arr.size(); i++) {
        cout << cnt_arr[i] << "\n";
    }
    return 0;
}