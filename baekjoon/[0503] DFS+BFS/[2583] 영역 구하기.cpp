#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int M, N, K, map[100][100] = { 0 }, d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }, cnt = 0, G_cnt = 0;
vector<int> cnt_arr;
void DFS(int x, int y) {
    map[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int dx, dy;
        dx = x + d[i][0], dy = y + d[i][1];
        if (dx<0 || dx>M - 1 || dy<0 || dy>N - 1) continue;
        if (map[dx][dy] == 1) continue;
        cnt++;
        DFS(dx, dy);
    }

}
int main() {
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y, z, r;
        cin >> x >> y >> z >> r;
        for (int i = x; i < z; i++) {
            for (int j = y; j < r; j++) {
                map[j][i] = 1;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j]) continue;
            cnt = 1;
            DFS(i, j);
            cnt_arr.push_back(cnt);
            G_cnt++;
        }
    }
    sort(cnt_arr.begin(), cnt_arr.end());
    cout << G_cnt << '\n';
    for (int i = 0; i < G_cnt; i++) {
        cout << cnt_arr[i] << ' ';
    }
    return 0;
}